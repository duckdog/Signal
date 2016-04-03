//
//  ColorBlockMgr.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/04/01.
//
//

#include "ColorBlockMgr.hpp"

int ColorBlockMgr::blockTypeCount_[3];

bool ColorBlockMgr::init()
{

    if(!cocos2d::Sprite::init())
    {
        return false;
    }
    
    //カウントを初期化
    for(auto count : blockTypeCount_)
    {
        count = 0;
    }
    
    
    //基準になる(中心の)ブロックを生成.
    auto baseBlock = ColorBlock::Create(Screen::Screen::Get().downCenter,blockScale_,
                                        SetButtonType());
    
    
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
                          blockScale_,SetButtonType()));
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



//うまいこと色が分配されるようにする.
ColorBlock::Type ColorBlockMgr::SetButtonType()
{
    ColorBlock::Type typeNumber;
    int blueCount   = blockTypeCount_[(int)ColorBlock::Type::Blue];
    int yellowCount = blockTypeCount_[(int)ColorBlock::Type::Yellow];
    int redCount    = blockTypeCount_[(int)ColorBlock::Type::Red];
    const int limit = (int)ColorBlock::Type::Last;
    
    //半分ランダムにおく.
    if(redCount + yellowCount  + blueCount <=  (rowMax_ + colMax_) / 2)
    {
        //0~2の中でランダムで返す
        typeNumber  =  (ColorBlock::Type)(rand()%limit);
        blockTypeCount_[typeNumber]++;
        
    }
    //残りを程よく均等に分ける.
    else
    {
        //一番少ないカラータイプを取得.
        typeNumber = (ColorBlock::Type)GetLowestTypeNumber(blockTypeCount_);
        
    }
    
    return typeNumber;
    
}

//一番少ないカラータイプをかえす.
int ColorBlockMgr::GetLowestTypeNumber(int buttonTypeCounts[])
{
    //青（0番）からカウント
    int lowestCount = buttonTypeCounts[(int)ColorBlock::Type::Blue];
    int typeNumber = (int)ColorBlock::Type::Blue;
    
    //配列のサイズを取得
    int limit = 3;
    
    //シーンにある一番少ないタイプをかえす
    for(int i = 1; i < limit; i++)
    {
        //一番少ないタイプをかえす
        if(buttonTypeCounts[i] < lowestCount)
        {
            lowestCount = buttonTypeCounts[i];
            typeNumber = i;
        }
        //カウントが同率の場合は、同率のカラータイプ同士でランダムで返却.
        else if(buttonTypeCounts[i] == lowestCount)
        {
            // 同数だったら、ランダムで返す.
            if(rand()%2)
            {
                //ランダム値が１(true)になったら変更.
                lowestCount = buttonTypeCounts[i];
                typeNumber = i;
            }
        }
    }
    blockTypeCount_[typeNumber]++;
    return typeNumber;
}
