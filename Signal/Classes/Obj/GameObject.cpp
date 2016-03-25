#include "GameObject.hpp"
#include <iostream>
#include "../Screen.hpp"
#include "../AnchorPoint.hpp"


GameObject::GameObject()
:pos_(Screen::Screen::Get().center),scale_(1,1),ancPos_(AncPoint::AnchorCenter),
spritePath_(""),tag_(ObjectTag::Null){

    //////////////////////////////タッチ処理
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameObject::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameObject::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameObject::onTouchEnded, this);
    auto dip = Director::getInstance()->getEventDispatcher();
    dip->addEventListenerWithSceneGraphPriority(listener, this);


}


GameObject::~GameObject(){}


//Tips:spriteの位置とスケールの更新だけ頻繁におこなわれるため、定義
//２行だからいらなかったかも。
void GameObject::UpdatePosScale(cocos2d::Sprite* sprite)
{
    sprite->setPosition(pos_);
    sprite->setScale(scale_.x,scale_.y);
}