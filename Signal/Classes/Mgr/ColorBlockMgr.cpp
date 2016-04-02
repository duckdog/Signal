//
//  ColorBlockMgr.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/04/01.
//
//

#include "ColorBlockMgr.hpp"



bool ColorBlockMgr::init()
{

    if(!cocos2d::Sprite::init())
    {
        return false;
    }
    
    
    
    //基準になる(中心の)ブロックを生成.
    auto baseBlock = ColorBlock::Create(Screen::Screen::Get().downCenter,blockScale_,
                                        ColorBlock::Type::None);
    
    
    //追加
    blockVector_.push_back(baseBlock);
    this->addChild(baseBlock);
    
    //一個目からサイズを取得
    Vec2 blockSize =  baseBlock->GameObject::GetSize();
    createStartPos_ = Screen::Screen::Get().downCenter - cocos2d::Vec2(blockSize.x * 2,blockSize.y);
    
    
    //残りのブロックを生成
    for(int row = 0; row < rowMax_;row++){
        
        for(int col = 0; col < colMax_; col++){
            
            //一個だけつくってあるので、中心をスルー
            if(row == 1 && col == 3){continue;}

            //生成
            auto block = (ColorBlock::Create
                         (createStartPos_ + Vec2(blockSize.x * row,blockSize.y * col),
                          blockScale_,ColorBlock::Type::None));
            //追加
            this->addChild(block);
            blockVector_.push_back(block);
           
        }
    
    }
    
    return true;
}

void ColorBlockMgr::Update(float delta)
{
    //
    


}