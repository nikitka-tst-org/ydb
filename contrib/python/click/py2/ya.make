# Generated by devtools/yamaker (pypi).

PY2_LIBRARY()

VERSION(7.1.2)

LICENSE(BSD-3-Clause)

PEERDIR(
    contrib/python/colorama
    library/python/symbols/python
)

NO_LINT()

NO_CHECK_IMPORTS(
    click._winconsole
)

PY_SRCS(
    TOP_LEVEL
    click/__init__.py
    click/_bashcomplete.py
    click/_compat.py
    click/_termui_impl.py
    click/_textwrap.py
    click/_unicodefun.py
    click/_winconsole.py
    click/core.py
    click/decorators.py
    click/exceptions.py
    click/formatting.py
    click/globals.py
    click/parser.py
    click/termui.py
    click/testing.py
    click/types.py
    click/utils.py
)

RESOURCE_FILES(
    PREFIX contrib/python/click/py2/
    .dist-info/METADATA
    .dist-info/top_level.txt
)

END()

RECURSE_FOR_TESTS(
    tests
)
