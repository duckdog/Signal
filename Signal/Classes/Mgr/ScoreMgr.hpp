//
//  ScoreMgr.hpp
//  CocosTemplate
//
//  Created by 佐藤 匠 on 2016/03/31.
//
//

#pragma once
#include <cocos2d.h>


class ScoreMgr
{
public:
    
    static ScoreMgr& Get();
    
    void ScoreInit();
    void RateInit();
    bool CheckHighScore();
    
    //取得
    inline int GetShowScore() const{return showScore_;}
    inline int GetcurrentScore() const{return currentScore_;}
    inline int GetHighScore()const{return highScore_;}
    
    
    //加算
    void AddScore();
    void AddComboCount();
    
    //更新
    void UpdateScore(float delta);
    
private:
    
    ScoreMgr();
    
   
    //ハイスコア
    int highScore_;
    int highCombo_;
    int breakButtonCount_;
    
    //タイマー
    float addScoreSkipTimer_;
    float comboTimeCount_;
    const float skipTimeLimit_ = 1.0f;
    const float comboTimeLimit_ = 1.5f;
    
    //スコア、コンボ保存領域.//////////////////
    int currentScore_;
    int showScore_;
    int comboCount_;
   
    
    //レート////////////////////////////////
    const float defaultComboRate_ = 10.0f;
    const float defaultScoreRate_ = 100.0f;
    float comboRate_;
    int scoreRate_;



};