#include "Canvas.h"
#include "Quad.h"
#include "TruetypeFont.h"
#include "TextRender.h"
#include "TextMesh.h"
#include "TextBuffer.h"
#include "Matrix.h"

CanvasObject::CanvasObject() {
  isVisible = true;
  isEnabled = true;
  x = 0;
  y = 0;
  xScale = 1;
  yScale = 1;
  rotation = 0;
}

CanvasObject::CanvasObject(const MeshPtr& mesh)
: mesh(mesh) {
  isVisible = true;
  isEnabled = true;
  x = 0;
  y = 0;
  xScale = 1;
  yScale = 1;
  rotation = 0;
}

void CanvasObject::process(Context* context,Matrix _parentTransform) {
  if (isEnabled) {
    Matrix m = MatrixTranslation(Vec3(x, y, 0)) * MatrixScaling(Vec3(xScale, yScale, 1)) * MatrixRotation(Vec3(0, 0, rotation)) * _parentTransform;
    if (mesh) {
        mesh->transform = m;
    }
      
    for (vector<CanvasObjectPtr>::iterator idx = children.begin(); idx != children.end(); ++idx) {
      (*idx)->process(context,m);
    }
  }
}

void CanvasObject::render(Context* context) {
  if (isVisible) {
  
    if (mesh) { context->draw(mesh); }
    
    for (vector<CanvasObjectPtr>::iterator idx = children.begin(); idx != children.end(); ++idx) {
      (*idx)->render(context);
    }  
  }
}

void CanvasObject::insert(CanvasObjectPtr& child) {
  children.push_back(child);
}

void CanvasObject::remove(CanvasObjectPtr& child) {
  for (vector<CanvasObjectPtr>::iterator idx = children.begin(); idx != children.end(); ++idx) {
    if (child == *idx) {
      children.erase(idx);
      break;
    }
  }
}

Canvas::Canvas()
{
  colorShader = bundle.loadShader("color");
  textureShader = bundle.loadShader("texture");
  defaultColor = whiteColor;
}

CanvasObjectPtr Canvas::newRect(float x, float y, float width, float height, CanvasObjectPtr parent) {
  MeshPtr mesh = Quad::create(Rect(0, 0, width, height));
  mesh->material->shader = colorShader;
  mesh->material->color = defaultColor;
  CanvasObjectPtr result(new CanvasObject(mesh));
  result->x = x;
  result->y = y;
  if (parent) {
    parent->insert(result);
  }
  else {
    insert(result);
  }
  return result;
}

CanvasObjectPtr Canvas::newImage(const string& path, float x, float y, CanvasObjectPtr parent) {
	return newImage(bundle.loadTexture(path), x, y, parent);
}

CanvasObjectPtr Canvas::newImage(const TexturePtr& image, float x, float y, CanvasObjectPtr parent) {
  MeshPtr texturedQuad = Quad::create(image);
  texturedQuad->material->shader = textureShader;
  texturedQuad->material->color = defaultColor;
  texturedQuad->material->blendNormal();
  CanvasObjectPtr result(new CanvasObject(texturedQuad));
  result->x = x;
  result->y = y;
  if (parent) {
    parent->insert(result);
  }
  else {
    insert(result);
  }
  return result;
}

CanvasObjectPtr Canvas::newText(const string& text, float x, float y, float width,
                                const string& font, int fontSize, TextAlign align,
                                CanvasObjectPtr parent) {
  TruetypeFontPtr ttf(new TruetypeFont(bundle.load(font), fontSize));
  TextMeshPtr mesh;
  if (width > 0) {
    mesh.reset(new TextMesh());
    TextBuffer tb;
    tb.font(ttf);
    tb.width(width);
    tb.breakMode(BREAKMODE_WORD);
    tb.text(text);
    tb.setAlign(align);
    tb.reset();
    tb.renderAllPhysicalLines(mesh);
  }
  else {
    mesh = lost::render(text, ttf, false);
  }
  mesh->material->shader = textureShader;
  mesh->material->blendPremultiplied();
  CanvasObjectPtr result(new CanvasObject(mesh));
  result->x = x;
  result->y = y;
  if (parent) {
    parent->insert(result);
  }
  else {
    insert(result);
  }
  return result;
}