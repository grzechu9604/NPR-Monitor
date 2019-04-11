#include <zmq.hpp>
#include <string>
#include <iostream>
#include "ConfigReader.hpp"
#include "MessageSender.hpp"

using namespace std;

int main(int argc, char **argv)
{
    zmq::context_t context(1);
    MessageSender sender(&context, argv[1]);
    sender.SendP(1);
    sender.SendSignal(1);
    sender.SendSignalAll(1);
    sender.SendV(1);
    sender.SendWait(1);
}