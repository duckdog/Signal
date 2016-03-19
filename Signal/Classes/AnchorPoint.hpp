//
//  AnchorPoint.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/05.
//
//

#pragma once
#include <map>
//アンカーポイントを定義
namespace AncPoint {
    
    enum Key
    {
        LeftTop = 0,
        RightTop = 1,
        LeftBottom = 2,
        RightBottom = 3,
        
        Left,
        Right,
        Top,
        Bottom,
        Center,
        Last,
    };
    
    const cocos2d::Vec2  AnchorLeftTop = cocos2d::Point(0,1);
    const cocos2d::Vec2  AnchorRightTop = cocos2d::Point(1,1);
    const cocos2d::Vec2  AnchorLeftBottom = cocos2d::Point(0,0);
    const cocos2d::Vec2  AnchorRightBottom  = cocos2d::Point(1,0);
    
    const cocos2d::Vec2  AnchorLeft = cocos2d::Point(0,0.5f);
    const cocos2d::Vec2  AnchorRight  = cocos2d::Point(1,0.5f);
    
    const cocos2d::Vec2  AnchorCenter  = cocos2d::Point(0.5f,0.5f);
    const cocos2d::Vec2  AnchorTop  = cocos2d::Point(0.5f,1);
    const cocos2d::Vec2  AnchorBottom  = cocos2d::Point(0.5f,0);
    
    
    static std::map<AncPoint::Key,cocos2d::Vec2> anchorMap =
    {
        {LeftTop,AnchorLeftTop},
        {LeftBottom,AnchorLeftBottom},
        {RightTop,AnchorRightTop},
        {RightBottom,AnchorRightBottom},
        {Right,AnchorRight},
        {Left,AnchorLeft},
        {Top,AnchorTop},
        {Bottom,AnchorBottom},
        {Center,AnchorCenter},
        
        
    };
    
    
}
