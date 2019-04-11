
enum requestTypes
{
    WAIT_MSG_TYPE, SIGNAL_MSG_TYPE, SIGNAL_ALL_MSG_TYPE, P_MSG_TYPE, V_MSG_TYPE, NOISE_MSG_TYPE
};

struct Message {
    char ID;
    requestTypes type;
    int monitorId;
};