//
//  GameScene.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/19.
//
//

#include "GameScene.hpp"
Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool GameScene::init()
{
    
    if ( !Layer::init())
    {
        return false;
    }
    
    return true;
}
