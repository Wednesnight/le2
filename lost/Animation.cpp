//
//  Animation.cpp
//  LostEngine2
//
//  Created by Timo Boll on 13.09.12.
//  Copyright (c) 2012 Tony Kostanjsek. All rights reserved.
//

#include <iostream>
#include "lost/Animation.h"

namespace lost {
    
    Animation::Animation(const ResourceBundle &_mainBundle) {
        m_mainBundle = _mainBundle;
        
        m_animationPlayState = AP_NONE;
        m_animationState = A_NONE;
        m_time = 0.0;
        m_frame = 0;
    }
    
    Animation::~Animation() {
        m_texture.reset();
        m_shader.reset();
        m_quad.reset();        
    }
    
    void Animation::setUVCoords(int32_t _frame) {
        
        int32_t column = _frame%m_maxFrameCountPerColumn;
        int32_t row = _frame/m_maxFrameCountPerColumn;
        
        float rowWidth = (float)m_frameWidth/(float)m_texture->dataWidth;
        float lineHeight = (float)m_frameHeight/(float)m_texture->dataHeight;
        
        float offsetX = (float)column/(float)m_maxFrameCountPerColumn;
        float offsetY = (float)row/(float)m_maxFrameCountPerRow;
        
        m_quad->setTexCoord(3, Vec2( offsetX, offsetY));
        m_quad->setTexCoord(2, Vec2( offsetX + rowWidth, offsetY));
        m_quad->setTexCoord(1, Vec2( offsetX + rowWidth, (offsetY + lineHeight)));
        m_quad->setTexCoord(0, Vec2( offsetX, (offsetY + lineHeight)));
    }
    
    void Animation::load(std::string _textureSrc,int32_t _frameWidth,int32_t _frameHeight,int32_t _frameCount) {
        
        m_texture = m_mainBundle.loadTexture(_textureSrc);
        m_shader = m_mainBundle.loadShader("texture");
        
        m_frameWidth = _frameWidth;
        m_frameHeight = _frameHeight;
        m_maxFrameCountPerColumn = m_texture->dataWidth/m_frameWidth;
        m_maxFrameCountPerRow = m_texture->dataHeight/m_frameHeight;
        m_frameCount = _frameCount;
        
        Rect rect(0, 0, m_frameWidth, m_frameHeight);
        m_quad = Quad::create(m_texture,rect,true);
        m_quad->material->shader = m_shader;
        m_quad->material->color = whiteColor;
        m_quad->material->blendNormal();
        
        
        setUVCoords(0);     
    }
    
    void Animation::addAnimation(std::string _key, int32_t _start, int32_t _end) {
        m_animations[_key] = new AnimationRange(_start,_end);
    }
    
    void Animation::showFrame(int32_t _frame) {
        setUVCoords(_frame);
        m_animationPlayState = AP_NONE;
    }
    
    void Animation::play(std::string _animationKey,AnimationPlayStates _animationPlayState,double _singleFrameTime,bool _reset) {
        m_animationPlayState = _animationPlayState;
        m_singleFrameTime = _singleFrameTime;
        
        m_startFrame = m_animations[_animationKey]->start;
        m_endFrame = m_animations[_animationKey]->end;
        
        if (m_animationPlayState == AP_ONCE || m_animationPlayState == AP_LOOP) {
            m_animationState = A_FORWARD;
            if (_reset) { m_frame = m_startFrame; }
        }else{
            m_animationState = A_REWARD;
            if (_reset) { m_frame = m_endFrame; }
        }
    }
    
    void Animation::pause() {
        m_animationPlayState = AP_NONE;
    }
    
    void Animation::update(double _frameTime) {
        
        if (m_animationState != A_NONE) {
            if (m_time >= m_singleFrameTime) {
                if (m_animationPlayState == AP_ONCE) {
                    if (m_frame >= m_endFrame) { 
                        m_animationState = A_NONE;
                        m_frame --;
                    } else {
                        setUVCoords(m_frame);
                        m_frame ++;
                    }
                    m_time = 0.0;
                    
                }else if (m_animationPlayState == AP_LOOP) { 
                    if (m_frame >= m_endFrame) { 
                        m_frame = m_startFrame; }
                    else { 
                        setUVCoords(m_frame);
                        m_frame ++;
                    }
                    m_time = 0.0;                  
                
                }else if (m_animationPlayState == AP_REWARD_ONCE) {
                    if (m_frame <= m_startFrame) { 
                        m_animationState = A_NONE;
                    } else {
                        setUVCoords(m_frame);
                        m_frame --;
                    }
                    m_time = 0.0;
                }else if (m_animationPlayState == AP_REWARD_LOOP) {
                    if (m_frame < m_startFrame) { 
                        m_frame = m_endFrame-1; 
                    } else {
                        setUVCoords(m_frame);
                        m_frame --;                                            
                    }
                    m_time = 0.0;    
                }
            }
            m_time += _frameTime;
        }
    }    
}