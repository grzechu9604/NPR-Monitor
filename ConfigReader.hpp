#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class ConfigReader
{
private:
public:
    ConfigReader(string);
    ~ConfigReader();
    int AmountOfProcessesToConnect;
    vector<string> ProcessesAdresses;
};