#include "HelloWorldScene.hpp"
#include "../Mgr/SpriteMgr.hpp"
#include "../Screen.hpp"
#include "../Obj/Button.hpp"

Scene* HelloWorldScene::createScene()
{
    auto scene = Scene::create();   
    auto layer = HelloWorldScene::create();

	scene->addChild(layer);

	return scene;
}

bool HelloWorldScene::init()
{
 
    if ( !Layer::init())
    {
        return false;
    }
    
    //背景テスト
    auto sprite = SpriteMgr::Get().Add
    (spriteFilePath,Resource::SpriteKey::Test);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //読み込み、位置指定、レイヤーにZ値をしていして追加
    sprite->setPosition(Screen::Screen::Get().center);
    float ajustMag = Screen::Screen::Get().Maginification().y;
    sprite->setScale(1 * ajustMag,1 * ajustMag);
    this->addChild(sprite,0);
    
    //Button表示テスト
    std::vector<Sprite*> ButtonSprites;
    ButtonSprites.push_back(SpriteMgr::Get().Add
                            (buttonFP,Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    ButtonSprites.push_back(SpriteMgr::Get().Find(Resource::SpriteKey::UIButton));
    
    
    for(auto Button : ButtonSprites)
    {
        
        if(ajustMag < 1){
            Button->setScale(0.265f * ajustMag,0.265f * ajustMag);
        }
        else {
            Button->setScale(0.265f,0.265f);
        }
    }

    ButtonSprites[0]->setPosition((Screen::Screen::Get().rightBottom));
    ButtonSprites[1]->setPosition((Screen::Screen::Get().rightTop));
    ButtonSprites[2]->setPosition((Screen::Screen::Get().rightCenter));
    ButtonSprites[3]->setPosition((Screen::Screen::Get().rightTopCenter));
    ButtonSprites[4]->setPosition((Screen::Screen::Get().right));
    
    ButtonSprites[5]->setPosition((Screen::Screen::Get().leftBottom));
    ButtonSprites[6]->setPosition((Screen::Screen::Get().leftTop));
    ButtonSprites[7]->setPosition((Screen::Screen::Get().leftCenter));
    ButtonSprites[8]->setPosition((Screen::Screen::Get().leftTopCenter));
    ButtonSprites[9]->setPosition((Screen::Screen::Get().left));
    ButtonSprites[10]->setPosition((Screen::Screen::Get().center));
    ButtonSprites[11]->setPosition((Screen::Screen::Get().leftBottomCenter));
    ButtonSprites[12]->setPosition((Screen::Screen::Get().rightBottomCenter));
    
    ButtonSprites[13]->setPosition((Screen::Screen::Get().top));
    ButtonSprites[14]->setPosition((Screen::Screen::Get().upCenter));
    ButtonSprites[15]->setPosition((Screen::Screen::Get().bottom));
    ButtonSprites[16]->setPosition((Screen::Screen::Get().downCenter));

    
    for(auto Button : ButtonSprites)
    {
        this->addChild(Button,0);
    }
    
    return true;
}


