#include <zmq.hpp>
#include <string>

using namespace std;
using namespace zmq;

class IDGetter
{
private:
    int _ID;
public:
    IDGetter(string setterAddress);
    int GetID();
    ~IDGetter();
};

