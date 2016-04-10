//
//  ScoreNumbers.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/04/03.
//
//

#pragma once

#include "GameObject.hpp"
#include "ScoreMgr.hpp"

class ScoreNumbers : public GameObject,create_func<ScoreNumbers>
{
public:
    
    bool init(cocos2d::Vec2 pos,   cocos2d::Vec2 scale,
              cocos2d::Vec2 ancPos = AncPoint::AnchorCenter);
    void Update(float delta);
    
    using create_func::Create;
    
    
private:

    ScoreMgr* scoreMgrPtr_;
    int scoreDigit_;
    
    std::vector<cocos2d::Sprite*> numberSpriteVector_;
    std::vector<const char*> NumberSpritePathes_ =
    {"0.png","1.png","2.png","3.png","4.png",
     "5.png","6.png","7.png","8.png","9.png"};
    


};