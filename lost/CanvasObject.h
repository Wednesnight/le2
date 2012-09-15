//
//  CanvasObject.h
//  LostEngine2
//
//  Created by Timo Boll on 15.09.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef LostEngine2_CanvasObject_h
#define LostEngine2_CanvasObject_h

#include "shared_ptr.h"
#include "Context.h"
#include "Mesh.h"
#include "Rect.h"
#include "Bundle.h"

using namespace lost;

struct CanvasObject;
typedef shared_ptr<CanvasObject> CanvasObjectPtr;

struct CanvasObject {
protected:
    MeshPtr mesh;
    vector<CanvasObjectPtr> children;
public:
    bool isVisible, isEnabled;
    float x, y, xScale, yScale, rotation;
    
    CanvasObject();
    CanvasObject(const MeshPtr& mesh);
    
    virtual void process(Context* context, double deltaTime, Matrix _parentTransform = MatrixIdentity());
    virtual void render(Context* context);
    
    void insert(CanvasObjectPtr& child);
    void remove(CanvasObjectPtr& child);
    
    unsigned int childCount() {
        return children.size();
    }
    
    const CanvasObjectPtr& operator[](unsigned int index) {
        return children[index];
    }
    
};

struct Spritesheet : public CanvasObject {
    QuadPtr quad;
    unsigned int index;
    Spritesheet(const TexturePtr& texture, const vector<Rect>& rects);
    void render(Context* context);
};

#endif
