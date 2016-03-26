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
    using create_func::Create;

private:
    
    float lifeTime_;
    float speed_;
    cocos2d::Vec2 direction_;
    


};