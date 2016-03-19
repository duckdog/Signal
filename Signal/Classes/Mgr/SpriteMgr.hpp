//
//リソース管理に挑戦中
//cocos依存、現在テクスチャのみ。サウンドも管理したい
//


#pragma once

#include "cocos2d.h"
#include <list>
#include <map>
#include <memory>
#include "SpriteKey.hpp"

USING_NS_CC;
using namespace Resource;

class SpriteMgr
{
    
public:
    
    static SpriteMgr& Get();
    
    cocos2d::Sprite* Add(const char* spriteFileName,SpriteKey);
    cocos2d::Sprite* Find(SpriteKey);
    void Erase(SpriteKey);
    void Clear();

private:
    SpriteMgr() = default;
    std::map<int,const char*> spriteCash_;
    
};
    
    