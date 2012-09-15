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
#include "lost/Animation.h"

namespace lost 
{

  CameraPtr camPlayer1;
  CameraPtr camPlayer2;
  
  CanvasPtr canvas;
  CanvasObjectPtr coloredQuad;
  CanvasObjectPtr texturedQuad;
  CanvasObjectPtr rt1;
  CanvasObjectPtr rt2;
    
  ResourceBundle mainBundle;
  AnimationPtr anim;
    
  QuadPtr crazyQuad;
  TexturePtr crazyQuadTexture;  

  void Engine::startup()
  {
    camPlayer1 = Camera2D::create(Rect(0,0,1024,384));
    camPlayer2 = Camera2D::create(Rect(0,384,1024,384));
    camPlayer2->projectionMatrix() = MatrixRotZ(180) * camPlayer2->projectionMatrix();
    
    canvas = Canvas::create();

    rt2 = canvas->newText("This here is a relatively long text, that's hopefully gonna be rendered in multiple lines AND right aligned!",
                          300, 300, 200, "Vera.ttf", 28, ALIGN_RIGHT);
    rt2->rotation = -15;
//    rt2->xScale = 2;
//    rt2->yScale = 2;

    rt1 = canvas->newText("I vant to drink your blood!", 50, 50);

    coloredQuad = canvas->newRect(25, 100, 50, 50);

    texturedQuad = canvas->newImage("rings.png", 100, 100);

    
      
    anim.reset(new Animation(mainBundle));
    anim->load("greenman2_0.png",64,64,15);
      
    anim->addAnimation("default", 0, 15);
    anim->addAnimation("idle", 0, 5);
      
    anim->play("default",AP_LOOP, 0.05,true);
      
    //anim->showFrame(4);
      
    anim->getQuad()->transform = MatrixTranslation(Vec3(30,30,0));
      
      vector<Rect> rects;
      Rect rect1(0,0,64,64);
      rects.push_back(rect1);
      
      Rect rect2(0,0,64,64);
      rects.push_back(rect2);
      
      
      vector<Rect> pixelCoords;
      Rect pc1(0,0,64,64);
      pixelCoords.push_back(pc1);
      
      Rect pc2(128,128,64,64);
      pixelCoords.push_back(pc2);
      
      crazyQuadTexture = mainBundle.loadTexture("greenman2_0.png");
      crazyQuad = Quad::create(rects,crazyQuadTexture,pixelCoords);
      crazyQuad->material->shader = mainBundle.loadShader("texture");
      crazyQuad->material->color = whiteColor;
      crazyQuad->material->blendNormal();
      crazyQuad->transform = MatrixTranslation(Vec3(130,130,0));
      
  }

  long timeElapsed = 0;

  void Engine::update(long deltaFrameTime)
  {
    glContext->clearColor(redColor);
    
    //First Camera
    glContext->camera(camPlayer1);
      
    glContext->clear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    timeElapsed += deltaFrameTime;
    if (timeElapsed >= 500) {
      timeElapsed = 0;
      coloredQuad->isVisible = !coloredQuad->isVisible;
    }
    canvas->process(glContext);
    
    //Second Camera
    glContext->camera(camPlayer2);
    
    anim->update((double)deltaFrameTime/1000.0);
      
    glContext->draw(anim->getQuad());   
    
    crazyQuad->createIndices(0);
    crazyQuad->transform = MatrixTranslation(Vec3(130,130,0));
    glContext->draw(crazyQuad);   
    crazyQuad->createIndices(1);
    crazyQuad->transform = MatrixTranslation(Vec3(194,130,0));
    glContext->draw(crazyQuad);   
  }

  void Engine::shutdown()
  {
  }

}

