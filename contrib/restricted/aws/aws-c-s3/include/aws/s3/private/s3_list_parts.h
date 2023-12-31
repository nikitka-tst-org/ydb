#ifndef AWS_S3_LIST_PARTS_H
#define AWS_S3_LIST_PARTS_H

/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/s3/private/s3_paginator.h>
#include <aws/s3/s3_client.h>

#include <aws/common/date_time.h>
#include <aws/common/string.h>

/** Struct representing part info as returned from ListParts call. */
struct aws_s3_part_info {
    /**
     * Size of the object in bytes.
     */
    uint64_t size;
    /**
     * Part number of the given part.
     */
    uint32_t part_number;
    /**
     * Timestamp from S3 on the latest modification, if you have a reliable clock on your machine, you COULD use this
     * to implement caching.
     */
    struct aws_date_time last_modified;
    /**
     * Etag for the object, usually an MD5 hash. you COULD also use this to implement caching.
     */
    struct aws_byte_cursor e_tag;

    /**
     * CRC32 checksum for the part. Optional.
     */
    struct aws_byte_cursor checksumCRC32;

    /**
     * CRC32C checksum for the part. Optional.
     */
    struct aws_byte_cursor checksumCRC32C;

    /**
     * SHA1 checksum for the part. Optional.
     */
    struct aws_byte_cursor checksumSHA1;

    /**
     * SHA256 checksum for the part. Optional.
     */
    struct aws_byte_cursor checksumSHA256;
};

/**
 * Invoked when a part is encountered during ListParts call. Return false, to immediately
 * terminate the list operation. Returning true will continue until at least the current page is iterated.
 */
typedef bool(aws_s3_on_part_fn)(const struct aws_s3_part_info *info, void *user_data);

/**
 * Parameters for calling aws_s3_initiate_list_parts(). All values are copied out or re-seated and reference counted.
 */
struct aws_s3_list_parts_params {
    /**
     * Must not be NULL. The internal call will increment the reference count on client.
     */
    struct aws_s3_client *client;
    /**
     * Must not be empty. Name of the bucket to list.
     */
    struct aws_byte_cursor bucket_name;
    /**
     * Must not be empty. Key with which multipart upload was initiated.
     */
    struct aws_byte_cursor key;
    /**
     * Must not be empty. Id identifying multipart upload.
     */
    struct aws_byte_cursor upload_id;
    /**
     * Must not be empty. The endpoint for the S3 bucket to hit. Can be virtual or path style.
     */
    struct aws_byte_cursor endpoint;
    /**
     * Callback to invoke on each part that's listed.
     */
    aws_s3_on_part_fn *on_part;
    /**
     * Callback to invoke when each page of the bucket listing completes.
     */
    aws_s3_on_page_finished_fn *on_list_finished;
    /**
     * Associated user data.
     */
    void *user_data;
};

AWS_EXTERN_C_BEGIN

/**
 * Initiates a list objects command (without executing it), and returns a paginator object to iterate the bucket with if
 * successful.
 *
 * Returns NULL on failure. Check aws_last_error() for details on the error that occurred.
 *
 * this is a reference counted object. It is returned with a reference count of 1. You must call
 * aws_s3_paginator_release() on this object when you are finished with it.
 *
 * This does not start the actual list operation. You need to call aws_s3_paginator_continue() to start
 * the operation.
 */
AWS_S3_API struct aws_s3_paginator *aws_s3_initiate_list_parts(
    struct aws_allocator *allocator,
    const struct aws_s3_list_parts_params *params);

AWS_S3_API struct aws_s3_paginated_operation *aws_s3_list_parts_operation_new(
    struct aws_allocator *allocator,
    const struct aws_s3_list_parts_params *params);

AWS_EXTERN_C_END

#endif /* AWS_S3_LIST_PARTS_H */
