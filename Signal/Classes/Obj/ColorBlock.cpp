//
//  ColorBlockButton.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/04/01.
//
//

#include "ColorBlockButton.hpp"


ColorBlockButton::ColorBlockButton()
:Button()
{

}

Button* ColorBlockButton::CreateBlockButton(cocos2d::Vec2 pos, cocos2d::Vec2 scale,
                                            cocos2d::Vec2 ancPos,const char* spritePath,
                                            ObjectTag tag)
{
    
    auto button = Button::Create(pos,scale,ancPos,spritePath,tag);
    
    
    return button;

}