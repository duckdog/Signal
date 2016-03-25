//
//  TiltleScene.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/19.
//
//

#include "TitleScene.hpp"
#include "SpriteMgr.hpp"
#include "Screen.hpp"
#include "../Obj/NextSceneButton.hpp"
Scene* TitleScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TitleScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool TitleScene::init()
{
    
    if ( !Layer::init())
    {
        return false;
    }
   
    //背景
    auto bg = SpriteMgr::Get().Add(bgFilePath,Resource::SpriteKey::TitleBg);
    Screen::Screen::Get().FulScreenSprite(bg);

    auto testButton = Button::Create(Screen::Screen::Get().leftBottom,Vec2(0.20f,0.20f),
                                     AncPoint::AnchorLeftBottom,GameObject::ObjectTag::Button);
    //ボタンにシーン遷移機能を追加.
    testButton->SetTouchEndedFunc([](){ SceneMgr::ReplaceScene(SceneType::Menu);});
    
    
    testButton->GetSprite()->setTexture("PauseButton.png");
    
    
    objectList_.push_back(testButton);
    
    for(auto obj : objectList_){this->addChild(obj);}
    this->addChild(bg, -1);

    return true;
}



