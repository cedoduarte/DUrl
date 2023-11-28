#ifndef DURL_H
#define DURL_H

#include "qnetaccessmanager.h"

#include <QNetworkReply>
#include <QObject>

class DUrl : public QObject
{
    Q_OBJECT
public:
    explicit DUrl(int argc, char **argv, QObject *parent = nullptr);
    virtual ~DUrl();
    void start();
private slots:
    void finished(QNetworkReply *reply);
    void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);
private:
    /**
        input examples:
            name=Carlos Enrique Duarte Ortiz;age=28;free=true
    */
    QByteArray toJson(const QString &input) const;

    int m_argc;
    char **m_argv;
    QNetAccessManager *m_manager;
};

#endif // DURL_H
