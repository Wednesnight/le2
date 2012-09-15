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

#include <map>

namespace lost
{
    struct Animation;
    typedef shared_ptr<Animation> AnimationPtr;
    
    enum AnimationPlayStates {
        AP_NONE = 1,
        AP_ONCE,
        AP_LOOP,
        AP_REWARD_ONCE,
        AP_REWARD_LOOP
    };
    
    enum AnimationStates {
        A_NONE = 1,
        A_FORWARD,
        A_REWARD
    };
    
    struct Animation    {
    private:
        ResourceBundle m_mainBundle;
        MeshPtr m_quad;
        TexturePtr m_texture;
        ShaderProgramPtr m_shader;
        
        int32_t m_frame;
        double m_time;
        AnimationPlayStates m_animationPlayState;
        AnimationStates m_animationState;
        
        int32_t m_startFrame;
        int32_t m_endFrame;
        
        double m_singleFrameTime;
        int32_t m_frameWidth,m_frameHeight;

        int32_t m_frameCount;
        int32_t m_maxFrameCountPerColumn;
        int32_t m_maxFrameCountPerRow;
        
        struct AnimationRange {
            int32_t start;
            int32_t end;
            
            AnimationRange(int32_t _start,int32_t _end) {
                start = _start;
                end = _end;
            }
        };
        
        map<std::string,AnimationRange*> m_animations;
        
        void setUVCoords(int32_t _frame);
        
    public:
        Animation(const ResourceBundle &_mainBundle);
        ~Animation();
        
        void load(std::string _textureSrc,int32_t _frameWidth,int32_t _frameHeight,int32_t _frameCount);
        
        void addAnimation(std::string _key,int32_t _start, int32_t _end);
        
        void showFrame(int32_t _frame);
        
        void play(std::string _animationKey,AnimationPlayStates _animationPlayState,double _singleFrameTime,bool _reset);
        void pause();
        void update(double _frameTime);    
                
        const MeshPtr& getQuad() { return m_quad; }
    };
}

#endif