#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#pragma once

class ConfigReader
{
private:
    bool isSetter;
public:
    ConfigReader(char * configFilePath);
    ~ConfigReader();
    vector<string> ProcessesAdresses;
    bool IsSetter();
    string PassiveAddress;
};