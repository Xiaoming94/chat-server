#include <iostream>
#include <string>

int main(int numberOfArguments, char ** args) {
    if (numberOfArguments != 2u)
    {
        std::cerr << "Not supported number of arguments \n"; 
        std::abort();
    }
    std::string name{args[1]};
    std::cout << "Client startin'..." << name << std::endl;
    return 0;
}

//two users chat each other
//Given: one client sends a message to another client
//And:  if the other client is off line
//When: sender has no confirmation (yet)
//Then: ....

//there is a pending message
//the client starts
//the message is displayed (optionally with the sender)

//the client is running
//the client receives a message
//the message is displayed (optionally with the sender)

// client:
// identify itself
// start up (subscription, connect to the server) > receive messages 
// send

// server
// start up 
// receive and forward or store messages 

// ./client userId
// Client starting...
// send ravi Hello 
// To ravi: Hello 
// From ravi: Hej to you as well

class ClientUI
{
    public:
    //display output 
    virtual void print(std::string_view message) const = 0;
};

class ClientUIStdOutput : public ClientUI
{
public:
    void print(std::string_view message) const override
    {
        std::cout << message << '\n';        
    }
};

class ClientBackEnd
{
public:
    //connect to server
    virtual void start(std::string_view name) = 0;

    virtual void send(std::string_view message, std::string_view to) const = 0;
};

class ClientBackEndImpl : public ClientBackEnd
{

    private:
    std::reference_wrapper<ClientUI> m_ui;
};