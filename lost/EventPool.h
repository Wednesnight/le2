#ifndef LOST_EVENTPOOL_H
#define LOST_EVENTPOOL_H

#include "lost/Event.h"
#include "tinythread.h"

namespace lost
{

struct EventPool
{
  EventPool();
  ~EventPool();
  
  Event* borrowEvent();
  void returnEvent(Event* event);
  
  uint32_t _poolSize;
  Event* _events;
  tthread::mutex _mutex;
};

}

#endif

