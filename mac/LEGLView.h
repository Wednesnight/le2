@interface LEGLView : NSOpenGLView
{
  CVDisplayLinkRef _displayLink;
}

-(CVDisplayLinkRef)displayLink;

@end

