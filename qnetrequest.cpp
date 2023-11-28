#include "qnetrequest.h"

#include <QSslSocket>
#include <QSslConfiguration>

QNetRequest::HeaderMimeType QNetRequest::s_defaultContentType = QNetRequest::ApplicationJson;

void QNetRequest::setDefaultContentType(HeaderMimeType mimeType)
{
    s_defaultContentType = mimeType;
}

QNetRequest::QNetRequest()
{
    setSslConfig();
    setContentTypeHeader(s_defaultContentType);
}

QNetRequest::QNetRequest(const QUrl &url)
{
    setSslConfig();
    setContentTypeHeader(s_defaultContentType);
    setUrl(url);
}

QNetRequest::~QNetRequest()
{
    // nothing to do here
}

void QNetRequest::setSslConfig()
{
    QSslConfiguration sslConfig = sslConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    setSslConfiguration(sslConfig);
}

void QNetRequest::setContentTypeHeader(QNetRequest::HeaderMimeType mimeType)
{
    setHeader(QNetworkRequest::ContentTypeHeader, contentType(mimeType));
}

QNetRequest::HeaderMimeType QNetRequest::contentTypeHeader() const
{
    return m_mimeType;
}

QString QNetRequest::sslLibraryBuildVersionString()
{
    return QSslSocket::sslLibraryBuildVersionString();
}

QString QNetRequest::contentType(QNetRequest::HeaderMimeType mimeType)
{
    switch (mimeType)
    {
        case FontTtf: return "font/ttf";
        case TextCss: return "text/css";
        case TextCsv: return "text/csv";
        case AudioAac: return "audio/aac";
        case ImageGif: return "image/gif";
        case AudioOgg: return "audio/ogg";
        case VideoOgg: return "video/ogg";
        case FontWoff: return "font/woff";
        case TextJson: return "text/json";
        case TextHtml: return "text/html";
        case TextPlain: return "text/plain";
        case ImageJpeg: return "image/jpeg";
        case AudioMidi: return "audio/midi";
        case VideoMpeg: return "video/mpeg";
        case ImageTiff: return "image/tiff";
        case AudioWebm: return "audio/webm";
        case VideoWebm: return "video/webm";
        case ImageWebp: return "image/webp";
        case FontWoff2: return "font/woff2";
        case Video3gpp: return "video/3gpp";
        case Audio3gpp: return "audio/3gpp";
        case AudioXWav: return "audio/x-wav";
        case Video3gpp2: return "video/3gpp2";
        case Audio3gpp2: return "audio/3gpp2";
        case ImageXIcon: return "image/x-icon";
        case ImageSvgXml: return "image/svg+xml";
        case TextCalendar: return "text/calendar";
        case VideoXMSVideo: return "video/x-msvideo";
        case ApplicationOgg: return "application/ogg";
        case ApplicationPdf: return "application/pdf";
        case ApplicationRtf: return "application/rtf";
        case ApplicationZip: return "application/zip";
        case ApplicationXml: return "application/xml";
        case ApplicationXSh: return "application/x-sh";
        case ApplicationJson: return "application/json";
        case ApplicationXCsh: return "application/x-csh";
        case ApplicationXTar: return "application/x-tar";
        case ApplicationXBzip: return "application/x-bzip";
        case ApplicationMSWord: return "application/msword";
        case ApplicationXBzip2: return "application/x-bzip2";
        case ApplicationEPubZip: return "application/epub+zip";
        case ApplicationXAbiWord: return "application/x-abiword";
        case ApplicationXhtmlXml: return "application/xhtml+xml";
        case ApplicationVndVisio: return "application/vnd.visio";
        case ApplicationJavaScript: return "application/javascript";
        case ApplicationAsteriskPlusJson: return "application/*+json";
        case ApplicationVndMsExcel: return "application/vnd.ms-excel";
        case ApplicationJavaArchive: return "application/java-archive";
        case ApplicationOctetStream: return "application/octet-stream";
        case ApplicationX7zCompressed: return "application/x-7z-compressed";
        case ApplicationVncAmazonEbook: return "application/vnd.amazon.ebook";
        case ApplicationXRarCompressed: return "application/x-rar-compressed";
        case ApplicationXShockwaveFlash: return "application/x-shockwave-flash";
        case ApplicationVndMsPowerPoint: return "application/vnd.ms-powerpoint";
        case ApplicationVndMozillaXulXml: return "application/vnd.mozilla.xul+xml";
        case ApplicationXwwwFormUrlEncoded: return "application/x-www-form-urlencoded";
        case ApplicationVndAppleInstallerXml: return "application/vnd.apple.installer+xml";
        case ApplicationVndOasisOpenDocumentText: return "application/vnd.oasis.opendocument.text";
        case ApplicationVndOasisOpenDocumentSpeadSheet: return "application/vnd.oasis.opendocument.spreadsheet";
        case ApplicationVndOasisOpenDocumentPresentation: return "application/vnd.oasis.opendocument.presentation";
    }
    return "";
}
