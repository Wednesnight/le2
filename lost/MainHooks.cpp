#include "MainHooks.h"
#include "Log.h"
#include "lost/Bundle.h"
#include "lost/Bitmap.h"

namespace lost 
{

void leStartup() 
{
  ResourceBundle rb;
  DataPtr data = rb.load("rings.png");
  Bitmap bmp(data);
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

