QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AceCompress.cpp \
    main.cpp \
    mainwindow.cpp \
    zstd/common/debug.c \
    zstd/common/entropy_common.c \
    zstd/common/error_private.c \
    zstd/common/fse_decompress.c \
    zstd/common/pool.c \
    zstd/common/threading.c \
    zstd/common/xxhash.c \
    zstd/common/zstd_common.c \
    zstd/compress/fse_compress.c \
    zstd/compress/hist.c \
    zstd/compress/huf_compress.c \
    zstd/compress/zstd_compress.c \
    zstd/compress/zstd_compress_literals.c \
    zstd/compress/zstd_compress_sequences.c \
    zstd/compress/zstd_compress_superblock.c \
    zstd/compress/zstd_double_fast.c \
    zstd/compress/zstd_fast.c \
    zstd/compress/zstd_lazy.c \
    zstd/compress/zstd_ldm.c \
    zstd/compress/zstd_opt.c \
    zstd/compress/zstdmt_compress.c \
    zstd/decompress/huf_decompress.c \
    zstd/decompress/zstd_ddict.c \
    zstd/decompress/zstd_decompress.c \
    zstd/decompress/zstd_decompress_block.c

HEADERS += \
    AceCompress.h \
    mainwindow.h \
    zstd/common/bitstream.h \
    zstd/common/compiler.h \
    zstd/common/cpu.h \
    zstd/common/debug.h \
    zstd/common/error_private.h \
    zstd/common/fse.h \
    zstd/common/huf.h \
    zstd/common/mem.h \
    zstd/common/pool.h \
    zstd/common/portability_macros.h \
    zstd/common/threading.h \
    zstd/common/xxhash.h \
    zstd/common/zstd_deps.h \
    zstd/common/zstd_internal.h \
    zstd/common/zstd_trace.h \
    zstd/compress/clevels.h \
    zstd/compress/hist.h \
    zstd/compress/zstd_compress_internal.h \
    zstd/compress/zstd_compress_literals.h \
    zstd/compress/zstd_compress_sequences.h \
    zstd/compress/zstd_compress_superblock.h \
    zstd/compress/zstd_cwksp.h \
    zstd/compress/zstd_double_fast.h \
    zstd/compress/zstd_fast.h \
    zstd/compress/zstd_lazy.h \
    zstd/compress/zstd_ldm.h \
    zstd/compress/zstd_ldm_geartab.h \
    zstd/compress/zstd_opt.h \
    zstd/compress/zstdmt_compress.h \
    zstd/decompress/huf_decompress_amd64.S \
    zstd/decompress/zstd_ddict.h \
    zstd/decompress/zstd_decompress_block.h \
    zstd/decompress/zstd_decompress_internal.h \
    zstd/zdict.h \
    zstd/zstd.h \
    zstd/zstd_errors.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    zstd/zstd.pro

DISTFILES += \
    zstd/VERSION.txt \
    zstd/zstd.pri
