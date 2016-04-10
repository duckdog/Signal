//
//  ParticleEmitter.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/26.
//
//

#include "GameObject.hpp"
class Particle;
namespace Direction{
    
    
    static cocos2d::Vec2 upVec    = Vec2(0,1);
    static cocos2d::Vec2 DownVec  = Vec2(0,-1);
    static cocos2d::Vec2 LeftVec  = Vec2(-1,0);
    static cocos2d::Vec2 RightVec = Vec2(1,0);
    
    
}


class ParticleEmitter : public GameObject,create_func<ParticleEmitter>
{
    
    
public:
    
    ParticleEmitter();
    ~ParticleEmitter();
    using create_func::Create;
    
    //通常初期化
    virtual bool init(cocos2d::Vec2 pos,cocos2d::Vec2 scale = Vec2(0.04f,0.04f),
                      cocos2d::Vec2 direc = Direction::upVec,
                      float angle = 360,
                      float lifeTime = 1, int maxPartcle = 10,
                      float speed    = 30, const char* spritePath = "smog.png");
    
    virtual void Update(float delta);
    
    
    std::vector<Particle*> GetPartcles(){return particleVector_;}
    static void SetTouchEndedFunc(std::function<void()> func){ touchEndedFuncs_.push_back(func);}
    static void SetTouchEndedFuncs( std::vector<std::function<void()>>& funcs){ touchEndedFuncs_ = std::move(funcs);}
    
protected:
    
    std::vector<Particle*> particleVector_;
       
    //タッチ処理用
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    
    
    static std::vector<std::function<void()>> touchBeganFuncs_;
    static std::vector<std::function<void()>> touchMovedFuncs_;
    static std::vector<std::function<void()>> touchEndedFuncs_;
    
};


//指定した向きを基準に、分割数、角度を設定して、扇型の方向を取得.
static std::vector<cocos2d::Vec2> GetFanDirecs(cocos2d::Vec2 baseDirec,int angle,int divisionNumber)
{
    
    std::vector<cocos2d::Vec2> directions;
    const double toRadian = (3.14/180);
    auto divisionAngle = angle / divisionNumber;
    
    for(int i = 0; i < divisionNumber; i++){
        //θを求める
        double theata = divisionAngle * (i + 1) * toRadian;
        directions.push_back(Vec2(baseDirec.x * cos(theata) - baseDirec.y * sin(theata),
                                  baseDirec.x * sin(theata) + baseDirec.y * cos(theata)));
    }
    
    return directions;
    
}



