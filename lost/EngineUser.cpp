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

namespace lost 
{

MeshPtr coloredQuad;
MeshPtr texturedQuad;
ShaderProgramPtr colorShader;
ShaderProgramPtr textureShader;
CameraPtr cam;
TexturePtr ringTexture;
FontPtr font;
TextMeshPtr rt1;
TextMeshPtr rt2;

void Engine::startup()
{
  ResourceBundle mainBundle;
  colorShader = mainBundle.loadShader("resources/glsl/color");
  textureShader = mainBundle.loadShader("resources/glsl/texture");
	ringTexture = mainBundle.loadTexture("resources/rings.png");
  cam = Camera2D::create(Rect(0,0,1024,768));
  
  DataPtr fontData = mainBundle.load("resources/fonts/vera/Vera.ttf");
  font.reset(new TruetypeFont(fontData, 18));

  rt2.reset(new TextMesh());
  TextBuffer tb;
  tb.font(font);
  tb.width(200);
  tb.breakMode(BREAKMODE_WORD);
  tb.text("This here is a relatively long text, that's hopefully gonna be rendered in multiple lines.");
  tb.setAlign(2);
  tb.reset();
  tb.renderAllPhysicalLines(rt2);
  rt2->material->blendPremultiplied();
  rt2->material->shader = textureShader;
  rt2->transform = MatrixTranslation(Vec3(200,200,0));

  rt1 = render("I vant to drink your blood!", font, false);
  rt1->material->shader = textureShader;
  rt1->material->blendPremultiplied();
  rt1->transform = MatrixTranslation(Vec3(50,50,0));



  coloredQuad = Quad::create(Rect(0,0,50,50));
  coloredQuad->material->shader = colorShader;
  coloredQuad->material->color = redColor;

  texturedQuad = Quad::create(ringTexture);
  texturedQuad->material->shader = textureShader;
  texturedQuad->material->color = whiteColor;
  texturedQuad->material->blendNormal();
  texturedQuad->transform = MatrixTranslation(Vec3(100,100,0));

}

void Engine::update()
{
  glContext->clearColor(blackColor);
  glContext->camera(cam);
  glContext->clear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
  glContext->draw(coloredQuad);
  glContext->draw(texturedQuad);
  glContext->draw(rt1);
  glContext->draw(rt2);
}

void Engine::shutdown()
{
}

}

