#import "LEAppDelegate.h"
#import "LEGLView.h"
#include "lost/Engine.h"

@implementation LEAppDelegate

@synthesize window;

- (void) quitAction: (id)sender
{
  LEGLView* view = (LEGLView*)[window contentView];
  CVDisplayLinkStop([view displayLink]);
  lost::Engine::instance()->doShutdown();
  [[NSApplication sharedApplication] terminate: nil];
}

@end
