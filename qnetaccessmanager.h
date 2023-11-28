#ifndef QNETACCESSMANAGER_H
#define QNETACCESSMANAGER_H

#include "qnetrequest.h"

#include <QIODevice>
#include <QByteArray>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QNetworkAccessManager>

/** network access manager with PATCH method included */
class QNetAccessManager : public QNetworkAccessManager
{
    Q_OBJECT
public:
    /** constructor */
    explicit QNetAccessManager(QObject *parent = nullptr);

    /** destructor */
    virtual ~QNetAccessManager();

    /** patch method request with QIODevice as body */
    QNetworkReply *patch(const QNetRequest &request, QIODevice *data);

    /** patch method request with QByteArray as body */
    QNetworkReply *patch(const QNetRequest &request, const QByteArray &data);

    /** patch method request with QHttpMultiPart as body */
    QNetworkReply *patch(const QNetRequest &request, QHttpMultiPart *multiPart);
};

#endif // QNETACCESSMANAGER_H
