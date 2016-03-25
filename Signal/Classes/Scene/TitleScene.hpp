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
    CREATE_FUNC(TitleScene);
    
    
    
private:
    std::vector<GameObject*> objectList_;
    const char* bgFilePath = "TitleBg.png";
    
};
