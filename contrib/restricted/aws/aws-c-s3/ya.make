# Generated by devtools/yamaker from nixpkgs 23.05.

LIBRARY()

LICENSE(Apache-2.0)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

VERSION(0.2.8)

ORIGINAL_SOURCE(https://github.com/awslabs/aws-c-s3/archive/v0.2.8.tar.gz)

PEERDIR(
    contrib/restricted/aws/aws-c-auth
    contrib/restricted/aws/aws-c-cal
    contrib/restricted/aws/aws-c-common
    contrib/restricted/aws/aws-c-http
    contrib/restricted/aws/aws-c-io
    contrib/restricted/aws/aws-c-sdkutils
    contrib/restricted/aws/aws-checksums
)

ADDINCL(
    GLOBAL contrib/restricted/aws/aws-c-s3/include
)

NO_COMPILER_WARNINGS()

NO_RUNTIME()

CFLAGS(
    -DAWS_AUTH_USE_IMPORT_EXPORT
    -DAWS_CAL_USE_IMPORT_EXPORT
    -DAWS_CHECKSUMS_USE_IMPORT_EXPORT
    -DAWS_COMMON_USE_IMPORT_EXPORT
    -DAWS_COMPRESSION_USE_IMPORT_EXPORT
    -DAWS_HTTP_USE_IMPORT_EXPORT
    -DAWS_IO_USE_IMPORT_EXPORT
    -DAWS_S3_USE_IMPORT_EXPORT
    -DAWS_SDKUTILS_USE_IMPORT_EXPORT
    -DAWS_USE_EPOLL
    -DCJSON_HIDE_SYMBOLS
    -DHAVE_SYSCONF
    -DS2N_CLONE_SUPPORTED
    -DS2N_CPUID_AVAILABLE
    -DS2N_FALL_THROUGH_SUPPORTED
    -DS2N_FEATURES_AVAILABLE
    -DS2N_KYBER512R3_AVX2_BMI2
    -DS2N_LIBCRYPTO_SUPPORTS_EVP_MD5_SHA1_HASH
    -DS2N_LIBCRYPTO_SUPPORTS_EVP_MD_CTX_SET_PKEY_CTX
    -DS2N_LIBCRYPTO_SUPPORTS_EVP_RC4
    -DS2N_MADVISE_SUPPORTED
    -DS2N_PLATFORM_SUPPORTS_KTLS
    -DS2N_STACKTRACE
    -DS2N___RESTRICT__SUPPORTED
)

SRCS(
    source/s3.c
    source/s3_auto_ranged_get.c
    source/s3_auto_ranged_put.c
    source/s3_checksum_stream.c
    source/s3_checksums.c
    source/s3_chunk_stream.c
    source/s3_client.c
    source/s3_copy_object.c
    source/s3_default_meta_request.c
    source/s3_endpoint.c
    source/s3_list_objects.c
    source/s3_list_parts.c
    source/s3_meta_request.c
    source/s3_paginator.c
    source/s3_request.c
    source/s3_request_messages.c
    source/s3_util.c
)

END()
