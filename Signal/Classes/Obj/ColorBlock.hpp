//
//  ColorBlockButton.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/04/01.
//
//

#pragma once
#include "Button.hpp"

class ColorBlock : public Button
{
public:
    enum Type
    {
        None   = -1,
        Blue   = 0,
        Yellow = 1,
        Red    = 2,
        
        Last = 3,
        
    };

    ColorBlockButton();
    
    static Button* CreateBlockButton(cocos2d::Vec2 pos, cocos2d::Vec2 scale,
                                     cocos2d::Vec2 ancPos     = AncPoint::AnchorCenter,
                                     const char*   spritePath = "button.png",
                                     ObjectTag     tag        = ObjectTag::Button);
    void Update();
    
private:
    
    Type type_;

};
