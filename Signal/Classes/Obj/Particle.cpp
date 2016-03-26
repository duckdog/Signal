//
//  Particle.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/26.
//
//

#include "Particle.hpp"



bool Particle::init(cocos2d::Vec2    pos,     cocos2d::Vec2 scale,
                    cocos2d::Sprite* sprite,  cocos2d::Vec2 direc,
                    float            lifeTime,float         speed,
                    cocos2d::Vec2    ancPos,  ObjectTag     tag)
{
    
    if(!cocos2d::Sprite::init())
    {
        return false;
    }
    //オブジェクトの基本情報を初期化
    sprite_ = sprite;
    Particle::InitInfo(pos,scale,ancPos,sprite_,tag);
    direction_ = direc;
    speed_     = speed;
    lifeTime_  = lifeTime;
    this->addChild(sprite_);
    sprite_->setPosition(pos);
    
//    //lifetime分経過後、自殺
//    auto liveTime = cocos2d::DelayTime::create(lifeTime);
//    auto end      = cocos2d::RemoveSelf::create(true);
//    auto sequence = cocos2d::Sequence::create(liveTime,end, NULL);
//    sprite_->runAction(sequence);

    this->schedule(schedule_selector(Particle::Update));
    
    return true;
}


void Particle::Update(float delta)
{
    //与えられたベクトルに進む
    pos_ += direction_ * speed_ * delta;
    lifeTime_ -= 1 * delta;
    
    if(lifeTime_ < 0){this->removeFromParentAndCleanup(true);}
    else{sprite_->setPosition(pos_);}

}