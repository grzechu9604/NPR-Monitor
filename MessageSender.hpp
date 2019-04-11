#include "MonitorDataTypes.hpp"
#include <iostream>
#include <zmq.hpp>

using namespace zmq;
using namespace std;

class MessageSender
{
private:
    void SendMessage(int monitorId, enum requestTypes msgType);
    socket_t publisher;
public:
    MessageSender(context_t * context, string address);
    ~MessageSender();
    void SendP(int monitorId);
    void SendV(int monitorId);
    void SendWait(int monitorId);
    void SendSignal(int monitorId);
    void SendSignalAll(int monitorId);
    void GenerateNoise();
};

