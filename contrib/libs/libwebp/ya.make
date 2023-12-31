# Generated by devtools/yamaker from nixpkgs 22.05.

LIBRARY()

VERSION(1.2.2)

ORIGINAL_SOURCE(https://github.com/webmproject/libwebp/archive/v1.2.2.tar.gz)

LICENSE(BSD-3-Clause WITH Google-Patent-License-Webm)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

PEERDIR(
    contrib/libs/libwebp/dec
    contrib/libs/libwebp/dsp/webpdsp
    contrib/libs/libwebp/enc
    contrib/libs/libwebp/utils/webputils
)

NO_COMPILER_WARNINGS()

NO_RUNTIME()

END()

RECURSE(
    dec
    demux
    dsp/webpdsp
    dsp/webpdsp_mips32
    dsp/webpdsp_mips_dsp_r2
    dsp/webpdsp_msa
    dsp/webpdsp_neon
    dsp/webpdsp_sse2
    dsp/webpdsp_sse41
    dsp/webpdspdecode
    dsp/webpdspdecode_mips32
    dsp/webpdspdecode_mips_dsp_r2
    dsp/webpdspdecode_msa
    dsp/webpdspdecode_neon
    dsp/webpdspdecode_sse2
    dsp/webpdspdecode_sse41
    enc
    mux
    utils/webputils
    utils/webputilsdecode
    webpdecoder
)
