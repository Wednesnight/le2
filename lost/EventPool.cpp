#include "lost/EventPool.h"

namespace lost
{

EventPool::EventPool()
{
  _poolSize = 128;
  size_t bytes = _poolSize*sizeof(Event);
  _events = (Event*)malloc(bytes);
  memset(_events, 0, bytes);
}

EventPool::~EventPool()
{
  free(_events);
}

Event* EventPool::borrowEvent()
{
  _mutex.lock();
  Event* result = NULL;
  
  for(uint32_t i=0; i<_poolSize; ++i)
  {
    if(_events[i].base.used == false)
    {
      result = &_events[i];
      result->base.used = true;
      break;
    }
  }
  ASSERT(result, "no free event found");
  _mutex.unlock();
  return result;
}

void EventPool::returnEvent(Event* event)
{
  _mutex.lock();
  event->base.used = false;
  _mutex.unlock();
}

}

