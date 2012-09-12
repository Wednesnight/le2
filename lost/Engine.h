#ifndef LOST_ENGINE_H
#define LOST_ENGINE_H

#include "lost/EventPool.h"
#include "lost/EventQueue.h"
#include "lost/Context.h"

namespace lost
{

struct Engine
{
  Engine();
  ~Engine();

  static Engine* instance();

  void startup();  // use provided, called by doStartup
  void update();   // user provided, called by OS specific code
  void shutdown(); // user provided, called by doShutdown
  
  void doStartup(); // called by OS specific code
  void doShutdown(); // called by OS specific code
  
  EventPool eventPool;
  EventQueue eventQueue;
  Context* glContext;
};

}

#endif

