#ifndef LOST_EVENT_H
#define LOST_EVENT_H

namespace lost
{

enum EventType
{
  ET_None=0,
  ET_KeyDownEvent,
  ET_KeyUpEvent,
  ET_MouseDownEvent,
  ET_MouseUpEvent,
  ET_MouseMoveEvent
};

struct BaseEvent
{
  EventType type;
  bool      used;
};

struct KeyEvent : BaseEvent
{
};

struct MouseEvent : BaseEvent
{
  
};

union Event
{
  BaseEvent base;
  KeyEvent keyEvent;
  MouseEvent mouseEvent;
};

}

#endif

