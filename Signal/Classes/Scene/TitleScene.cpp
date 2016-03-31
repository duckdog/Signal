//
//  TiltleScene.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/19.
//
//

#include "TitleScene.hpp"
#include "../Obj/TouchParticle.hpp"
#include "../Mgr/SpriteMgr.hpp"
#include "../Screen.hpp"
#include "../Obj/Button.hpp"

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
    //タッチ処理/////////////////////////////////////////////////////////////////////////////////
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(TitleScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(TitleScene::onTouchEnded, this);
    auto dip = Director::getInstance()->getEventDispatcher();
    dip->addEventListenerWithSceneGraphPriority(listener, this);
    
    //背景/////////////////////////////////////////////////////////////////////////////////
    auto bg = SpriteMgr::Get().Add(bgFilePath,Resource::SpriteKey::TitleBg);
    Screen::Screen::Get().FulScreenSprite(bg);

    //UI生成.シーン遷移機能を追加.
    auto testButton = Button::Create(Screen::Screen::Get().downCenter,Vec2(0.20f,0.20f),
                                     AncPoint::AnchorCenter,"StartButton.png");
    testButton->SetTouchEndedFunc([](){ SceneMgr::ReplaceScene(SceneType::Menu);});
    auto testButton2 = Button::Create(Screen::Screen::Get().upCenter,Vec2(0.20f,0.20f),
                                     AncPoint::AnchorCenter,"StartButton.png");
    testButton2->SetTouchEndedFunc([](){ SceneMgr::ReplaceScene(SceneType::Menu);});
    
    
    
    //シーンに追加
    objectList_.push_back(testButton);
    objectList_.push_back(testButton2);
    for(auto obj : objectList_){this->addChild(obj);}
    this->addChild(bg, -1);
    
    //update処理
    this->schedule(schedule_selector(TitleScene::Update));

    return true;
}

void TitleScene::Update(float delta)
{

}


bool TitleScene::onTouchBegan(Touch* touch, Event* event)
{
    auto touchPos = touch->getLocation();
    //this->addChild(ParticleEmitter::TouchParticleCreate(touchPos));
    this->addChild(TouchParticle::TouchParticleCreate(touchPos));

    
    return true;
}
void TitleScene::onTouchMoved(Touch* touch, Event* event)
{    
}
void TitleScene::onTouchEnded(Touch* touch, Event* event)
{
}