#ifndef LOST_EVENTQUEUE_H
#define LOST_EVENTQUEUE_H

#include "lost/Event.h"

namespace tthread { class mutex; }

namespace lost
{

struct EventQueue
{
  EventQueue();
  ~EventQueue();

  void addEvent(Event* event); // threadsafe, use this to add events to the
  void returnAllEvents();

  tthread::mutex* _mutex; // ignore this
  vector<Event*> events; // read events directly from here in user code
};

}
#endif

