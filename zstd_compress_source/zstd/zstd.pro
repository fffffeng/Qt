TEMPLATE = lib
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11 staticlib
DEFINES += ZSTD_MULTITHREAD

unix {
    QMAKE_CXXFLAGS += -pthread
    QMAKE_CFLAGS += -pthread
}

HEADERS += \
    common/bitstream.h \
    compress/clevels.h \
    common/compiler.h \
    common/cpu.h \
    common/debug.h \
    common/error_private.h \
    common/fse.h \
    compress/hist.h \
    common/huf.h \
    common/mem.h \
    common/pool.h \
    common/portability_macros.h \
    common/threading.h \
    common/xxhash.h \
    zdict.h \
    zstd.h \
    compress/zstd_compress_internal.h \
    compress/zstd_compress_literals.h \
    compress/zstd_compress_sequences.h \
    compress/zstd_compress_superblock.h \
    compress/zstd_cwksp.h \
    decompress/zstd_ddict.h \
    decompress/zstd_decompress_block.h \
    decompress/zstd_decompress_internal.h \
    common/zstd_deps.h \
    compress/zstd_double_fast.h \
    zstd_errors.h \
    compress/zstd_fast.h \
    common/zstd_internal.h \
    compress/zstd_lazy.h \
    compress/zstd_ldm.h \
    compress/zstd_ldm_geartab.h \
    compress/zstd_opt.h \
    common/zstd_trace.h \
    compress/zstdmt_compress.h

SOURCES += \
    common/debug.c \
    common/entropy_common.c \
    common/error_private.c \
    compress/fse_compress.c \
    common/fse_decompress.c \
    compress/hist.c \
    compress/huf_compress.c \
    decompress/huf_decompress.c \
    common/pool.c \
    common/threading.c \
    common/xxhash.c \
    common/zstd_common.c \
    compress/zstd_compress.c \
    compress/zstd_compress_literals.c \
    compress/zstd_compress_sequences.c \
    compress/zstd_compress_superblock.c \
    decompress/zstd_ddict.c \
    decompress/zstd_decompress.c \
    decompress/zstd_decompress_block.c \
    compress/zstd_double_fast.c \
    compress/zstd_fast.c \
    compress/zstd_lazy.c \
    compress/zstd_ldm.c \
    compress/zstd_opt.c \
    compress/zstdmt_compress.c