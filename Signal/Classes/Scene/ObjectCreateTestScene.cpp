//
//  ObjectCreateTestScene.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/16.
//
//

#include "ObjectCreateTestScene.hpp"
#include "../Screen.hpp"
#include "../AnchorPoint.hpp"
#include "../Obj/Button.hpp"


Scene* ObjectCreateTestScene::createScene()
{
    auto scene = Scene::create();
    auto layer = ObjectCreateTestScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool ObjectCreateTestScene::init()
{
    
    if ( !Layer::init())
    {
        return false;
    }
    //生成と追加　UpdateはButtonクラス内で行う
    auto button =  Button::Create(Screen::Screen::Get().center,Vec2(1,1),
                                  AncPoint::AnchorCenter,GameObject::ObjectTag::Button);
    
    this->addChild(button,1);
    this->schedule(schedule_selector(ObjectCreateTestScene::Update));
    
       return true;
}

void ObjectCreateTestScene::Update(float delta)
{
  

}

