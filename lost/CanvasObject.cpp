//
//  CanvasObject.cpp
//  LostEngine2
//
//  Created by Timo Boll on 15.09.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

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

void CanvasObject::process(Context* context, double deltaTime, Matrix _parentTransform) {
    if (isEnabled) {
        Matrix m = MatrixTranslation(Vec3(x, y, 0)) * MatrixScaling(Vec3(xScale, yScale, 1)) * MatrixRotation(Vec3(0, 0, rotation)) * _parentTransform;
        if (mesh) {
            mesh->transform = m;
        }
        
        for (vector<CanvasObjectPtr>::iterator idx = children.begin(); idx != children.end(); ++idx) {
            (*idx)->process(context,deltaTime,m);
        }
    }
}

void CanvasObject::render(Context* context) {
    if (isEnabled && isVisible) {
        
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
