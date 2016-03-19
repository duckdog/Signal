#include "SpriteMgr.hpp"


    
SpriteMgr& SpriteMgr::Get()
{
    static SpriteMgr instance;
    return instance;
}

//生成
cocos2d::Sprite* SpriteMgr::Add(const char* spriteFileName,SpriteKey key)
{
    
    auto res = Sprite::create(spriteFileName);
    spriteCash_.insert(std::make_pair(static_cast<int>(key),spriteFileName));

    return res;
}

cocos2d::Sprite* SpriteMgr::Find(SpriteKey key)
{
    
    cocos2d::Sprite* res = Sprite::create(spriteCash_[static_cast<int>(key)]);
    return res;
}

//消去
void SpriteMgr::Erase(SpriteKey key)
{
    spriteCash_.erase(static_cast<int>(key));
}

//全消去
void SpriteMgr::Clear()
{
    spriteCash_.clear();
}
    
