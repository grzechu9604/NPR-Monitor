/**
 * 
 * ./main --addr protocol://address:port --config configFilePath --isServer 1/0
 * 
 * 
 **/

#include <zmq.hpp>
#include <string>
#include <iostream>
#include <unistd.h>
#include "ConfigReader.hpp"
#include "MessageSender.hpp"
#include "IDGetter.hpp"
#include "IDSetter.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    ConfigReader cr(argv[4]);

    int id = -1;

    if (argv[6][0] == '1')
    {
        id = 0;
        IDSetter setter(argv[2], cr.ProcessesAdresses.size() - 1);
    }
    else
    {
        IDGetter getter(cr.ProcessesAdresses[0]);
        id = getter.GetID();
    }

    cout << "My ID: " << id << endl;
    
}