#ifndef QFLEXIBLEJSONOBJECT_H
#define QFLEXIBLEJSONOBJECT_H

#include <QJsonValue>
#include <QJsonObject>

/** flexible json object (not case sensitive properties) */
class QFlexibleJsonObject
{
public:
    /** gets the value without sensitive case checking */
    static QJsonValue value(const QJsonObject &object, const QString &key);

    /** constructor is deleted for avoiding the objects creation of this class */
    QFlexibleJsonObject() = delete;
};

#endif // QFLEXIBLEJSONOBJECT_H
