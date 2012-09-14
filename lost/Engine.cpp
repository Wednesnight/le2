#include "lost/Engine.h"
#include "lost/EventPool.h"
#include "lost/EventQueue.h"
#include "lost/Context.h"
#include "lost/FontManager.h"
#include "lost/Platform.h"

namespace lost
{

static Engine* _lostEngine = NULL;

Engine::Engine()
{
  eventPool = new EventPool;
  eventQueue = new EventQueue;
  glContext = NULL; // created in startup, after OS specific GLcontext was created
  fontManager = NULL;// created in startup, after glContext was created, because it will use GL resources
  lastFrameTimestamp = 0;
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
  fontManager = new FontManager;
  // user startup
  startup();
}

void Engine::doUpdate()
{
  long deltaFrameTime = lastFrameTimestamp != 0 ? currentTimeMilliSeconds() - lastFrameTimestamp : 0;
  update(deltaFrameTime);
  eventQueue->returnAllEvents();
  lastFrameTimestamp = currentTimeMilliSeconds();
}

void Engine::doShutdown()
{
  // user shutdown
  shutdown();
  // engine shutdown
  delete glContext;
}


}