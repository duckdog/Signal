//
//  ScoreNumbers.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/04/03.
//
//

#include "ScoreNumbers.hpp"



bool ScoreNumbers::init(cocos2d::Vec2 pos,   cocos2d::Vec2 scale,
                        cocos2d::Vec2 ancPos)
{
    if(!cocos2d::Sprite::init())
    {
        return false;
    }
 
    //スコアマネージャーのポインタを保存
    scoreMgrPtr_ = &ScoreMgr::Get();
    
    //スケールの調整必須
    auto zeroNumber = cocos2d::Sprite::create(NumberSpritePathes_[0]);
    //画面サイズずれを調整
    auto mag = Screen::Screen::Get().Maginification().y;
    scale_ = cocos2d::Vec2(scale.x * mag,scale.y * mag);
    
    //画像サイズを取得,当たり判定用にサイズを設定。
    size_ = zeroNumber->getContentSize();
    size_ = Vec2(size_.x * scale_.x , size_.y * scale_.y);
    pos_ = pos;
    
    zeroNumber->setPosition(pos_);
    zeroNumber->setScale(scale_.x,scale_.y);
    
    //桁数
    scoreDigit_ = 1;
    
    numberSpriteVector_.push_back(zeroNumber);
    this->addChild(zeroNumber);
    
    this->schedule(schedule_selector(ScoreNumbers::Update));
    
    return true;
}


void ScoreNumbers::Update(float delta)
{
    int score = scoreMgrPtr_->GetShowScore();
    int spriteNumber;
    
    
    //桁が繰り上がったら、
    while((scoreMgrPtr_->GetShowScore() / scoreDigit_) >= 10)
    {
        //桁数が上がったのを記憶
        scoreDigit_ *= 10;
        
        //画像を追加
        cocos2d::Sprite* scoreSprite = cocos2d::Sprite::create(NumberSpritePathes_[0]);
        scoreSprite->setScale(scale_.x,scale_.y);
        numberSpriteVector_.push_back(scoreSprite);

        //スコアの１桁目の位置を基準に左にずらしていき、中央揃えする
        float quarterSize = size_.x * 0.25f;
        float halfSize = quarterSize * 2;
        
        //基準の位置を設定
        cocos2d::Vec2 basePos = cocos2d::Vec2(pos_.x +(numberSpriteVector_.size() - 1)  * quarterSize,pos_.y);
        
        for(int i = 0; i < numberSpriteVector_.size(); i++)
        {
            //１桁目は基準位置を設定
            if(i == 0)
            {
                numberSpriteVector_[i]->setPosition(basePos);
                continue;
            }
            //１桁目を基準に、左にずらしていく
            numberSpriteVector_[i]->setPosition(basePos.x - (halfSize * i),basePos.y);
        
        }
        
        //スコアスプライトの情報初期化後、画面に表示.
        this->addChild(scoreSprite);
    }
    
    //showScoreから一桁ずつ数字を取り出す
    for(int i = 0; score > 0; i++)
    {
        spriteNumber = score % 10;
        numberSpriteVector_[i]->setTexture(NumberSpritePathes_[spriteNumber]);
        
        score *= 0.1f;
    }


    
}












