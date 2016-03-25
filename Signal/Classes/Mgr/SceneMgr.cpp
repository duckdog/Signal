#include "SceneMgr.hpp"
#include "../Scene/HelloWorldScene.hpp"
#include "../Scene/ObjectCreateTestScene.hpp"
#include "../Scene/MenuScene.hpp"
#include "../Scene/GameScene.hpp"
#include "../Scene/TitleScene.hpp"

 void SceneMgr::ReplaceScene(SceneType type)
{
	switch (type)
	{
	case Title:
		Director::getInstance()->replaceScene(TitleScene::createScene());
		break;
	case Menu:
		Director::getInstance()->replaceScene(MenuScene::createScene());
		break;
	case Game:
		Director::getInstance()->replaceScene(GameScene::createScene());
		break;
	default:
		//error
		break;
	}
}