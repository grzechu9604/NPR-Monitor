#include <iostream>

using namespace std;

class Monitor
{
private:
    int _id;
public:
    Monitor(int monitorId);
    ~Monitor();

    int GetId();
    void Wait();
    void Signal();
    void SignalAll();
    void P();
    void V(); 
};

Monitor::Monitor(int monitorId)
{
}

Monitor::~Monitor()
{
}
