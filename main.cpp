#include <zmq.hpp>
#include <string>
#include <iostream>
#include "ConfigReader.hpp"
#include "MessageSender.hpp"

using namespace std;

int main ()
{
    zmq::context_t context(1);
    MessageSender sender(&context, "tcp://*:5556");
    sender.SendP(1);
    sender.SendSignal(1);
    sender.SendSignalAll(1);
    sender.SendV(1);
    sender.SendWait(1);
}