#include "MonitorWrapper.hpp"

MonitorWrapper::MonitorWrapper(ConfigReader cr) : cr(cr)
{
    this->isSetter = cr.IsSetter();
    this->ActiveAddress = cr.ActiveAddress;
    this->PassiveAddress = cr.PassiveAddress;

    if (this->isSetter)
    {
        this->processID = 0;
        IDSetter(this->PassiveAddress, cr.ProcessesAdresses.size());
    }
    else
    {
        IDGetter getter(cr.ProcessesAdresses[0]);
        this->processID = getter.GetID();
    }
}

MonitorWrapper::~MonitorWrapper()
{
}

int MonitorWrapper::GetID()
{
    return this->processID;
}