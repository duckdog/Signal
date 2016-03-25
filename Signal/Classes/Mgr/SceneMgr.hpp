
#pragma once

#include<memory>
#include<vector>
#include<list>
#include "cocos2d.h"

USING_NS_CC;

class SceneMgr;
typedef std::shared_ptr<SceneMgr> sceneSptr;
class SceneMgr : public cocos2d::Layer
{
public:
	enum SceneType
	{
        TestObject,
        
		Title,
		Menu,
		Game,

		None,
	};

	SceneMgr() = default;
    ~SceneMgr(){};
	static void ReplaceScene(SceneType type = SceneType::Title);
	
protected:
    
    CREATE_FUNC(SceneMgr);
};
