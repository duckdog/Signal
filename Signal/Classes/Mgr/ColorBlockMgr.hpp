//
//  ColorBlockMgr.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/04/01.
//
//

#pragma once

#include "../Obj/ColorBlock.hpp"

class ColorBlockMgr : public GameObject,
create_func<ColorBlockMgr>
{

public:
    
    virtual bool init();
    void Update(float delta);
    using create_func::Create;
    
private:
    
    std::vector<ColorBlock*> blockVector_;
    
    
    const cocos2d::Vec2 blockScale_ = Vec2(0.25f,0.25f);
    cocos2d::Vec2 createStartPos_;
    
    const int rowMax_ = 5;
    const int colMax_ = 3;

};