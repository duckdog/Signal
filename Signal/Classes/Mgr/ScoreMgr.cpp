//
//  ScoreMgr.cpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/31.
//
//

#include "ScoreMgr.hpp"


ScoreMgr::ScoreMgr()
{
    
}

ScoreMgr& ScoreMgr::Get()
{
    static ScoreMgr instance;
    return instance;
}

//初期化
void ScoreMgr::ScoreInit()
{
    
    currentScore_ = 0;
    showScore_ = 0;
    comboCount_ = 0;
       
    RateInit();
}
void ScoreMgr::RateInit()
{
    
    comboRate_ = defaultComboRate_;
    scoreRate_ = defaultScoreRate_;
}


void ScoreMgr::AddScore()
{
    //
    //何かしらのコンボ処理
    //
    
    AddComboCount();
    breakButtonCount_++;
    currentScore_ += scoreRate_;
    
   
}

void ScoreMgr::AddComboCount()
{
    comboTimeCount_ = comboTimeLimit_;
    comboCount_++;
}

//ハイスコアならば真を返す
bool ScoreMgr::CheckHighScore()
{
    if(currentScore_ > highScore_)
    {
        //セーブ
        highScore_ = currentScore_;
        return true;
    }
    
    return false;
}



void ScoreMgr::UpdateScore(float delta)
{
    //一定の時間コンボがなかったら、コンボをリセット
    if(comboTimeCount_ > 0)
    {
        comboTimeCount_ -= 1 * delta;
    }
    else if(comboTimeCount_ <= 0)
    {
        //コンボ数を０にリセット
        comboCount_ = 0;
        
    }

    //表示してるスコアより、実際のスコアが小さければ
    if(showScore_< currentScore_){
        
        addScoreSkipTimer_ += 1 * delta;
        
        //代入に一秒以上かかったら直接代入.
        if(addScoreSkipTimer_ > skipTimeLimit_){
            
            showScore_ = currentScore_;
        }
        //少しずつ加算,だんだん加速
        showScore_ += defaultScoreRate_ * (addScoreSkipTimer_ * addScoreSkipTimer_);
        
        //実際のスコアより多くなってしまっていたら、もとに戻す.
        if(showScore_ > currentScore_) showScore_ = currentScore_;
       
        
    }
    else{
        //念のため再代入
        showScore_ = currentScore_;
        addScoreSkipTimer_ = 0;
    }
    
}
















