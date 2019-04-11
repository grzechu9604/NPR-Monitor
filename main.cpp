#include <zmq.hpp>
#include <string>
#include <iostream>
#include <unistd.h>
#include "ConfigReader.hpp"
#include "MessageSender.hpp"


using namespace std;

int main(int argc, char **argv)
{
    zmq::context_t context(1);
    MessageSender sender(&context, argv[1]);

    for(size_t i = 0; i < 100; i++)
    {
        sender.SendP(1);
        sender.SendSignal(2);
        sender.SendSignalAll(3);
        sender.SendV(4);
        sender.SendWait(5);
    }
    

}