//
//  Button.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/16.
//
//

#pragma once
#include "GameObject.hpp"
#include "SceneMgr.hpp"
#include <functional>



class Button : public GameObject,create_func<Button>
{

    
public:
    
    Button();
    ~Button();
    
    //タッチ処理用
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    //通常初期化
    virtual bool init(cocos2d::Vec2 pos, cocos2d::Vec2 scale,
                      cocos2d::Vec2 ancPos     = AncPoint::AnchorCenter,
                      const char*   spritePath = "button.png",
                      ObjectTag     tag        = ObjectTag::Button);
       
    virtual void Update(float delta);
    bool IsTouch(){return isTouch_;};
    using create_func::Create;
    
    static void SetTouchEndedFunc(std::function<void()> func){ touchEndedFuncs_.push_back(func);}
    static void SetTouchEndedFuncs( std::vector<std::function<void()>>& funcs){ touchEndedFuncs_ = std::move(funcs);}
    
protected:

    static std::vector<std::function<void()>> touchBeganFuncs_;
    static std::vector<std::function<void()>> touchMovedFuncs_;
    static std::vector<std::function<void()>> touchEndedFuncs_;
    
    
    bool isTouch_;

    
};



