# Generated by devtools/yamaker (pypi).

PY2_LIBRARY()

VERSION(0.59.0)

LICENSE(LGPL-2.1-or-later)

PEERDIR(
    contrib/python/six
)

NO_LINT()

PY_SRCS(
    TOP_LEVEL
    websocket/__init__.py
    websocket/_abnf.py
    websocket/_app.py
    websocket/_cookiejar.py
    websocket/_core.py
    websocket/_exceptions.py
    websocket/_handshake.py
    websocket/_http.py
    websocket/_logging.py
    websocket/_socket.py
    websocket/_ssl_compat.py
    websocket/_url.py
    websocket/_utils.py
)

RESOURCE_FILES(
    PREFIX contrib/python/websocket-client/py2/
    .dist-info/METADATA
    .dist-info/top_level.txt
)

END()

RECURSE_FOR_TESTS(
    tests
)
