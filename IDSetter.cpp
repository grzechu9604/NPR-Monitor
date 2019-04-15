#include "IDSetter.hpp"
#include "MonitorDataTypes.hpp"

IDSetter::IDSetter(string bindingAddress, int followersAmount)
{
    context_t context(2);
    socket_t socket(context, ZMQ_REP);
    socket.bind(bindingAddress);

    int processesAmount = followersAmount + 1;

    for (int i = 1; i < processesAmount; i++)
    {
        message_t request;
        socket.recv(&request);
        Message recevedMsg;
        memcpy(&recevedMsg, request.data(), (sizeof(struct Message)));

        Message replyMsg;
        message_t reply(sizeof(struct Message));
        replyMsg.ProcessID = 0;
        replyMsg.MonitorId = -1;
        if (recevedMsg.Type == GIVE_ID_MSG_TYPE)
        {
            replyMsg.Type = SET_ID_MSG_TYPE;
            replyMsg.Data = i;
        }
        else
        {
            // SERVER WASN'T READY
            replyMsg.Type = RESET_MSG_TYPE;
            replyMsg.Data = -1;
            i--;
        }
        memcpy(reply.data(), &replyMsg, sizeof(struct Message));
        socket.send(reply);
    }
}

IDSetter::~IDSetter()
{
}