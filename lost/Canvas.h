#ifndef CANVAS_H
#define CANVAS_H

#include "shared_ptr.h"
#include "Context.h"
#include "Mesh.h"
#include "Rect.h"
#include "Bundle.h"

#include "CanvasObject.h"


using namespace lost;

struct Canvas;
typedef shared_ptr<Canvas> CanvasPtr;



struct Canvas : public CanvasObject {

private:
  ResourceBundle bundle;

  ShaderProgramPtr colorShader;
  ShaderProgramPtr textureShader;
  
  Color defaultColor;

  Canvas();

public:
  static CanvasPtr create() {
    return CanvasPtr(new Canvas());
  }

  CanvasObjectPtr newRect(float x, float y, float width, float height,
                          CanvasObjectPtr parent = CanvasObjectPtr());
  
  CanvasObjectPtr newImage(const string& path, float x = .0f, float y = .0f,
                           CanvasObjectPtr parent = CanvasObjectPtr());

  CanvasObjectPtr newImage(const TexturePtr& image, float x = .0f, float y = .0f,
                           CanvasObjectPtr parent = CanvasObjectPtr());

  CanvasObjectPtr newText(const string& text, float x = .0f, float y = .0f,
                          float width = .0f, const string& font = "Vera.ttf",
                          int fontSize = 18, TextAlign align = ALIGN_LEFT,
                          CanvasObjectPtr parent = CanvasObjectPtr());
  
  CanvasObjectPtr newSky(const TexturePtr& image, float x = .0f, float y = .0f,
                          CanvasObjectPtr parent = CanvasObjectPtr());
};

#endif
