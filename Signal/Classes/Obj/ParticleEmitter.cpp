//
//  ParticleEmitter.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/26.
//
//

#include "ParticleEmitter.hpp"
#include "Particle.hpp"
#include "Random.hpp"

std::vector<std::function<void()>> ParticleEmitter::touchBeganFuncs_;
std::vector<std::function<void()>> ParticleEmitter::touchMovedFuncs_;
std::vector<std::function<void()>> ParticleEmitter::touchEndedFuncs_;


ParticleEmitter::ParticleEmitter()
:GameObject()
{
    
}

ParticleEmitter::~ParticleEmitter()
{
    
}

//生成
bool ParticleEmitter::init(cocos2d::Vec2 pos,cocos2d::Vec2 scale,
                           cocos2d::Vec2 direc,
                           float angle,
                           float lifeTime,int maxPartcle,
                           float speed, const char* spritePath)
{
    
    if(!cocos2d::Sprite::init())
    {
        return false;
    }
    
    
    

    //パーティクル生成
    //方向を計算、取得
    auto direcs = GetFanDirecs(direc,angle,maxPartcle);
    for(int i = 0; i < maxPartcle; i++)
    {
        auto particle = Sprite::create(spritePath);
        particleVector_.push_back(Particle::Create(pos,scale,
                                                   particle,direcs[i],
                                                   lifeTime,speed));
        
        this->addChild(particleVector_[i]);
    }
    
    //Updateを登録.
    this->schedule(schedule_selector(ParticleEmitter::Update));
    
    return true;
}



void ParticleEmitter::Update(float delta)
{
    //位置とスケールを更新　出現させたパーティクルがなくなったら、自動でremove
    if(this->getChildren().size() == 0){this->removeFromParentAndCleanup(true);}
}


//タッチシステムのデフォルト実装.
bool ParticleEmitter::onTouchBegan(Touch* touch, Event* event) {
    
    return true;
}
void ParticleEmitter::onTouchMoved(Touch* touch, Event* event) {}

//ボタン上で、指（カーソル）をはなしたら,真を返す.
void ParticleEmitter::onTouchEnded(Touch* touch, Event* event) {

    auto location = touch->getLocation();
    
}

