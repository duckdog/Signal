//
//  TiltleScene.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/19.
//
//

#pragma once
#include "../Mgr/SceneMgr.hpp"

class GameObject;


class TitleScene : public SceneMgr
{
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    void  Update(float delta);
    CREATE_FUNC(TitleScene);
    //タッチ処理用
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    
    
private:
    std::vector<GameObject*> objectList_;
    const char* bgFilePath = "TitleBg.png";
    
};
