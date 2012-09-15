#include "lost/Engine.h"
#include "lost/Log.h"
#include "lost/Bundle.h"
#include "lost/Bitmap.h"
#include "lost/Texture.h"
#include "lost/Context.h"
#include "lost/BufferLayout.h"
#include "lost/Mesh.h"
#include "lost/HybridIndexBuffer.h"
#include "lost/Camera2D.h"
#include "lost/TruetypeFont.h"
#include "lost/TextRender.h"
#include "lost/TextMesh.h"
#include "lost/Material.h"
#include "lost/TextBuffer.h"
#include "Canvas.h"

namespace lost 
{

  CameraPtr cam;
  CanvasPtr canvas;
  CanvasObjectPtr coloredQuad;
  CanvasObjectPtr texturedQuad;
  CanvasObjectPtr rt1;
  CanvasObjectPtr rt2;

  void Engine::startup()
  {
    cam = Camera2D::create(Rect(0,0,1024,768));
    canvas = Canvas::create();

    rt2 = canvas->newText("This here is a relatively long text, that's hopefully gonna be rendered in multiple lines AND right aligned!",
                          300, 300, 200, "Vera.ttf", 28, ALIGN_RIGHT);
    rt2->rotation = -15;
//    rt2->xScale = 2;
//    rt2->yScale = 2;

    rt1 = canvas->newText("I vant to drink your blood!", 50, 50);

    coloredQuad = canvas->newRect(25, 100, 50, 50);

    texturedQuad = canvas->newImage("rings.png", 100, 100);
  }

  long timeElapsed = 0;

  void Engine::update(long deltaFrameTime)
  {
    glContext->clearColor(blackColor);
    glContext->camera(cam);
    glContext->clear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    timeElapsed += deltaFrameTime;
    if (timeElapsed >= 500) {
      timeElapsed = 0;
      coloredQuad->isVisible = !coloredQuad->isVisible;
    }
    canvas->process(glContext);
  }

  void Engine::shutdown()
  {
  }

}

