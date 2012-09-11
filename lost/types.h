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

#ifndef LOST_TYPES_H
#define LOST_TYPES_H

#include <stdint.h>
#include <string>
#include "lost/shared_ptr.h"

namespace lost
{
  typedef int8_t s8;
  typedef int16_t s16;
  typedef int32_t s32;
  typedef int64_t s64;

  typedef uint8_t u8;
  typedef uint16_t u16;
  typedef uint32_t u32;
  typedef uint64_t u64;
  
  typedef float f32;
  typedef double f64;

  typedef uint8_t                         utf8_char;
  typedef std::basic_string<utf8_char>    utf8_string;

  typedef uint16_t                        utf16_char;
  typedef std::basic_string<utf16_char>   utf16_string;

  typedef uint32_t                        utf32_char;
  typedef std::basic_string<utf32_char>   utf32_string;

  #define LE_SP(structname) struct structname;typedef shared_ptr<structname> structname##Ptr;
  
  LE_SP(VertexShader);
  LE_SP(UniformBlock);
  LE_SP(Texture);
  LE_SP(ShaderProgram);
  LE_SP(Shader);
  LE_SP(Mesh);
  LE_SP(Material);
  LE_SP(HostBuffer);
  LE_SP(HybridBuffer);
  LE_SP(HybridIndexBuffer);
  LE_SP(HybridVertexBuffer);
  LE_SP(Bitmap);
  LE_SP(Buffer);
  LE_SP(Camera);
  LE_SP(Camera2D);
  LE_SP(Camera3D);
  LE_SP(Data);
  LE_SP(FragmentShader);
  LE_SP(Font);
  LE_SP(Glyph);
  LE_SP(TruetypeFont);
  LE_SP(TextMesh);
  LE_SP(Quad);
}

#endif
