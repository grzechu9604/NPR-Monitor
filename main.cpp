/**
 * 
 * ./main --config configFilePath
 * 
 * 
 **/

#include <zmq.hpp>
#include <string>
#include <iostream>
#include <unistd.h>
#include "ConfigReader.hpp"
#include "MonitorWrapper.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    ConfigReader cr(argv[2]);

    MonitorWrapper wrapper(cr);

    cout << "My ID: " << wrapper.GetID() << endl;
}