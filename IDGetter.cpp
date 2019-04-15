#include "IDGetter.hpp"
#include "MonitorDataTypes.hpp"

IDGetter::IDGetter(string setterAddress)
{
    context_t context(2);
    socket_t socket(context, ZMQ_REQ);
    socket.connect(setterAddress);

    Message m;
    m.Data = -1;
    m.MonitorId = -1;
    m.ProcessID = -1;
    m.Type = GIVE_ID_MSG_TYPE;

    message_t request(sizeof(struct Message));
    memcpy(request.data(), &m, (sizeof(struct Message)));

    Message replyMsg;
    do
    {
        socket.send(request);

        message_t reply;
        socket.recv(&reply);
        memcpy(&replyMsg, reply.data(), (sizeof(struct Message)));

    } while (replyMsg.Type != SET_ID_MSG_TYPE);

    this->_ID = replyMsg.Data;
}

IDGetter::~IDGetter()
{
}

int IDGetter::GetID()
{
    return this->_ID;
}