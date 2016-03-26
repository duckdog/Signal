//
//  Header.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/26.
//
//

#include


#pragma once

#include <stdio.h>
#include <iostream>

namespace Random {
    
    static void Init()
    {
        //乱数の初期化.
        srand((unsigned int)time(NULL));
        
    }
    
    
    //範囲乱数生成
    static float GetRandomRange(float min,float max)
    {
        return min + (float)(rand()/ (float)(RAND_MAX/ (max - min)));
    }
    static int GetRandomRange(int min,int max)
    {
        return min + (int)(rand() * (max-min+1.0)/(1.0+RAND_MAX));
    }

    }
}