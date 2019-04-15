#include "MessageSender.hpp"


#include <unistd.h>

MessageSender::MessageSender(context_t * context, char * address) : publisher(*context, ZMQ_PUB)
{
    string transport(address);
    this->publisher.bind(transport);
    this->GenerateNoise();
}

MessageSender::~MessageSender()
{
}

void MessageSender::GenerateNoise()
{
    for(size_t i = 0; i < 10; i++)
    {
        usleep(100000);
        SendMessage(-1, NOISE_MSG_TYPE);
    }
    
}

void MessageSender::SendMessage(int monitorId, enum requestTypes msgType)
{
    struct Message myMmessage;
    //myMmessage.ID = 'G';
    myMmessage.MonitorId = monitorId;
    myMmessage.Type = msgType;

    zmq::message_t message(sizeof(struct Message));
    memcpy(message.data(), &myMmessage, sizeof(struct Message));
    cout << this->publisher.send(message) << endl;
}

void MessageSender::SendP(int monitorId)
{
    SendMessage(monitorId, P_MSG_TYPE);
}

void MessageSender::SendV(int monitorId)
{
    SendMessage(monitorId, V_MSG_TYPE);
}

void MessageSender::SendWait(int monitorId)
{
    SendMessage(monitorId, WAIT_MSG_TYPE);
}

void MessageSender::SendSignal(int monitorId)
{
    SendMessage(monitorId, SIGNAL_MSG_TYPE);
}

void MessageSender::SendSignalAll(int monitorId)
{
    SendMessage(monitorId, SIGNAL_ALL_MSG_TYPE);
}
