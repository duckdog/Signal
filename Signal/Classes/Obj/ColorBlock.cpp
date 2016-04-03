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
#include "ColorBlockMgr.hpp"
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
    type_ = type;
    
    //生成
    spritePath_ = spritePath;
    sprite_ = SpriteMgr::Get().Add(spritePath_,Resource::SpriteKey::Block);
    //テスト
    colorMask_ = SpriteMgr::Get().Add(colorMaskPath_,Resource::SpriteKey::BlockMask);
    colorMask_->setAnchorPoint(AncPoint::AnchorLeftBottom);
    SetColor((int)type,colorMask_);
    
    //ステータス,描画する画像の初期化
    ColorBlock::InitInfo(pos,scale,ancPos,sprite_,tag);
    
    this->addChild(sprite_);
    sprite_->addChild(colorMask_);
    
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

void ColorBlock::SetColor(int typeNumber,cocos2d::Sprite* sprite)
{

    Color3B color = Color3B::BLACK;
    
    switch (typeNumber) {
        case Type::Red:
            color = Color3B::RED;
            break;
        case Type::Yellow:
            color = Color3B::YELLOW;
            break;
        case Type::Blue:
            color = Color3B::BLUE;
            break;
            
    }
    
    sprite->setColor(color);
    


};

//消去メソッド
void ColorBlock::BreakBlock()
{
    //壊れてない状態だったらブロックを壊す
    if(reLifeTimer_ <= 0)
    {
        //タッチでブロックをぶっ壊す
        reLifeTimer_ = reMakeTime_;
        sprite_->setVisible(false);
        
//        //自分のカウントを減らす
//        auto blockCount = ColorBlockMgr::GetBlockTypeCount();
//        blockCount[(int)type_]--;
//        
//        
//        //現在のブロックのタイプから、ゲームが詰まないように、タイプを取得
//        this->type_ = (Type)ColorBlockMgr::GetLowestTypeNumber(blockCount);
//
        
        //ランダムに色を変更.
        //Todo:色のでる確率は用調整。
        this->type_ = random(Type::Blue,Type::Red);
        SetColor(type_,colorMask_);
        
        auto effect = TouchParticle::TouchParticleCreate(pos_,particleScale_,
                                                         Direction::LeftVec,
                                                         particletAngle_,
                                                         particletLifeTime_,particleMax_,
                                                         particletSpeed_,"button.png");
        //他のブロックに隠れないように、z値を１にしておく.
        this->addChild(effect,1);
        
    
        ScoreMgr::Get().AddScore();
    }


}


bool ColorBlock::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto location = touch->getLocation();
    
    //ボタン内でカーソルを話したら実行
    if(Collision::isPointToRect(location,Vec2(pos_.x ,pos_.y),size_,ancPos_))
    {
        
        ColorBlock::BreakBlock();
        
    }


}












