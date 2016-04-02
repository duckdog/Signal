//
//  ColorBlockButton.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/04/01.
//
//

#pragma once
#include "GameObject.hpp"

class ColorBlock : public GameObject,create_func<ColorBlock>
{
    
public:
    
    enum Type
    {
        None   = -1,
        Blue   = 0,
        Yellow = 1,
        Red    = 2,
        
        Last = 3,
        
    };

    ColorBlock();
    using create_func::Create;
    
    virtual bool  init(cocos2d::Vec2 pos, cocos2d::Vec2 scale,
                       Type type,
                       cocos2d::Vec2 ancPos     = AncPoint::AnchorCenter,
                       const char*   spritePath = "button.png",
                       ObjectTag     tag        = ObjectTag::Button);
    
    void Update(float delta);
    
    //タッチ処理用
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event){};
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){};
    
private:
    
    Type type_;
    float reLifeTimer_;
    const float reMakeTime_ = 0.4f;
    
    const cocos2d::Vec2 particleScale_ = Vec2(0.1f,0.1f);
    const float particletLifeTime_ = 0.45f;
    const float particletSpeed_ = 200;
    const int   particletAngle_ = 300;
    const int   particleMax_ = 20;


};
