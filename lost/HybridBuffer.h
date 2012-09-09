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

#ifndef LOST_HYBRIDBUFFER_H
#define LOST_HYBRIDBUFFER_H

#include "lost/Buffer.h"
#include "lost/HostBuffer.h"

namespace lost
{


/** base class for hybrid buffers that contain a hostbuffer as well as one or more
 *  gpu buffers.
 *  Only one type of gpu buffer can be managed by a hybrid buffer.
 */
struct HybridBuffer
{
  typedef map<UsageType, string> VertexAttributeMap;
  // we need to separate construction and initialisation because derived classes
  // have to perform more complex setup operations in constructor.
  HybridBuffer();               
  void init(GLenum inGpuBufferType,
            const BufferLayout& inLayout);               
  virtual ~HybridBuffer();
  
  void reset(uint32_t num);
  void reset(DataPtr data);
  
  void set(uint32_t idx, UsageType ut, uint8_t val);
  void set(uint32_t idx, UsageType ut, uint16_t val);
  void set(uint32_t idx, UsageType ut, uint32_t val);
  void set(uint32_t idx, UsageType ut, float val);
  void set(uint32_t idx, UsageType ut, const Vec2& val);
  void set(uint32_t idx, UsageType ut, const Vec3& val);
  void set(uint32_t idx, UsageType ut, const Vec4& val);
  void set(uint32_t idx, UsageType ut, const Color& val);  
  
  Vec2 getAsVec2(uint32_t idx, UsageType ut);
  Vec3 getAsVec3(uint32_t idx, UsageType ut);
  uint32_t getAsU32(uint32_t idx, UsageType ut);
  uint16_t getAsU16(uint32_t idx, UsageType ut);
  
  void upload();
  
  bool hasUsageType(UsageType ut);
  Buffer* bufferForUsageType(UsageType ut);  
  const AttributePointerConfig& pointerConfigForUsageType(UsageType ut);
  
  GLenum gpuBufferType; // should be either GL_ARRAY_BUFFER or GL_ELEMENT_ARRAY_BUFFER
  bool dirty;
  HostBufferPtr hostBuffer;
  BufferPtr     gpuBuffer;
  VertexAttributeMap vertexAttributeMap; // maps a usageType to a shader vertex attribute name
};


}

#endif
