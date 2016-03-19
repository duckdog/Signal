#include "SceneMgr.hpp"
#include "../Scene/HelloWorldScene.hpp"
#include "../Scene/ObjectCreateTestScene.hpp"
 void SceneMgr::ReplaceScene(SceneType type)
{
	switch (type)
	{
	case Title:
		Director::getInstance()->replaceScene(HelloWorldScene::createScene());
		break;
	case TestObject:
		Director::getInstance()->replaceScene(ObjectCreateTestScene::createScene());
		break;
	case Game:
		Director::getInstance()->replaceScene(HelloWorldScene::createScene());
		break;
	default:
		//error
		break;
	}
}