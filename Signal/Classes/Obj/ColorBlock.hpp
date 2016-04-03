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
    
    //ブロックのカラータイプ
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
    
    cocos2d::Sprite* GetMask(){return colorMask_;}
    void BreakBlock();
    //タッチ処理用
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event){};
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){};
    
private:
    
    //タイプにあわせてマスクの色を変える
    void SetColor(int typeNumber,cocos2d::Sprite* sprite);
    
    //追加情報
    Type type_;
    const char* colorMaskPath_ = "buttonWhiteMask.png";
    cocos2d::Sprite* colorMask_;
    
    
    //タッチして壊れてから再表示までの時間
    float reLifeTimer_;
    const float reMakeTime_ = 0.4f;
    
    //壊れる時のぱーてぃくるエフェクトの情報
    const cocos2d::Vec2 particleScale_ = Vec2(0.1f,0.1f);
    const float particletLifeTime_ = 0.45f;
    const float particletSpeed_ = 200;
    const int   particletAngle_ = 300;
    const int   particleMax_ = 20;


};
