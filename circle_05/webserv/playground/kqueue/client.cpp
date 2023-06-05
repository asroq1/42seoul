#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/event.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#ifndef PORT
#define PORT 8080
#endif

int handle_error(std::string str) {
    perror(str.c_str());
    exit(1);
}

/*
        chgLst에 추가해주면 kevent함수가 호출할 때마다 해당 이벤트를 모니터링
   한다.
 */
void chgEvnts(std::vector<struct kevent> &chgLst, uintptr_t ident,
              int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data,
              void *udata) {

    struct kevent tmpEvnt;

    EV_SET(&tmpEvnt, ident, filter, flags, fflags, data, udata);
    chgLst.push_back(tmpEvnt);
}

int main() {
    int serv_sock;
    struct sockaddr_in serv_addr;

    if ((serv_sock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
        return (handle_error("socket : "));

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if (connect(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)))
        return (handle_error("connect : "));

    fcntl(serv_sock, F_SETFL, fcntl(serv_sock, F_GETFL, 0) | O_NONBLOCK);

    int kq;
    if ((kq = kqueue()) < 0)
        return (handle_error("kqueue ; "));

    std::vector<struct kevent> chgLst; // kqueue에 올라가는 이벤트 배열
    struct kevent evntLst[8];

    /*
            모니터링을 원하는 옵션을 추가한다.
                        모니터링을 원하는 옵션들이 감지되면 발생된 이벤트 정보를
       eventLst에다가 저장한다.
    */
    chgEvnts(chgLst, serv_sock, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
    chgEvnts(chgLst, serv_sock, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);

    int newEvnts;
    struct kevent *curEvnts;

    while (1) {
        newEvnts = kevent(kq, &chgLst[0], chgLst.size(), evntLst, 8, NULL);
        if (newEvnts == -1)
            handle_error("kevent : ");

        chgLst.clear(); // 새로 발생한 이벤트 처리를 위해 이전에 감지된 이벤트를
                        // 초기화

        for (int i = 0; i < newEvnts; i++) {
            curEvnts = &evntLst[i];
            if (curEvnts->flags & EV_ERROR) {
                std::cerr << "client socket error\ndisconnecting...\n";
                break;
                // filter는 EVFILT_READ & WRITE를 감지한다.
            } else if (curEvnts->filter == EVFILT_READ) {
                char buff[1024];
                memset(buff, 0, sizeof(buff));
                int n = read(curEvnts->ident, buff, sizeof(buff));

                if (n < 0) {
                    std::cerr << "client socket error\ndisconnecting...\n";
                    break;
                } else
                    std::cout << "echoed from server : \n" << buff << std::endl;
            } else if (curEvnts->filter == EVFILT_WRITE) {
                std::cout << "put msg to send : " << std::endl;
                std::string buffer;
                while (true) {
                    std::getline(std::cin, buffer);
                    if (std::cin.eof()) {
                        std::cerr << "\nEOF signaled" << std::endl;
                        close(serv_sock);
                        std::cout << "bye 👋" << std::endl;
                        exit(1);
                    }
                    if (buffer.size())
                        break;
                    std::cerr << "You cannot send empty msg" << std::endl;
                }
                if (write(curEvnts->ident, buffer.c_str(), buffer.size()) < 0) {
                    perror("write : ");
                    break;
                }
            }
        }
    }
    close(serv_sock);
    std::cout << "bye 👋" << std::endl;
    return 0;
}