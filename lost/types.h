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
  
  struct VertexShader;
  typedef shared_ptr<VertexShader> VertexShaderPtr;

  struct UniformBlock;
  typedef shared_ptr<UniformBlock> UniformBlockPtr;

  struct Texture;
  typedef shared_ptr<Texture> TexturePtr;

  struct ShaderProgram;
  typedef shared_ptr<ShaderProgram> ShaderProgramPtr;
  
  struct Shader;
  typedef shared_ptr<Shader> ShaderPtr;
  
  struct Mesh;
  typedef shared_ptr<Mesh> MeshPtr;
  
  struct Material;
  typedef shared_ptr<Material> MaterialPtr;
  
  struct HostBuffer;
  typedef shared_ptr<HostBuffer> HostBufferPtr;

  struct HybridBuffer;
  typedef shared_ptr<HybridBuffer> HybridBufferPtr;

  struct HybridIndexBuffer;
  typedef shared_ptr<HybridIndexBuffer> HybridIndexBufferPtr;

  struct HybridVertexBuffer;
  typedef shared_ptr<HybridVertexBuffer> HybridVertexBufferPtr;

  struct Bitmap;
  typedef shared_ptr<Bitmap> BitmapPtr;

  struct Buffer;
  typedef shared_ptr<Buffer> BufferPtr;

  struct Camera;
  typedef shared_ptr<Camera> CameraPtr;

  struct Camera2D;
  typedef lost::shared_ptr<Camera2D> Camera2DPtr;

  struct Camera3D;
  typedef shared_ptr<Camera3D> Camera3DPtr;

  struct Data;
  typedef shared_ptr<Data> DataPtr;

  struct FragmentShader;
  typedef shared_ptr<FragmentShader> FragmentShaderPtr;

}

#endif
