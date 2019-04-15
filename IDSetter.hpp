#include <zmq.hpp>

using namespace std;
using namespace zmq;

class IDSetter
{
  private:
  public:
    IDSetter(string bindingAddress, int followersAmount);
    ~IDSetter();
};

