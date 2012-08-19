#include "MainHooks.h"
#include "Log.h"
#include "lost/Bundle.h"

namespace lost 
{

void leStartup() 
{
  ResourceBundle rb;
  DataPtr data = rb.load("test.jpg");
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

