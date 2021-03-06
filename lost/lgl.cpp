#include "lost/lgl.h"
#include <sstream>
#include "lost/Log.h"

namespace lost
{

  string getGlErrorAsString(GLenum err)
  {
    // FIXME: we need a cleaner way to handle this, maybe move error handling/debugging to a dedicated header
    #if TARGET_OPENGL_ES
      // there are only a handful of error codes in OpenGL ES, so we switch them by hand
      string result;
      switch(err)
      {
        case GL_NO_ERROR:result="GL_NO_ERROR";break;
        case GL_INVALID_ENUM:result="GL_INVALID_ENUM";break;
        case GL_INVALID_VALUE:result="GL_INVALID_VALUE";break;
        case GL_INVALID_OPERATION:result="GL_INVALID_OPERATION";break;
//        case GL_STACK_OVERFLOW:result="GL_STACK_OVERFLOW";break;
//        case GL_STACK_UNDERFLOW:result="GL_STACK_UNDERFLOW";break;
        case GL_OUT_OF_MEMORY:result="GL_OUT_OF_MEMORY";break;
//        case GL_INVALID_FRAMEBUFFER_OPERATION_OES:result="GL_INVALID_FRAMEBUFFER_OPERATION_OES";break;
        default:
          std::ostringstream os;
          os << "error 0x" << std::hex << err;
          result = os.str();
      }
      return result;
    #else
      const char* buf = reinterpret_cast<const char*>(gluErrorString(err));
      if(buf)
        return string(buf);
      else
      {
        // null pointer most probably means some extension produced an error that standard gluErrorString doesn't know
        // so we just output a hex number
        std::ostringstream os;
        os << "error 0x" << std::hex <<  err;
        return os.str().c_str();
      }
    #endif
  }

    #define enum2string_helper(glenum) case glenum: return #glenum;break;

    string enum2string(GLenum inVal)
    {
      switch(inVal)
      {
        enum2string_helper(GL_FLOAT)
        enum2string_helper(GL_FLOAT_VEC2)
        enum2string_helper(GL_FLOAT_VEC3)
        enum2string_helper(GL_FLOAT_VEC4)
        enum2string_helper(GL_INT)
        enum2string_helper(GL_INT_VEC2)
        enum2string_helper(GL_INT_VEC3)
        enum2string_helper(GL_INT_VEC4)
        enum2string_helper(GL_BOOL)
        enum2string_helper(GL_BOOL_VEC2)
        enum2string_helper(GL_BOOL_VEC3)
        enum2string_helper(GL_BOOL_VEC4)
        enum2string_helper(GL_FLOAT_MAT2)
        enum2string_helper(GL_FLOAT_MAT3)
        enum2string_helper(GL_FLOAT_MAT4)
#if TARGET_OPENGL
        enum2string_helper(GL_FLOAT_MAT2x3)
        enum2string_helper(GL_FLOAT_MAT2x4)
        enum2string_helper(GL_FLOAT_MAT3x2)
        enum2string_helper(GL_FLOAT_MAT3x4)
        enum2string_helper(GL_FLOAT_MAT4x2)
        enum2string_helper(GL_FLOAT_MAT4x3)
        enum2string_helper(GL_SAMPLER_1D)
        enum2string_helper(GL_SAMPLER_3D)
        enum2string_helper(GL_SAMPLER_1D_SHADOW)
        enum2string_helper(GL_SAMPLER_2D_SHADOW)
        enum2string_helper(GL_FRAMEBUFFER_COMPLETE_EXT)
        enum2string_helper(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT)
        enum2string_helper(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT)
        enum2string_helper(GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT)
        enum2string_helper(GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT)
        enum2string_helper(GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT)
        enum2string_helper(GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT)
        enum2string_helper(GL_FRAMEBUFFER_UNSUPPORTED_EXT)
#endif
        enum2string_helper(GL_SAMPLER_2D)
        enum2string_helper(GL_SAMPLER_CUBE)

        default:
            ASSERT(false, "enum2string: don't know enum: " << inVal);
        return "???";  // should never be reached due to assert in default:, but compiler complained
      }
    }

}