#include "AceCompress.h"
#include "zstd/zstd.h"
#include "zstd/zstd_errors.h"
#include <QScopedArrayPointer>
#include <QtDebug>
#include <QFile>

static ZSTD_CCtx* AceLogCCtx = nullptr;
static ZSTD_DCtx* AceLogDCtx = nullptr;

QByteArray AceCompress::zstdCompress(const QByteArray& content, ZStdDictType dictType)
{
    QByteArray compressed;
    if (dictType == AceLog) {
        if (!AceLogCCtx) {
            QFile dictFile(":/res/dict/ace_studio_log_zstd_dict_v1");
            if (!dictFile.open(QFile::ReadOnly)) {
                return {};
            }
            auto dict = dictFile.readAll();
            AceLogCCtx = ZSTD_createCCtx();
            ZSTD_CCtx_loadDictionary(AceLogCCtx, dict.data(), dict.size());
        }
        auto bufferSize = ZSTD_compressBound(content.size());
        QScopedArrayPointer<char> buffer(new char[bufferSize]);
        auto zstdCode = ZSTD_compressCCtx(AceLogCCtx, buffer.get(), bufferSize, content.data(), content.size(), ZSTD_defaultCLevel());
        if (ZSTD_isError(zstdCode))
        {
            qWarning() << "[AceCompress] " << QStringLiteral("Can not compress with zstd. code= %1, errorString= %2")
                          .arg(ZSTD_getErrorCode(zstdCode))
                          .arg(ZSTD_getErrorString(ZSTD_getErrorCode(zstdCode)));
            return {};
        }
        compressed = QByteArray(buffer.data(), zstdCode);
    }
    else { //None
        auto bufferSize = ZSTD_compressBound(content.size());
        QScopedArrayPointer<char> buffer(new char[bufferSize]);
        auto zstdCode = ZSTD_compress(buffer.get(), bufferSize, content.data(), content.size(), ZSTD_defaultCLevel());
        if (ZSTD_isError(zstdCode))
        {
            qWarning() << "[AceCompress] " << QStringLiteral("Can not compress with zstd. code= %1, errorString= %2")
                          .arg(ZSTD_getErrorCode(zstdCode))
                          .arg(ZSTD_getErrorString(ZSTD_getErrorCode(zstdCode)));
            return {};
        }
        compressed = QByteArray(buffer.data(), zstdCode);
    }

    return compressed;
}

QByteArray AceCompress::zstdDecompress(const QByteArray& content, ZStdDictType dictType)
{
    QByteArray decompressed;
    if (dictType == AceLog) {
        if (!AceLogDCtx) {
            QFile dictFile(":/res/dict/ace_studio_log_zstd_dict_v1");
            if (!dictFile.open(QFile::ReadOnly)) {
                return {};
            }
            auto dict = dictFile.readAll();
            AceLogDCtx = ZSTD_createDCtx();
            ZSTD_DCtx_loadDictionary(AceLogDCtx, dict.data(), dict.size());
        }

        auto bufferSize = ZSTD_getFrameContentSize(content.data(), content.size());
        if (bufferSize == ZSTD_CONTENTSIZE_ERROR || bufferSize == ZSTD_CONTENTSIZE_UNKNOWN)
        {
            qWarning() << "[AceCrypto] " << "Can not decompress, as content size can not be determined.";
            return {};
        }

        QScopedArrayPointer<char> buffer(new char[bufferSize]);
        auto zstdCode = ZSTD_decompressDCtx(AceLogDCtx, buffer.data(), bufferSize, content.data(), content.size());
        if (ZSTD_isError(zstdCode))
        {
            qWarning() << "[AceCrypto] " << QStringLiteral("Can not decompress project file with zstd. code= %1, errorString= %2")
                          .arg(ZSTD_getErrorCode(zstdCode))
                          .arg(ZSTD_getErrorString(ZSTD_getErrorCode(zstdCode)));
            return {};
        }
        decompressed = QByteArray(buffer.data(), zstdCode);
    }
    else { //None
        auto bufferSize = ZSTD_getFrameContentSize(content.data(), content.size());
        if (bufferSize == ZSTD_CONTENTSIZE_ERROR || bufferSize == ZSTD_CONTENTSIZE_UNKNOWN)
        {
            qWarning() << "[AceCrypto] " << "Can not decompress, as content size can not be determined.";
            return {};
        }

        QScopedArrayPointer<char> buffer(new char[bufferSize]);
        auto zstdCode = ZSTD_decompress(buffer.data(), bufferSize, content.data(), content.size());
        if (ZSTD_isError(zstdCode))
        {
            qWarning() << "[AceCrypto] " << QStringLiteral("Can not decompress project file with zstd. code= %1, errorString= %2")
                          .arg(ZSTD_getErrorCode(zstdCode))
                          .arg(ZSTD_getErrorString(ZSTD_getErrorCode(zstdCode)));
            return {};
        }
        decompressed = QByteArray(buffer.data(), zstdCode);
    }

    return decompressed;
}
