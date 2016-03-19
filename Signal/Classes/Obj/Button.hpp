//
//  Button.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/16.
//
//

#pragma once
#include "GameObject.hpp"

class Button : public GameObject,create_func<Button>
{
    
public:
    
    Button();
    ~Button();
    virtual bool init(cocos2d::Vec2 pos,cocos2d::Vec2 scale,
                      cocos2d::Vec2 ancPos,ObjectTag tag);
    virtual void Update(float delta);
    bool IsTouch(){return isTouch_;};
    using create_func::Create;
    
    
protected:
    
    //タッチ処理用
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    const char* buttonSpritePath = "button.png";
    
    bool isTouch_;

    
};


/*
 Button* Button::Create(cocos2d::Vec2 pos, cocos2d::Vec2 scale,
 cocos2d::Vec2 ancPos, GameObject::ObjectTag tag)
 {
 
 //生成
 Button* pRet = new Button();
 
 //メモリ確保、初期化の可否チェック
 if(pRet && pRet->init(pos,scale,ancPos,tag)){
 //cocos2d::Refに定義されてるリファレンスカウンタ適用のautorelease関数適用
 pRet->autorelease();
 return pRet;
 }
 else{
 //失敗した場合NULL返却
 delete  pRet;
 pRet = NULL;
 return NULL;
 }
 }
 */
