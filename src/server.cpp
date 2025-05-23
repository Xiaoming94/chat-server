#include <iostream>
#include <sys/socket.h>

constexpr int DOMAIN{AF_LOCAL};
constexpr int TYPE{42};
constexpr int PROTOCOL{0};

class Server
{
public:
    Server() :
        m_socket(socket(DOMAIN, TYPE, PROTOCOL))
    {}

    void start()
    {
        //publish itself
        const sockaddr SERVER_NAME{.sa_family = AF_LOCAL, .sa_data = "127.0.0.1"};
        const socklen_t length{};

        if (bind(m_socket, &SERVER_NAME, length) < 0)
        {
            std::cerr << "The server cannot be started\n";
            std::abort();
        }
    }

private:
    int m_socket;
};

int main() {
    std::cout << "Server starting..." << std::endl;
    Server server;
    server.start();
    return 0;
}