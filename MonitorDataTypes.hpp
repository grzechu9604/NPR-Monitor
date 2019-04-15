
enum requestTypes
{
    GIVE_ID_MSG_TYPE = 1, 
    SET_ID_MSG_TYPE,
    RESET_MSG_TYPE,
    WAIT_MSG_TYPE, 
    SIGNAL_MSG_TYPE, 
    SIGNAL_ALL_MSG_TYPE, 
    P_MSG_TYPE, 
    V_MSG_TYPE, 
    NOISE_MSG_TYPE
};

struct Message {
    int ProcessID;
    requestTypes Type;
    int MonitorId;
    int Data;
};
