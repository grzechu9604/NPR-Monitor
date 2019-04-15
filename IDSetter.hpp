#include <zmq.hpp>

using namespace std;
using namespace zmq;

class IDSetter
{
  private:
  public:
    IDSetter(char * bindingAddress, int followersAmount);
    ~IDSetter();
};

