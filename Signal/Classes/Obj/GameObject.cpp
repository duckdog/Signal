#include "GameObject.hpp"
#include <iostream>
#include "../Screen.hpp"
#include "../AnchorPoint.hpp"


GameObject::GameObject()
:pos_(Screen::Screen::Get().center),scale_(1,1),ancPos_(AncPoint::AnchorCenter),
spritePath_(""),tag_(ObjectTag::Null){
    //タッチ処理/////////////////////////////////////////////////////////////////
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(false);
    listener->onTouchBegan = CC_CALLBACK_2(GameObject::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameObject::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameObject::onTouchEnded, this);
    auto dip = Director::getInstance()->getEventDispatcher();
    dip->addEventListenerWithSceneGraphPriority(listener, this);

}


GameObject::~GameObject(){}


//Tips:spriteの位置とスケールの更新だけ頻繁におこなわれるため、定義　//２行だからいらなかったかも。
void GameObject::UpdatePosScale(cocos2d::Sprite* sprite)
{
    sprite->setPosition(pos_);
    sprite->setScale(scale_.x,scale_.y);
}

//Tips:内部情報をCreateと関係なく、初期化した場合に使う
void GameObject::InitInfo(cocos2d::Vec2 pos,cocos2d::Vec2 scale,
                          cocos2d::Vec2 ancPos,cocos2d::Sprite* sprite,
                          ObjectTag tag)
{
    //ステータスを初期化
    pos_ = pos;
    ancPos_ = ancPos;
    tag_ = tag;
    auto mag = Screen::Screen::Get().Maginification().y;//画面サイズずれを調整
    scale_ = cocos2d::Vec2(scale.x * mag,scale.y * mag);
    
    sprite_->setScale(scale_.x,scale_.y);
    sprite_->setPosition(pos_);
    sprite_->setAnchorPoint(ancPos_);
    //画像サイズを取得,当たり判定用にサイズを設定。
    
    size_ = sprite->getContentSize();
    size_ = Vec2(size_.x * scale_.x , size_.y * scale_.y);
}