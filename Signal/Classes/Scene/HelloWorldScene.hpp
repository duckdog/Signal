#pragma once

#include "../Mgr/SceneMgr.hpp"

class HelloWorldScene : public SceneMgr
{
public:

    static cocos2d::Scene* createScene();
    virtual bool init();

    CREATE_FUNC(HelloWorldScene);

private:
    const char* spriteFilePath = "iPhone5.png";
    const char* buttonFP = "button.png";
};

