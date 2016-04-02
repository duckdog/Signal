//
//  Particle.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/26.
//
//


#include "GameObject.hpp"

class Particle: public GameObject,create_func<Particle>
{
public:
    
    bool init(cocos2d::Vec2    pos,   cocos2d::Vec2 scale,
              cocos2d::Sprite* sprite,cocos2d::Vec2 direc,
              float lifeTime = 1.0f,
              float speed = 3.0f,
              cocos2d::Vec2 ancPos = AncPoint::AnchorCenter,
              ObjectTag tag = ObjectTag::Null);

    void Update(float delta);
    void SetGravity(bool setGravity, float initialVelocity = 1,float acceleration = 5);
    
    inline void SetSpeed(float speed){speed_ = speed;}
    inline void SetLifeTime(float lifeTime){lifeTime_ = lifeTime;}
    inline void SetDirection(cocos2d::Vec2 direc){direction_ = direc;}

    
    using create_func::Create;

private:
    void AddGravitiy(cocos2d::Vec2& pos,float time,float initialVelocity = 0, float acceleration = 1);
    
    
    float lifeTime_;
    float speed_;
    float count_;
    cocos2d::Vec2 direction_;
    
    bool setGravity_;
    float initialVelocity_;
    float acceleration_;

};