#include "MessageSender.hpp"

MessageSender::MessageSender(context_t * context, string address) : publisher(*context, ZMQ_PUB)
{
    string transport(address);
    this->publisher.bind(transport);
}

MessageSender::~MessageSender()
{
}

void MessageSender::SendMessage(int monitorId, enum requestTypes msgType)
{
    struct Message myMmessage;
    myMmessage.ID = 'G';
    myMmessage.monitorId = monitorId;
    myMmessage.type = msgType;

    zmq::message_t message(sizeof(struct Message));
    memcpy(message.data(), &myMmessage, sizeof(struct Message));
    this->publisher.send(message);
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
