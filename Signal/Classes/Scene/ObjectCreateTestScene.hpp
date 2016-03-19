//
//  ObjectCreateTestScene.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/16.
//
//

#pragma once
#include "../Mgr/SceneMgr.hpp"

class ObjectCreateTestScene : public SceneMgr
{
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    void Update(float delta);
    CREATE_FUNC(ObjectCreateTestScene);
    
private:
    
};

