#ifndef SCOREBOARD_CPP
#define SCOREBOARD_CPP

// #include "Dictionary.h"
// #include "Dictionary.cpp"
// #include "Tuple.h"
// #include "Tuple.cpp"
#include "ScoreBoard.h"
#include <iostream>
// #include <sstream>
// #include <string>
// #include<cstddef>

template <class T>
ScoreBoard<T>::ScoreBoard()
{
    //do nothing
}

template <class T>
ScoreBoard<T>::~ScoreBoard()
{
    //do nothing
}

template <class T>
void ScoreBoard<T>::addScore(std::string user,T score)
{
   T curr=scores.at(user);
   if(score>curr)
   {
    scores.set(user,score);
   }
}

template <class T>
void ScoreBoard<T>::removeScore(std::string user)
{
    //scores.remove(user);
// if(scores.exists(user)){
// //return;


//     Dictionary<std::string,T> score_new;

//     for(int x=0;x<scores.size();x++)
//     {
//         std::string curr=scores.getKeys()[x];

//         if(curr!= user)
//         {
//             score_new.set(curr,scores.at(curr));
//         }
//     }

//     scores=score_new;
//     }

    scores.removeAt(user);

}


template <class T>
T ScoreBoard<T>::getScore(std::string user)
{
    return scores.at(user);
}

template <class T>
T ScoreBoard<T>::getHighScore()
{
    if(scores.size()==0)
    {
        return T();
    }

    T highest=scores.at(scores.getKeys()[0]);

    for(int x=1;x<scores.size();x++)
    {
        T curr=scores.at(scores.getKeys()[x]);

        if(curr>highest)
        {
            highest=curr;
        }
    }

    return highest;
}

template <class T>
Tuple<int,std::string*> ScoreBoard<T>::getHighScoreUser()
{
  //  T highest=getHighScore();

    // int count=0;

    // for(int x=0;x<scores.size();x++)
    // {
    //     if(scores.at(scores.getKeys()[x])==highest)
    //     {
    //         count++;
    //     }
    // }


    // if(count==0)
    // {
    //   //Tuple<int,std::string*> temp(0,NULL);

    //     return Tuple<int,std::string*>(0,NULL);
    // }

    // std::string* userhighest=new std::string[count];

    // int idx=0;
    

    // for(int x=0;x<scores.size();x++)
    // {
    //     if(scores.at(scores.getKeys()[x])==highest)
    //     {
    //         userhighest[idx++]=scores.getKeys()[x];
    //     }
    // }
    

    

    

    // Tuple<int,std::string*> result(count,userhighest);

    // delete[] userhighest;

   return scores.keysWithValue(getHighScore());

    //return result;
}



#endif