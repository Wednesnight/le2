#include "lost/EventPool.h"
#include "tinythread.h"

namespace lost
{

EventPool::EventPool()
{
  _mutex = new tthread::mutex;

  _numEvents = 128;
  size_t bytes = _numEvents*sizeof(Event);
  _events = (Event*)malloc(bytes);
  memset(_events, 0, bytes);
  for(size_t i=0; i<_numEvents; ++i)
  {
    Event* event = &_events[i];
    event->base.pool = this;
  }
}

EventPool::~EventPool()
{
  delete _mutex;
  free(_events);
}

Event* EventPool::borrowEvent()
{
  _mutex->lock();
  Event* result = NULL;
  
  for(size_t i=0; i<_numEvents; ++i)
  {
    if(_events[i].base.used == false)
    {
      result = &_events[i];
      result->base.used = true;
      break;
    }
  }
  ASSERT(result, "no free event found");
  _mutex->unlock();
  return result;
}

void EventPool::returnEvent(Event* event)
{
  _mutex->lock();
  event->base.used = false;
  _mutex->unlock();
}

}

