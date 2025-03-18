#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Dictionary.h"
#include "Tuple.h"
#include "Tuple.cpp"

template <class T>

class ScoreBoard
{
    private:
        Dictionary<std::string,T> scores;

     public:
        ScoreBoard();
        ~ScoreBoard();
        void addScore(std::string,T);
        void removeScore(std::string);
        T getScore(std::string);
        T getHighScore();
        Tuple<int,std::string*> getHighScoreUser();   
};

#include "Dictionary.cpp"

#endif

