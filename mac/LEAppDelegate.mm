#import "LEAppDelegate.h"
#import "LEGLView.h"
#include "lost/Engine.h"

@implementation LEAppDelegate

- (void) quitAction: (id)sender
{
  LEGLView* view = (LEGLView*)[_window contentView];
  CVDisplayLinkStop([view displayLink]);
  lost::Engine::instance()->doShutdown();
  [[NSApplication sharedApplication] terminate: nil];
}

@end
