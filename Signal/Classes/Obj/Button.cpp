//
//  Button.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/16.
//
//

#include "Button.hpp"


std::vector<std::function<void()>> Button::touchBeganFuncs_;
std::vector<std::function<void()>> Button::touchMovedFuncs_;
std::vector<std::function<void()>> Button::touchEndedFuncs_;

Button::Button()
:GameObject(), isTouch_(false)
{
    
}
Button::~Button()
{
    
}

bool Button::init(cocos2d::Vec2 pos,cocos2d::Vec2 scale,cocos2d::Vec2 ancPos,ObjectTag tag)
{
    
    if(!cocos2d::Sprite::init())
    {
        return false;
    }
    //ステータスを初期化
    pos_ = pos;
    scale_ = scale;
    ancPos_ = ancPos;
    tag_ = tag;
    spritePath_ = buttonSpritePath;
    
    //描画がする画像の初期化
    sprite_ = SpriteMgr::Get().Add(spritePath_,Resource::SpriteKey::UIButton);
    sprite_->setScale(scale_.x,scale_.y);
    sprite_->setPosition(pos_);
    sprite_->setAnchorPoint(ancPos_);
    this->addChild(sprite_);
    
    //画像サイズを取得,当たり判定用にサイズを設定。
    size_ = sprite_->getContentSize();
    size_ = Vec2(size_.x * scale.x , size_.y * scale.y);

    //Updateを登録.
    this->schedule(schedule_selector(Button::Update));
    
    return true;
}

void Button::Update(float delta)
{
    //位置とスケールを更新
    UpdatePosScale(sprite_);
    
    
}


//タッチシステムのデフォルト実装.
bool Button::onTouchBegan(Touch* touch, Event* event) {
    isTouch_ = false;
    
    
    
    return true;
}
void Button::onTouchMoved(Touch* touch, Event* event) {}

//ボタン上で、指（カーソル）をはなしたら,真を返す.
void Button::onTouchEnded(Touch* touch, Event* event) {
    auto location = touch->getLocation();
    
    //ボタン内でカーソルを話したら実行
    if(Collision::isPointToRect(location,Vec2(pos_.x ,pos_.y),size_,ancPos_))
    {
        //関数ポインタに登録されているものを実行.
        for(auto func : touchEndedFuncs_)
        {
            //実行
            func();
        }
        
        isTouch_ = true;
    }
}

