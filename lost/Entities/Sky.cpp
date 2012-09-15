//
//  Sky.cpp
//  LostEngine2
//
//  Created by Timo Boll on 15.09.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <math.h>

#include "lost/Entities/Sky.h"


void Sky::process(Context* context, double deltaTime, Matrix _parentTransform) {    
    if (isEnabled) {
        
        Matrix m = MatrixTranslation(Vec3(x, y, 0)) * MatrixScaling(Vec3(xScale, yScale, 1)) * MatrixRotation(Vec3(0, 0, rotation)) * _parentTransform;
        if (mesh) {
            mesh->transform = m;
        }
        
        int32_t num = 0;
        for (std::list<CanvasObjectPtr>::iterator idx = children.begin(); idx != children.end(); ++idx) {
            
            (*idx)->x = ((num*250)%300 - 150) + sinf((float)deltaTime) * 400;
            (*idx)->y = ((num*30)%100 - 50);
                        
            (*idx)->process(context,deltaTime,m);
        }
    }
}