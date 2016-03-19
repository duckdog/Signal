//
//オブジェクトのベースを定義
//一括管理もしたかったがココスだとあまりにもやりづらかったので、断念
//素敵なやり方教えていただけたら嬉しい...

#pragma once

#include "cocos2d.h"
#include<utility>
#include <memory>
#include <list>
#include <vector> 
#include "../Mgr/SpriteMgr.hpp"
#include "Collision.hpp"

class GameObject: public cocos2d::Sprite
{
public:
    
	enum ObjectTag
	{
		Player = 1,
		Enemy,
		Item,
        Button,
        
		Null,
	};
    
	GameObject();
	~GameObject();
    
    cocos2d::Vec2 GetPos(){return pos_;}
    cocos2d::Sprite* GetSprite(){return sprite_;}

protected:
    
    void UpdatePosScale(cocos2d::Sprite*);
    //タッチ処理用
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){};
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event){};
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){};
    
	cocos2d::Vec2 pos_;
    cocos2d::Vec2 size_;
	cocos2d::Vec2 scale_;
	cocos2d::Vec2 ancPos_;
    cocos2d::Sprite* sprite_;
    const char*   spritePath_;
	
    ObjectTag tag_;
    

};

//以下,引数付きのcreate関数の実装
template<class Derived>
struct create_func {
    template<class... Args>
    static Derived* Create(Args&&... args) {
        //生成
        auto p = new Derived();
        //メモリ確保、初期化の可否チェック
        if (p->init(std::forward<Args>(args)...)) {
            //cocos2d::Refに定義されてるリファレンスカウンタ適用のautorelease関数適用
            //カウンタを１足して,シーン遷移時に0になり、解放される。とかなんとか。
            p->autorelease();
            return p;
        } else {
            //失敗した場合NULL返却
            delete p;
            return nullptr;
        }
    }
};

