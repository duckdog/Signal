//
//  ParticleEmitter.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/26.
//
//

#include "ParticleEmitter.hpp"


std::vector<std::function<void()>> ParticleEmitter::touchBeganFuncs_;
std::vector<std::function<void()>> ParticleEmitter::touchMovedFuncs_;
std::vector<std::function<void()>> ParticleEmitter::touchEndedFuncs_;

ParticleEmitter::ParticleEmitter()
:GameObject()
{
    
}
ParticleEmitter::~ParticleEmitter()
{
    
}

bool ParticleEmitter::init(cocos2d::Vec2 pos,float lifeTime,int maxPartcle)
{
    
    if(!cocos2d::Sprite::init())
    {
        return false;
    }
    
    lifeTime_ = lifeTime;
    maxPartcle_ = maxPartcle;
    
    //生成
    for(int i = 0; i < maxPartcle; i++)
    {
        auto particle = Sprite::create("button.png");
        this->addChild(particle);
        particle->setPosition(pos);
        auto scaleBy = cocos2d::ScaleTo::create(lifeTime,0.5f,1.0f);
        auto end = cocos2d::RemoveSelf::create(true);
        auto sequence = cocos2d::Sequence::create(scaleBy,end, NULL);
        particle->runAction(sequence);
    }
    
   // spritePath_ = spritePath;
    //sprite_ = SpriteMgr::Get().Add(spritePath_,Resource::SpriteKey::UIParticleEmitter);
    //ステータス,描画する画像の初期化
//    ParticleEmitter::InitInfo(pos,scale,ancPos,sprite_,tag);
//    sprite_->setScale(scale_.x,scale_.y);
//    sprite_->setPosition(pos_);
//    sprite_->setAnchorPoint(ancPos_);
//    this->addChild(sprite_);
    
    //Updateを登録.
    this->schedule(schedule_selector(ParticleEmitter::Update));
    
    return true;
}

void ParticleEmitter::Update(float delta)
{
    //位置とスケールを更新
    //UpdatePosScale(sprite_);
  
    
    lifeTime_ -= delta * 1;
    
    if(this->getChildren().size() == 0){this->removeFromParentAndCleanup(true); CCLOG("さらば！");}
    
}


//タッチシステムのデフォルト実装.
bool ParticleEmitter::onTouchBegan(Touch* touch, Event* event) {
    
    
    
    return true;
}
void ParticleEmitter::onTouchMoved(Touch* touch, Event* event) {}

//ボタン上で、指（カーソル）をはなしたら,真を返す.
void ParticleEmitter::onTouchEnded(Touch* touch, Event* event) {

    auto location = touch->getLocation();
    
}

