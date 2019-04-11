#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class ConfigReader
{
private:
public:
    ConfigReader(char * configFilePath);
    ~ConfigReader();
    vector<string> ProcessesAdresses;
};