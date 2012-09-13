#ifndef LOST_EVENTPOOL_H
#define LOST_EVENTPOOL_H

#include "lost/Event.h"

namespace tthread { class mutex; }

namespace lost
{

struct EventPool
{
  EventPool();
  ~EventPool();
  
  Event* borrowEvent();
  void returnEvent(Event* event);
  
  size_t          _numEvents;
  Event*          _events;
  tthread::mutex* _mutex;
};

}

#endif

