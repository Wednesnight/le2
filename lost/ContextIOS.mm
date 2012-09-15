/*
 Copyright (c) 2012 Tony Kostanjsek, Timo Boll
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
 "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
 distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
 following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "lost/Context.h"
#import <GLKit/GLKit.h>

namespace lost
{
  struct Context::ContextHiddenMembers
  {
    EAGLContext* glContext;
  };
  
  void Context::initialize()
  {
    hiddenMembers = new ContextHiddenMembers;
    hiddenMembers->glContext = [EAGLContext currentContext];
  }
  
  void Context::finalize()
  {
    delete hiddenMembers;
  }
  
  void Context::makeCurrent()
  {
    [EAGLContext setCurrentContext:hiddenMembers->glContext];
  }
  
  void Context::clearCurrent()
  {
    [EAGLContext setCurrentContext:Nil];
  }
  
  void Context::swapBuffers()
  {
    //
  }
  
  void Context::vsync(bool enable)
  {
    //
  }
  
  void Context::multithreaded(bool enable)
  {
    //          
  }
  
  void* Context::getCurrentOsSpecific()
  {
    return NULL;
  }
  
  void Context::setCurrentOsSpecififc(void* ctx)
  {
    //
  }
}
