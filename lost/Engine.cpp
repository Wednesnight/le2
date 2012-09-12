#include "lost/Engine.h"

namespace lost
{

static Engine* _lostEngine = NULL;

Engine::Engine()
{
}

Engine::~Engine()
{
}

Engine* Engine::instance()
{
  if(!_lostEngine)
  {
    _lostEngine = new Engine;
  }
  return _lostEngine;
}

void Engine::doStartup()
{
  // engine startup
  glContext = new Context;
  // user startup
  startup();
}

void Engine::doShutdown()
{
  // user shutdown
  shutdown();
  // engine shutdown
  delete glContext;
}


}