#include "ConfigReader.hpp"
#include "IDSetter.hpp"
#include "IDGetter.hpp"

class MonitorWrapper
{
private:
    bool isSetter;
    string ActiveAddress;
    string PassiveAddress;
    ConfigReader cr;
    int processID;
public:
    MonitorWrapper(ConfigReader cr);
    ~MonitorWrapper();
    int GetID();
};
