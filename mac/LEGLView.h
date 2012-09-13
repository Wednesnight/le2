#import <QuartzCore/CVDisplayLink.h>

@interface LEGLView : NSOpenGLView
{
  CVDisplayLinkRef _displayLink;
}

-(CVDisplayLinkRef)displayLink;

@end

