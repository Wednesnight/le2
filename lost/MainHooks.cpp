#include "MainHooks.h"
#include "Log.h"
#include "lost/Bundle.h"
#include "lost/Bitmap.h"
#include "lost/Texture.h"

namespace lost 
{

void leStartup() 
{
  ResourceBundle rb;
  DataPtr data = rb.load("rings.png");
  BitmapPtr bmp = Bitmap::create(data);
	TexturePtr tex = Texture::create(bmp);
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

