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

#include "lost/Uniform.h"

namespace lost
{

Uniform::Uniform()
{
  index = 0;
  glType = 0;
  size = 0;
  location = 0;
}

Uniform::Uniform(const string& inName, GLint inIndex, GLenum inGlType, GLint inSize, GLint loc)
: name(inName), index(inIndex), glType(inGlType), size(inSize), location(loc)
{
}

void Uniform::operator=(float v) { setFloat(v); }
void Uniform::operator=(const Color& inCol) { set(inCol); }
void Uniform::operator=(const Vec2& vec) { set(vec); }
void Uniform::operator=(const Vec3& vec) { set(vec); }
void Uniform::operator=(const Vec4& vec) { set(vec); }
void Uniform::operator=(GLint v) { setInt(v); }

void Uniform::setInt(GLint inVal)
{
  glUniform1i(location, inVal);GLASSERT;
}

void Uniform::setFloat(float inVal)
{
  glUniform1f(location, inVal);GLASSERT;
}

void Uniform::setBool(bool inVal)
{
  glUniform1f(location, inVal);GLASSERT;
}

void Uniform::set(const Color& inCol)
{
    switch(glType)
    {
      case GL_FLOAT_VEC3: glUniform3f(location, inCol.r(), inCol.g(), inCol.b());GLASSERT;break;
      case GL_FLOAT_VEC4: glUniform4f(location, inCol.r(), inCol.g(), inCol.b(), inCol.a());GLASSERT;break;
      default: ASSERT(false,"type mismatch for: '"+name+"' required: "+enum2string(glType)+" was 'Color'");
    }
}

void Uniform::set(const Vec4& vec)
{
    switch(glType)
    {
      case GL_FLOAT_VEC3: glUniform3f(location, vec.x, vec.y, vec.z);GLASSERT;break;
      case GL_FLOAT_VEC4: glUniform4f(location, vec.x, vec.y, vec.z, vec.w);GLASSERT;break;
      default: ASSERT(false, "type mismatch for: '"+name+"' required: "+enum2string(glType)+" was 'Vec4'");
    }
}

void Uniform::set(const Vec2& inVec)
{
    switch(glType)
    {
      case GL_FLOAT_VEC2: glUniform2f(location, inVec.x, inVec.y);GLASSERT;break;
      default: ASSERT(false, "type mismatch for: '"+name+"' required: "+enum2string(glType)+" was 'Vec2'");
    }
}

void Uniform::set(const Vec3& inVec)
{
    switch(glType)
    {
      case GL_FLOAT_VEC3: glUniform3f(location, inVec.x, inVec.y, inVec.z);GLASSERT;break;
      default: ASSERT(false, "type mismatch for: '"+name+"' required: "+enum2string(glType)+" was 'Vec3'");
    }
}

void Uniform::set(const Matrix& mat)
{
  switch(glType)
  {
    case GL_FLOAT_MAT4: glUniformMatrix4fv(location, 1, GL_FALSE, mat.m);GLASSERT;break;
    default: ASSERT(false, "type mismatch for: '"+name+"' required: "+enum2string(glType)+" was 'Matrix'");
  }
}

}
