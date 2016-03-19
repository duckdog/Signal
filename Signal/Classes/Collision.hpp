//
//  Collision.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/19.
//
//

#include "AnchorPoint.hpp"
#include "Screen.hpp"

USING_NS_CC;

namespace   Collision{
    
    
    //Tips:点と四角の当たり判定.
    //四角の回転未対応.
    static bool isPointToRect(cocos2d::Vec2 point,
                              cocos2d::Vec2 pos,cocos2d::Vec2 size,
                              cocos2d::Vec2 anchorPoint = AncPoint::AnchorCenter)
    {
        
        //画像のアンカーポイントに合わせて当たり判定を微調整.
        pos -= Vec2(size.x * anchorPoint.x ,
                    size.y * anchorPoint.y);
        
        
        if(point.x  > pos.x && point.x < (pos.x + size.x) &&
           point.y > pos.y && point.y < (pos.y + size.y))
        {
            return true;
        }
        
        return false;
    }
    
    /*
     //
     //以下当たり判定　末実装
     //
    static bool RectToRect(cocos2d::Vec2 pos1,cocos2d::Vec2 size1,
                           
                           cocos2d::Vec2 pos2,cocos2d::Vec2 size2,
                           AncPoint::Key anchorPoint1 = AncPoint::Key::Center,
                           AncPoint::Key anchorPoint2 = AncPoint::Key::Center)
    {
        
        //画像のアンカーポイントに合わせて当たり判定を微調整.
        Vec2 anchor1  = AncPoint::anchorMap[anchorPoint1];
        Vec2 anchor2  = AncPoint::anchorMap[anchorPoint1];

        pos1 -= Vec2(size1.x * anchor1.x ,
                     size1.y * anchor1.y);
        pos2 -= Vec2(size2.x * anchor2.x ,
                     size2.y * anchor2.y);
        

     
        if(pos1.x  > pos2.x + size2.x && point.x < (pos.x + size.x) &&
           point.y > pos.y && point.y < (pos.y + size.y))
        {
            return true;
        }
     
        return false;
    }
    
    
    
    
    static bool PointToCircle()
    {
        
        return false;
        
    }
    
    static bool CircleToCircle()
    {
        return false;
        
    }
    */
    
}
