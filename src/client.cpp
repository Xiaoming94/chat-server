#include <iostream>
#include <string>
#include <string_view>

#include <sys/socket.h>

constexpr int DOMAIN{AF_LOCAL};
constexpr int TYPE{42};
constexpr int PROTOCOL{0};

class ClientImpl
{
public:
    ClientImpl(std::string_view name) : 
        m_socket(socket(DOMAIN, TYPE, PROTOCOL))
    {
        connect(name);
    }

    void connect(std::string_view name)
    {
        if (establishConnection())
        {
            onSuccessfulConnection();
        }
        else
        {
            onConnectionFailed();
        }
    }

    bool establishConnection()
    {
        const sockaddr SERVER_NAME{.sa_family = AF_LOCAL, .sa_data = "127.0.0.1"};
        const socklen_t length{};
        if (::connect(m_socket, &SERVER_NAME, length) < 0)
        {
            onConnectionFailed();
            return false;
        }
        return false;
    }

    void onConnectionFailed()
    {
        std::cerr << "Connection establishment failed\n";
        std::abort();
    }

    void onSuccessfulConnection()
    {
        //listen to the UI
        //listen to the server
    }

private:
    int m_socket;
};

int main(int numberOfArguments, char ** args) {
    if (numberOfArguments != 2u)
    {
        std::cerr << "Not supported number of arguments \n"; 
        std::abort();
    }
    std::string name{args[1]};
    std::cout << "Client starting..." << name << std::endl;
    ClientImpl client(name);
    return 0;
}