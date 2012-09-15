//
//  ViewController.m
//  ReRunner
//
//  Created by Timo Boll on 14.09.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"

#include "lost/Engine.h"
#include "lost/EventPool.h"
#include "lost/EventQueue.h"

@interface ViewController () {
}
@property (strong, nonatomic) EAGLContext *context;

- (void)setupGL;
- (void)tearDownGL;

@end

@implementation ViewController

@synthesize context = _context;

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];

    if (!self.context) {
        NSLog(@"Failed to create ES context");
    }
    
    GLKView *view = (GLKView *)self.view;
    view.context = self.context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    
    [self setupGL];
}

- (void)viewDidUnload
{    
    [super viewDidUnload];
    
    [self tearDownGL];
    
    if ([EAGLContext currentContext] == self.context) {
        [EAGLContext setCurrentContext:nil];
    }
	self.context = nil;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc. that aren't in use.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
  return (interfaceOrientation == UIInterfaceOrientationLandscapeLeft ||
          interfaceOrientation == UIInterfaceOrientationLandscapeLeft);
}

- (void)setupGL
{
  [EAGLContext setCurrentContext:self.context];
  lost::Engine::instance()->doStartup();
  [EAGLContext setCurrentContext:Nil];
}

- (void)tearDownGL
{
  [EAGLContext setCurrentContext:self.context];
  lost::Engine::instance()->doShutdown();
  [EAGLContext setCurrentContext:Nil];
}

#pragma mark - GLKView and GLKViewController delegate methods

- (void)update
{
  [EAGLContext setCurrentContext:self.context];
  lost::Engine::instance()->doUpdate();
  [EAGLContext setCurrentContext:Nil];
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)touchEvent
{
  lost::Event* event = lost::Engine::instance()->eventPool->borrowEvent();
  event->base.type = lost::ET_TouchBegan;
  lost::Engine::instance()->eventQueue->addEvent(event);
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)touchEvent
{
  lost::Event* event = lost::Engine::instance()->eventPool->borrowEvent();
  event->base.type = lost::ET_TouchMoved;
  lost::Engine::instance()->eventQueue->addEvent(event);
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)touchEvent
{
  lost::Event* event = lost::Engine::instance()->eventPool->borrowEvent();
  event->base.type = lost::ET_TouchCancelled;
  lost::Engine::instance()->eventQueue->addEvent(event);
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)touchEvent
{
  lost::Event* event = lost::Engine::instance()->eventPool->borrowEvent();
  event->base.type = lost::ET_TouchEnded;
  lost::Engine::instance()->eventQueue->addEvent(event);
}

@end
