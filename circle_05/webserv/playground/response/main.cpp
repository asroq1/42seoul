
#include <iostream>
#include <map>
#include <string>

int main() {
    // 클라이언트로부터 HTTP 요청을 받습니다.
    std::string request =
        "GET /index.html HTTP/1.1\r\nLIMIT: 10\r\nEXCEPT: "
        "private\r\nAUTOINDEX: on\r\n\r\n";

    // HTTP 요청의 첫 번째 줄에서 메소드와 경로를 추출합니다.
    size_t first_space = request.find(' ');
    size_t second_space = request.find(' ', first_space + 1);
    std::string method = request.substr(0, first_space);
    std::string path =
        request.substr(first_space + 1, second_space - first_space - 1);

    // HTTP 요청에서 추가적인 정보를 추출합니다.
    std::map<std::string, std::string> headers;
    size_t start = request.find("\r\n") + 2;
    while (start < request.size()) {
        size_t end = request.find("\r\n", start);
        if (end == std::string::npos) break;

        size_t colon = request.find(':', start);
        std::string name = request.substr(start, colon - start);
        std::string value = request.substr(colon + 2, end - colon - 2);

        headers[name] = value;

        start = end + 2;
    }

    // 메소드가 GET, POST 또는 DELETE인 경우에만 요청을 처리합니다.
    if (method == "GET" || method == "POST" || method == "DELETE") {
        // 요청을 처리하고 적절한 응답을 생성합니다.
        std::cout << "Method: " << method << \std::endl;
        std::cout << "Path: " << path << std::endl;
        for (const auto& header : headers) {
            std::cout << header.first << ": " << header.second << std::endl;
        }
    } else {
        // 지원하지 않는 메소드에 대한 응답을 생성합니다.
        std::cout << "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
    }

    return 0;
}
//```

//    이 코드는 클라이언트로부터 HTTP 요청을 받아들이고,
//    요청의 메소드와 경로를 추출합니다.또한 요청에서 LIMIT,
//    EXCEPT 및 AUTOINDEX와 같은 추가적인 정보를 추출합니다.이후에는 메소드가
//    GET, POST 또는 DELETE인 경우에만 요청을 처리하고 적절한 응답을 생성합니다
//        .

//    이 코드는 간단한 예제일 뿐이며 실제 웹 서버 구현에서는 더 많은 기능과 세부
//        사항이 필요할 수 있습니다.