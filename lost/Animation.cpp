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
        
        m_animationState = NONE;
        m_time = 0.0;
        m_frame = 0;
    }
    
    Animation::~Animation() {
        m_texture.reset();
        m_shader.reset();
        m_quad.reset();        
    }
    
    void Animation::setUVCoords(uint32_t _frame) {
        
        uint32_t column = _frame%m_maxFrameCountPerColumn;
        uint32_t row = _frame/m_maxFrameCountPerColumn;
        
        float rowWidth = (float)m_frameWidth/(float)m_texture->dataWidth;
        float lineHeight = (float)m_frameHeight/(float)m_texture->dataHeight;
        
        float offsetX = (float)column/(float)m_maxFrameCountPerColumn;
        float offsetY = (float)row/(float)m_maxFrameCountPerRow;
        
        m_quad->setTexCoord(3, Vec2( offsetX, offsetY));
        m_quad->setTexCoord(2, Vec2( offsetX + rowWidth, offsetY));
        m_quad->setTexCoord(1, Vec2( offsetX + rowWidth, (offsetY + lineHeight)));
        m_quad->setTexCoord(0, Vec2( offsetX, (offsetY + lineHeight)));
    }
    
    void Animation::load(std::string _textureSrc,uint32_t _frameWidth,uint32_t _frameHeight,uint32_t _frameCount) {
        
        m_texture = m_mainBundle.loadTexture(_textureSrc);
        m_shader = m_mainBundle.loadShader("resources/glsl/texture");
        
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
    
    void Animation::play(AnimationStates _animationState,double _singleFrameTime) {
        m_animationState = _animationState;
        m_singleFrameTime = _singleFrameTime;
    }
    
    void Animation::pause() {
        m_animationState = NONE;
    }
    
    void Animation::update(double _frameTime) {
        
        if (m_animationState == LOOP) {
            if (m_time >= m_singleFrameTime) {
                m_frame += 1;
                if (m_frame >= m_frameCount) { m_frame = 0; }
                setUVCoords(m_frame);
                m_time = 0.0;
            }
        }
        
        m_time += _frameTime;
    }    
}