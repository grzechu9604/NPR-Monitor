#include <zmq.hpp>
#include <string>
#include <iostream>
#include "ConfigReader.hpp"

using namespace std;

int main ()
{
    string configPath = "adresses.config";
    ConfigReader cr(configPath);
    int t = 0;
}