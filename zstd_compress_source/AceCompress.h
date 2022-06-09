#ifndef ACECOMPRESS_H
#define ACECOMPRESS_H

#include "qtmetamacros.h"
#include <QByteArray>

namespace AceCompress {
    Q_NAMESPACE

    enum ZStdDictType {
        None = 0,
        AceLog = 1,

        MaxSupported = 1
    };
    Q_ENUM_NS(ZStdDictType)

    QByteArray zstdCompress(const QByteArray& content, ZStdDictType dictType = None);
    QByteArray zstdDecompress(const QByteArray& content, ZStdDictType dictType = None);
}

#endif // ACECOMPRESS_H
