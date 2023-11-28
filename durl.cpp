#include "durl.h"
#include "qnetrequest.h"

#include <QRegularExpression>
#include <QRegularExpressionMatchIterator>
#include <QRegularExpressionMatch>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>

DUrl::DUrl(int argc, char **argv, QObject *parent)
    : QObject(parent)
{
    m_argc = argc;
    m_argv = argv;
    m_manager = new QNetAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished, this, &DUrl::finished);
    connect(m_manager, &QNetAccessManager::sslErrors, this, &DUrl::sslErrors);
}

DUrl::~DUrl()
{
}

QByteArray DUrl::toJson(const QString &input) const
{
    QString output = "{";

    // Define a regular expression pattern to match key-value pairs
    QRegularExpression regex("(\\w+)\\s*=\\s*([^;]+)\\s*(?:;|$)");

    // Iterate over matches and extract key-value pairs
    QRegularExpressionMatchIterator matchIterator = regex.globalMatch(input);
    while (matchIterator.hasNext())
    {
        QRegularExpressionMatch match = matchIterator.next();
        if (match.hasMatch())
        {
            QString key = match.captured(1);
            QString value = match.captured(2);
            if (value.contains(" "))
            {
                value = QString("\"%1\"").arg(value);
            }
            else
            {
                bool ok;
                value.toDouble(&ok);
                if (!ok)
                {
                    if (value != "true" && value != "false")
                    {
                        value = QString("\"%1\"").arg(value);
                    }
                }
            }
            output += QString(",\"%1\":%2").arg(key, value);
        }
    }
    output += "}";
    output.replace("{,", "{");

    QByteArray resultJson;
    QJsonParseError conversionError;
    QJsonDocument doc = QJsonDocument::fromJson(output.toLatin1(), &conversionError);
    if (conversionError.error == QJsonParseError::NoError)
    {
        resultJson = doc.toJson(QJsonDocument::Compact);
    }
    return resultJson;
}

void DUrl::start()
{
    QString httpMethod = m_argv[1];
    QString url = m_argv[2];
    if (httpMethod == "GET")
    {
        m_manager->get(QNetworkRequest(QUrl(url)));
    }
    else if (httpMethod == "DELETE")
    {
        m_manager->deleteResource(QNetRequest(QUrl(url)));
    }
    else if (httpMethod == "POST" || httpMethod == "PUT")
    {
        QString body = m_argv[3];
        if (body == "BODY")
        {
            QString keyValues;
            keyValues += m_argv[4];
            for (int i = 5; i < m_argc; i++)
            {
                keyValues += " " + QString(m_argv[i]);
            }
            if (httpMethod == "POST")
            {
                m_manager->post(QNetRequest(QUrl(url)), toJson(keyValues));
            }
            else
            {
                m_manager->put(QNetRequest(QUrl(url)), toJson(keyValues));
            }
        }
    }
}

void DUrl::finished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        qDebug().noquote().nospace() << reply->readAll();
    }
    else
    {
        qDebug().noquote().nospace() << reply->errorString();
    }
}

void DUrl::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    qDebug() << "SSL Errors:";
    for (const QSslError &error : errors) {
        qDebug() << "   " << error.errorString();
    }

    // You can implement your logic here to decide how to handle SSL errors.

    // For example, you can ignore all SSL errors and continue.
    reply->ignoreSslErrors();

    qDebug().noquote().nospace() << reply->readAll();
}

