#include "qnetaccessmanager.h"

QNetAccessManager::QNetAccessManager(QObject *parent)
    : QNetworkAccessManager(parent)
{
    // nothing to do here
}

QNetAccessManager::~QNetAccessManager()
{
    // nothing to do here
}

QNetworkReply *QNetAccessManager::patch(const QNetRequest &request, QIODevice *data)
{
    return sendCustomRequest(request, "PATCH", data);
}

QNetworkReply *QNetAccessManager::patch(const QNetRequest &request, const QByteArray &data)
{
    return sendCustomRequest(request, "PATCH", data);
}

QNetworkReply *QNetAccessManager::patch(const QNetRequest &request, QHttpMultiPart *multiPart)
{
    return sendCustomRequest(request, "PATCH", multiPart);
}
