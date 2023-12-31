# Generated by devtools/yamaker from nixpkgs 22.05.

LIBRARY()

LICENSE(BSD-3-Clause)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

VERSION(6.4.5)

ORIGINAL_SOURCE(https://github.com/jtv/libpqxx/archive/6.4.5.tar.gz)

PEERDIR(
    contrib/libs/libpq
)

ADDINCL(
    GLOBAL contrib/libs/libpqxx/include
    contrib/libs/libpq
    contrib/libs/libpq/src/interfaces/libpq
)

NO_COMPILER_WARNINGS()

NO_UTIL()

CFLAGS(
    -DHAVE_CONFIG_H
)

SRCS(
    src/array.cxx
    src/binarystring.cxx
    src/connection.cxx
    src/connection_base.cxx
    src/cursor.cxx
    src/dbtransaction.cxx
    src/encodings.cxx
    src/errorhandler.cxx
    src/except.cxx
    src/field.cxx
    src/largeobject.cxx
    src/nontransaction.cxx
    src/notification.cxx
    src/pipeline.cxx
    src/prepared_statement.cxx
    src/result.cxx
    src/robusttransaction.cxx
    src/row.cxx
    src/sql_cursor.cxx
    src/statement_parameters.cxx
    src/strconv.cxx
    src/stream_base.cxx
    src/stream_from.cxx
    src/stream_to.cxx
    src/subtransaction.cxx
    src/tablereader.cxx
    src/tablestream.cxx
    src/tablewriter.cxx
    src/transaction.cxx
    src/transaction_base.cxx
    src/util.cxx
    src/version.cxx
)

END()
