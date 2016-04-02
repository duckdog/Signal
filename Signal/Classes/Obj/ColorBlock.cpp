//
//  ColorBlockButton.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/04/01.
//
//

#include "ColorBlock.hpp"
#include "ScoreMgr.hpp"
#include "TouchParticle.hpp"
ColorBlock::ColorBlock()
{

}


bool ColorBlock::init(cocos2d::Vec2 pos,     cocos2d::Vec2 scale,
                      Type type,             cocos2d::Vec2 ancPos,
                      const char* spritePath,ObjectTag     tag)
{
    
    if(!cocos2d::Sprite::init())
    {
        return false;
    }
    
    reLifeTimer_ = 0;
    type_ = Type::None;
    
    //生成
    spritePath_ = spritePath;
    sprite_ = SpriteMgr::Get().Add(spritePath_,Resource::SpriteKey::Block);
    //ステータス,描画する画像の初期化
    ColorBlock::InitInfo(pos,scale,ancPos,sprite_,tag);
//    sprite_->setScale(scale_.x,scale_.y);
//    sprite_->setPosition(pos_);
//    sprite_->setAnchorPoint(ancPos_);
    this->addChild(sprite_);
    
    //Updateを登録.
    this->schedule(schedule_selector(ColorBlock::Update));
    
    return true;
}


void ColorBlock::Update(float delta)
{
    if(reLifeTimer_ > 0)
    {
        
        reLifeTimer_ -=  1 * delta;
        if(reLifeTimer_ <= 0){ sprite_->setVisible(true); }
    }
    

}


bool ColorBlock::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto location = touch->getLocation();
    
    //ボタン内でカーソルを話したら実行
    if(Collision::isPointToRect(location,Vec2(pos_.x ,pos_.y),size_,ancPos_))
    {
        
        //壊れてない状態だったらブロックを壊す
        if(reLifeTimer_ <= 0)
        {
            //タッチでブロックをぶっ壊す
            reLifeTimer_ = reMakeTime_;
            sprite_->setVisible(false);
            auto effect = TouchParticle::TouchParticleCreate(pos_,particleScale_,
                                                             Direction::LeftVec,
                                                             particletAngle_,
                                                             particletLifeTime_,particleMax_,
                                                             particletSpeed_,"button.png");
            this->addChild(effect,1);
            
            ScoreMgr::Get().AddScore();
        }
    }


}












