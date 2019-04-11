#include "ConfigReader.hpp"

using namespace std;

ConfigReader::ConfigReader(string configPath)
{
    ifstream configFile;
    configFile.open (configPath);

    string line;
    while(getline(configFile, line)){
        ProcessesAdresses.push_back(line);
    }
}

ConfigReader::~ConfigReader()
{
    ProcessesAdresses.clear();
}
