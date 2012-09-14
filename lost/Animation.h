//
//  Animation.h
//  LostEngine2
//
//  Created by Timo Boll on 13.09.12.
//  Copyright (c) 2012 Tony Kostanjsek. All rights reserved.
//

#ifndef LostEngine2_Animation_h
#define LostEngine2_Animation_h

#include "lost/Quad.h"
#include "lost/Mesh.h"
#include "lost/Bundle.h"

namespace lost
{
    struct Animation;
    typedef shared_ptr<Animation> AnimationPtr;
    
    enum AnimationStates {
        NONE = 1,
        ONCE,
        LOOP,
        REWARD_ONCE,
        REWARD_LOOP,
        PINGPONG
    };
    
    struct Animation    {
    private:
        ResourceBundle m_mainBundle;
        MeshPtr m_quad;
        TexturePtr m_texture;
        ShaderProgramPtr m_shader;
        
        uint32_t m_frame;
        uint32_t m_maxFrameCountPerColumn;
        uint32_t m_maxFrameCountPerRow;
        uint32_t m_frameCount;
        AnimationStates m_animationState;
        double m_singleFrameTime;
        uint32_t m_frameWidth,m_frameHeight;

        double m_time;
        
        void setUVCoords(uint32_t _frame);
        
    public:
        Animation(const ResourceBundle &_mainBundle);
        ~Animation();
        
        //static Animation* instance();
        
        void load(std::string _textureSrc,uint32_t _frameWidth,uint32_t _frameHeight,uint32_t _frameCount);
        
        void play(AnimationStates _animationState,double _singleFrameTime);
        void pause();
        void update(double _frameTime);    
        
        const MeshPtr& getQuad() { return m_quad; }
    };
}

#endif