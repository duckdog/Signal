//
//  ParticleEmitter.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/26.
//
//

#include "GameObject.hpp"

class ParticleEmitter : public GameObject,create_func<ParticleEmitter>
{
    
    
public:
    
    ParticleEmitter();
    ~ParticleEmitter();
    //通常初期化
    virtual bool init(cocos2d::Vec2 pos,cocos2d::Vec2 scale = Vec2(0.1f,0.1f),
                      float lifeTime = 1, int maxPartcle = 10,
                      float speed    = 5, const char* spritePath = "smog.png");
    virtual void Update(float delta);
    using create_func::Create;
    
    static void SetTouchEndedFunc(std::function<void()> func){ touchEndedFuncs_.push_back(func);}
    static void SetTouchEndedFuncs( std::vector<std::function<void()>>& funcs){ touchEndedFuncs_ = std::move(funcs);}
    
protected:
    
       
    //タッチ処理用
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    static std::vector<std::function<void()>> touchBeganFuncs_;
    static std::vector<std::function<void()>> touchMovedFuncs_;
    static std::vector<std::function<void()>> touchEndedFuncs_;
    
};


namespace Direction{
    
    
    static cocos2d::Vec2 upVec    = Vec2(0,1);
    static cocos2d::Vec2 DownVec  = Vec2(0,-1);
    static cocos2d::Vec2 LeftVec  = Vec2(-1,0);
    static cocos2d::Vec2 RightVec = Vec2(1,0);
    
    
}
