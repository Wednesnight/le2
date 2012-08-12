#include "lost/Log.h"
#include <iostream>

namespace lost
{

void log(const string& msg)
{
  std::cout << msg.c_str() << std::endl;
}

}