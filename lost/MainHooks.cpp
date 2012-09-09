#include "MainHooks.h"
#include "Log.h"
#include "lost/Bundle.h"
#include "lost/Bitmap.h"
#include "lost/Texture.h"
#include "ShaderPreprocessor.h"

namespace lost 
{

void leStartup() 
{
  ResourceBundle rb;
  DataPtr data = rb.load("resources/rings.png");
  BitmapPtr bmp = Bitmap::create(data);
	TexturePtr tex = Texture::create(bmp);
  
  ShaderProgramPtr colorShader = loadShader(rb, "resources/glsl/color");
}

void leUpdate()
{
}

void leShutdown()
{
}

void leWindowResize(float w, float h)
{
}

}

