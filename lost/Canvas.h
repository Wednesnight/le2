#ifndef CANVAS_H
#define CANVAS_H

#include "shared_ptr.h"
#include "Context.h"
#include "Mesh.h"
#include "Rect.h"
#include "Bundle.h"

#include <list>

using namespace lost;
using namespace std;

struct CanvasObject;
typedef shared_ptr<CanvasObject> CanvasObjectPtr;

struct Canvas;
typedef shared_ptr<Canvas> CanvasPtr;

struct CanvasObject {
private:
  MeshPtr mesh;
  std::list<CanvasObjectPtr> children;
public:
  bool isVisible;
  float x, y, xScale, yScale, rotation;
  
  CanvasObject();
  CanvasObject(const MeshPtr& mesh);

  void process(Context* context);
  virtual void render(Context* context);
  
  void insert(CanvasObjectPtr& child);
  void remove(CanvasObjectPtr& child);
};

struct Spritesheet : public CanvasObject {
  QuadPtr quad;
  unsigned int index;
  Spritesheet(const TexturePtr& texture, const vector<Rect>& rects);
  void render(Context* context);
};

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

  CanvasObjectPtr newText(const string& text, float x = .0f, float y = .0f,
                          float width = .0f, const string& font = "Vera.ttf",
                          int fontSize = 18, TextAlign align = ALIGN_LEFT,
                          CanvasObjectPtr parent = CanvasObjectPtr());
  
};

#endif
