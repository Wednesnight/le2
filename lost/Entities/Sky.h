//
//  Sky.h
//  LostEngine2
//
//  Created by Timo Boll on 15.09.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef LostEngine2_Sky_h
#define LostEngine2_Sky_h

#include "lost/Canvas.h"
#include "Context.h"
#include "lost/Matrix.h"

#include <vector>
#include "lost/Vec2.h"
namespace lost
{
    struct Sky;
    typedef shared_ptr<Sky> SkyPtr;
    
    struct Sky : public CanvasObject {
    public:
        
        Sky() : CanvasObject() {}
        Sky(const MeshPtr& mesh) : CanvasObject(mesh) {}
        
        void process(Context* context, double deltaTime,Matrix _parentTransform = MatrixIdentity());
    };
}

#endif
