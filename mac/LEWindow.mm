#import "LEWindow.h"
#include "lost/Engine.h"
#include "lost/EventPool.h"
#include "lost/EventQueue.h"

@implementation LEWindow

-(void)keyDown:(NSEvent *)theEvent
{
  lost::Event* event = lost::Engine::instance()->eventPool->borrowEvent();
  event->base.type = lost::ET_KeyDownEvent;
  lost::Engine::instance()->eventQueue->addEvent(event);
}

-(void)keyUp:(NSEvent *)theEvent
{
  lost::Event* event = lost::Engine::instance()->eventPool->borrowEvent();
  event->base.type = lost::ET_KeyUpEvent;
  lost::Engine::instance()->eventQueue->addEvent(event);
}

- (void)mouseDown:(NSEvent *)theEvent
{
  lost::Event* event = lost::Engine::instance()->eventPool->borrowEvent();
  event->base.type = lost::ET_MouseDownEvent;
  lost::Engine::instance()->eventQueue->addEvent(event);
}

- (void)mouseUp:(NSEvent *)theEvent
{
  lost::Event* event = lost::Engine::instance()->eventPool->borrowEvent();
  event->base.type = lost::ET_MouseUpEvent;
  lost::Engine::instance()->eventQueue->addEvent(event);
}

- (void)mouseMoved:(NSEvent *)theEvent
{
  lost::Event* event = lost::Engine::instance()->eventPool->borrowEvent();
  event->base.type = lost::ET_MouseMoveEvent;
  lost::Engine::instance()->eventQueue->addEvent(event);
}

-(BOOL)canBecomeKeyWindow
{
  return YES;
}


@end

