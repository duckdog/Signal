//
//  TouchParticle.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/31.
//
//

#pragma once
#include "ParticleEmitter.hpp"


class TouchParticle : public ParticleEmitter
{
public:
    TouchParticle();
    ~TouchParticle() = default;
    
    //タッチ専用パーティクル
    static ParticleEmitter* TouchParticleCreate(cocos2d::Vec2 pos,cocos2d::Vec2 scale = Vec2(0.04f,0.04f),
                                                cocos2d::Vec2 direc = Direction::upVec,
                                                float angle = 360,
                                                float lifeTime = 0.3f, int maxPartcle = 20,
                                                float speed    = 100, const char* spritePath = "smog.png");

private:

    static float speedMax;
    static float speedMin;

};
