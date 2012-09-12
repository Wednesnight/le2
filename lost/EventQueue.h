#ifndef LOST_EVENTQUEUE_H
#define LOST_EVENTQUEUE_H

#include "lost/Event.h"

namespace lost
{

struct EventQueue
{
  EventQueue();
  ~EventQueue();

  vector<Event*> _queue;
};

}
#endif

