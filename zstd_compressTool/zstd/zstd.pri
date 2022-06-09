DEFINES += ZSTD_MULTITHREAD

unix {
    QMAKE_CXXFLAGS += -pthread
    QMAKE_CFLAGS += -pthread
}

HEADERS += \
    $$PWD/common/bitstream.h \
    $$PWD/compress/clevels.h \
    $$PWD/common/compiler.h \
    $$PWD/common/cpu.h \
    $$PWD/common/debug.h \
    $$PWD/common/error_private.h \
    $$PWD/common/fse.h \
    $$PWD/compress/hist.h \
    $$PWD/common/huf.h \
    $$PWD/common/mem.h \
    $$PWD/common/pool.h \
    $$PWD/common/portability_macros.h \
    $$PWD/common/threading.h \
    $$PWD/common/xxhash.h \
    $$PWD/zdict.h \
    $$PWD/zstd.h \
    $$PWD/compress/zstd_compress_internal.h \
    $$PWD/compress/zstd_compress_literals.h \
    $$PWD/compress/zstd_compress_sequences.h \
    $$PWD/compress/zstd_compress_superblock.h \
    $$PWD/compress/zstd_cwksp.h \
    $$PWD/decompress/zstd_ddict.h \
    $$PWD/decompress/zstd_decompress_block.h \
    $$PWD/decompress/zstd_decompress_internal.h \
    $$PWD/common/zstd_deps.h \
    $$PWD/compress/zstd_double_fast.h \
    $$PWD/zstd_errors.h \
    $$PWD/compress/zstd_fast.h \
    $$PWD/common/zstd_internal.h \
    $$PWD/compress/zstd_lazy.h \
    $$PWD/compress/zstd_ldm.h \
    $$PWD/compress/zstd_ldm_geartab.h \
    $$PWD/compress/zstd_opt.h \
    $$PWD/common/zstd_trace.h \
    $$PWD/compress/zstdmt_compress.h

SOURCES += \
    $$PWD/common/debug.c \
    $$PWD/common/entropy_common.c \
    $$PWD/common/error_private.c \
    $$PWD/compress/fse_compress.c \
    $$PWD/common/fse_decompress.c \
    $$PWD/compress/hist.c \
    $$PWD/compress/huf_compress.c \
    $$PWD/decompress/huf_decompress.c \
    $$PWD/common/pool.c \
    $$PWD/common/threading.c \
    $$PWD/common/xxhash.c \
    $$PWD/common/zstd_common.c \
    $$PWD/compress/zstd_compress.c \
    $$PWD/compress/zstd_compress_literals.c \
    $$PWD/compress/zstd_compress_sequences.c \
    $$PWD/compress/zstd_compress_superblock.c \
    $$PWD/decompress/zstd_ddict.c \
    $$PWD/decompress/zstd_decompress.c \
    $$PWD/decompress/zstd_decompress_block.c \
    $$PWD/compress/zstd_double_fast.c \
    $$PWD/compress/zstd_fast.c \
    $$PWD/compress/zstd_lazy.c \
    $$PWD/compress/zstd_ldm.c \
    $$PWD/compress/zstd_opt.c \
    $$PWD/compress/zstdmt_compress.c