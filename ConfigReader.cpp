#include "ConfigReader.hpp"

using namespace std;

ConfigReader::ConfigReader(char * configFilePath)
{
    ifstream configFile;
    configFile.open(configFilePath);

    string line;
    while(getline(configFile, line)){
        ProcessesAdresses.push_back(line);
    }
}

ConfigReader::~ConfigReader()
{
    ProcessesAdresses.clear();
}
