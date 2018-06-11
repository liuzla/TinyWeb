/*
*Author:GeneralSandman
*Code:https://github.com/GeneralSandman/TinyWeb
*E-mail:generalsandman@163.com
*Web:www.generalsandman.cn
*/

/*---XXX---
*
****************************************
*
*/

#include "my_http_parser.h"
#include <boost/bind.hpp>
#include <iostream>
#include <string>

using namespace std;

int getMessage()
{
    std::cout << "get Message\n";
}

int getUrl()
{
    cout << "get url\n";
}

int getStatus()
{
    cout << "get status\n";
}

int getRequestLine()
{
    cout << "get request line\n";
}

int getHeader()
{
    cout << "get request header\n";
}

int getHeaderKey()
{
    cout << "get header key\n";
}

int getHeaderValue()
{
    cout << "get header value\n";
}

int getBody()
{
    cout << "get body\n";
}

int endMessage()
{
    cout << "end message\n";
}

int getChunk()
{
    cout << "get chunk\n";
}

int endChunk()
{
    cout << "end chunk\n";
}

void testHttpParser()
{
    HttpParserSettings settings;
    settings.setGetMessageCallback(boost::bind(getMessage));
    settings.setGetRequestLineCallback(boost::bind(getRequestLine));
    settings.setGetHeaderCallback(boost::bind(getHeader));
    settings.setGetBodyCallback(boost::bind(getBody));
    settings.setGetEndMessageCallback(boost::bind(endMessage));

    HttpParser parser(&settings);

    parser.invokeByName("getMessage", nullptr, 0);
    parser.invokeByName("getRequestLine", nullptr, 0);
    parser.invokeByName("getHeader", nullptr, 0);
    parser.invokeByName("getBody", nullptr, 0);
    parser.invokeByName("endMessage", nullptr, 0);
}

void testHttpParserResponse()
{
    string response = "HTTP/1.1 200 OK\r\n"
                      "Date: Tue, 04 Aug 2009 07:59:32 GMT\r\n"
                      "Server: Apache\r\n"
                      "X-Powered-By: Servlet/2.5 JSP/2.1\r\n"
                      "Content-Type: text/xml; charset=utf-8\r\n"
                      "Connection: close\r\n"
                      "\r\n";
                    //   "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                    //   "<SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://schemas.xmlsoap.org/soap/envelope/\">\n"
                    //   "<SOAP-ENV:Body>\n"
                    //   "<SOAP-ENV:Fault>\n"
                    //   "<faultcode>SOAP-ENV:Client</faultcode>\n"
                    //   "<faultstring>Client Error</faultstring>\n"
                    //   "</SOAP-ENV:Fault>\n"
                    //   "</SOAP-ENV:Body>\n"
                    //   "</SOAP-ENV:Envelope>";

    string response1 = "HTTP/1.1 304 Not Modified\r\n"
                       "Server: Tengine\r\n"
                       "Date: Mon, 11 Jun 2018 07:18:14 GMT\r\n"
                       "Content-Type: text/html; charset=utf-8\r\n"
                       "Connection: keep-alive\r\n"
                       "Vary: Ali-Detector-Type\r\n"
                       "Cache-Control: max-age=60, s-maxage=300\r\n"
                       "X-Snapshot-Age: 1\r\n"
                       "Content-MD5: DheThrvjUs/c+FtbVv7Sbw==\r\n"
                       "ETag: W/\"29d7-163e38938b3\"\r\n"
                       "Via: cache9.l2cm12-1[0,304-0,H], cache48.l2cm12-1[0,0], cache6.cn295[0,304-0,H], cache6.cn295[1,0]\r\n"
                       "Age: 121\r\n"
                       "X-Cache: HIT TCP_IMS_HIT dirn:6:453356086 mlen:-1\r\n"
                       "Timing-Allow-Origin: *\r\n"
                       "EagleId: 7ceee81815287014946507756e\r\n"
                       "Strict-Transport-Security: max-age=31536000\r\n"
                       "\r\n";

        HttpParserSettings settings;
    settings.setGetMessageCallback(boost::bind(getMessage));
    settings.setGetRequestLineCallback(boost::bind(getRequestLine));
    settings.setGetHeaderCallback(boost::bind(getHeader));
    settings.setGetBodyCallback(boost::bind(getBody));
    settings.setGetEndMessageCallback(boost::bind(endMessage));

    HttpParser parser(&settings);
    parser.setType(HTTP_RESPONSE);
    int begin = 0;
    parser.execute(response, begin, response.size());
    cout << "begin:" << begin << endl;
}

void testHttpParserRequest()
{
}

int main()
{
    // testHttpParser();
    testHttpParserResponse();
    // testHttpParserRequest();
    return 0;
}
