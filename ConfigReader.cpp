#include "ConfigReader.hpp"

using namespace std;

ConfigReader::ConfigReader(char * configFilePath)
{
    ifstream configFile;
    configFile.open(configFilePath);

    string line;
    getline(configFile, line);
    this->isSetter = line[0] == '1';

    getline(configFile, ActiveAddress);
    getline(configFile, PassiveAddress);
    
    while(getline(configFile, line)){
        ProcessesAdresses.push_back(line);
    }
}

bool ConfigReader::IsSetter()
{
    return isSetter;
}

ConfigReader::~ConfigReader()
{
    ProcessesAdresses.clear();
}
