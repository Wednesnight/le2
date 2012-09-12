#import "LEAppDelegate.h"
#import "LEGLView.h"
#include "lost/MainHooks.h"

@implementation LEAppDelegate

- (void) quitAction: (id)sender
{
  DOUT("");
  LEGLView* view = (LEGLView*)[_window contentView];
  CVDisplayLinkStop([view displayLink]);
  lost::leShutdown();
  [[NSApplication sharedApplication] terminate: nil];
}

@end
