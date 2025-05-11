#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <iomanip>

using std::string;
using std::ostringstream;
using std::isalnum;
using std::cout;
using std::cin;
using std::cerr;
using std::hex;
using std::uppercase;
using std::setw;
using std::nouppercase;
using std::getline;


string url_encode(const std::string &value)
{
    ostringstream escaped;
    escaped.fill('0');
    escaped << hex;
    for (auto c : value)
    {
        if (isalnum((unsigned char)c) || c=='-'||c=='_'||c=='.'||c=='~')
        {
            escaped << c;
        } 
            else
        {
            escaped << '%' << uppercase << setw(2)
                    << int((unsigned char)c) << nouppercase;
        }
    }
    return escaped.str();
}

int main()
{
    const string APPID = "99KJX8-RTP79JYR22" ;
    string input;
    cout << "Введите функцию от x (например, x^2 + sin(x)): ";
    getline(cin, input);

    string query = "derivative of " + input;
    string enc = url_encode(query);
    string host = "api.wolframalpha.com";
    string path = "/v1/result?appid=" + APPID + "&i=" + enc;

    struct addrinfo hints 
    {
    }, *res;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(host.c_str(), "80", &hints, &res) != 0) 
    {
        cerr << "getaddrinfo error\n";
        return 1;
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock < 0)
    {
        perror("socket");
        freeaddrinfo(res);
        return 1;
    }
    if (connect(sock, res->ai_addr, res->ai_addrlen) < 0)
    {
        perror("connect");
        close(sock);
        freeaddrinfo(res);
        return 1;
    }
    freeaddrinfo(res);

    ostringstream req;
    req << "GET " << path << " HTTP/1.0\r\n"
        << "Host: " << host << "\r\n"
        << "User-Agent: simple-cpp-client/1.0\r\n"
        << "Connection: close\r\n\r\n";
    string request = req.str();

    if (send(sock, request.c_str(), request.size(), 0) < 0)
    {
        perror("send");
        close(sock);
        return 1;
    }

    string response;
    char buffer[1024];
    ssize_t n;
    while ((n = recv(sock, buffer, sizeof(buffer), 0)) > 0)
    {
        response.append(buffer, n);
    }
    close(sock);

    if (n < 0)
    {
        perror("recv");
        return 1;
    }

    auto pos = response.find("\r\n\r\n");
    if (pos != std::string::npos)
    {
        string body = response.substr(pos + 4);
        cout << "Производная: " << body << "\n";
    } 
        else 
    {
        cout << "Не удалось получить тело ответа:\n" << response;
    }

    return 0;
}
