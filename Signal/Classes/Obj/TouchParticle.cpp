//
//  TouchParticle.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/31.
//
//

#include "TouchParticle.hpp"
#include "Random.hpp"
#include "Particle.hpp"


float TouchParticle::speedMax =  0.5f;
float TouchParticle::speedMin = -0.5f;

TouchParticle::TouchParticle()
:ParticleEmitter()
{
    
}



ParticleEmitter* TouchParticle::TouchParticleCreate(cocos2d::Vec2 pos,cocos2d::Vec2 scale,
                                                      cocos2d::Vec2 direc,
                                                      float angle,
                                                      float lifeTime, int maxPartcle,
                                                      float speed, const char* spritePath)
{
    auto instance = ParticleEmitter::Create(pos,scale,direc,angle,lifeTime,maxPartcle,speed,spritePath);
    
    
    
    for(auto particleCell : instance->GetPartcles())
    {
        
        //ランダムにパーティクルが散るようにする
        particleCell->SetSpeed(speed + Random::GetRandomRange(speed * speedMin,speed * speedMax));
        auto scaleTo = cocos2d::ScaleTo::create(lifeTime,0);
        auto spawn = cocos2d::Spawn::create(scaleTo, NULL);
        particleCell->::GameObject::GetSprite()->runAction(spawn);
        
        //重力追加
        particleCell->SetGravity(true);
        
    }
    return instance;
    
}
