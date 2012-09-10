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

#ifndef LOST_CAMERA_H
#define LOST_CAMERA_H

#include "lost/Rect.h"
#include "lost/Matrix.h"
#include "lost/Vec2.h"

namespace lost
{
struct Camera
{
protected:
  Rect mViewport;
  Vec2       mDepth;

  Matrix mViewMatrix;
  Matrix mProjectionMatrix;
  
  virtual void update() = 0;
public:
  bool needsUpdate;

  Camera(const Rect& inViewport);
  virtual ~Camera() {};
  
  Rect& viewport(const Rect& inViewport);
  Rect& viewport();

  Vec2 depth();
  void depth(const Vec2& inDepth);

  Matrix& viewMatrix();
  Matrix& projectionMatrix();
};
}

#endif
