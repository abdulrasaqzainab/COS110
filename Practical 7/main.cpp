#include <iostream>
#include <sstream>
#include <string>
#include<cstddef>

#include "Dictionary.h"
#include "Dictionary.cpp"
#include "Tuple.h"
#include "Tuple.cpp"
#include "ScoreBoard.h"
#include "ScoreBoard.cpp"

using namespace std;

void test()
{
    
    
}


int main()
{
   Dictionary<std::string, int> mydictionary;
    mydictionary.set("Alice", 42);
    mydictionary.set("Bob", 55);
    mydictionary.set("Charlie", 30);

    std::cout << "Alice's score: " <<mydictionary.at("Alice") << std::endl;
    std::cout << "Bob's score: " << mydictionary.at("Bob") << std::endl;
    std::cout << "Charlie's score: " << mydictionary.at("Charlie") << std::endl;

    mydictionary.removeAt("Bob");
    std::cout << "After removing Bob, size: " << mydictionary.size() << std::endl;

    // Test Tuple
    Tuple<int, std::string> t(1, "a");
    std::cout << "Tuple t: " << t.getFirst() << ", " << t.getSecond() << std::endl;

    // Test ScoreBoard
    ScoreBoard<int> scoreboard;
    scoreboard.addScore("Alice", 100);
    scoreboard.addScore("Bob", 75);
    scoreboard.addScore("Charlie", 120);
    scoreboard.addScore("David", 90);

    std::cout << "Alice's score: " << scoreboard.getScore("Alice") << std::endl;
    std::cout << "High score: " << scoreboard.getHighScore() << std::endl;

    Tuple<int, std::string*> highScoreUsers = scoreboard.getHighScoreUser();
    std::cout << "High score users: ";
    
    std::cout << std::endl;
Tuple<int, double> tuple1(10, 20.5);
    Tuple<int, double> tuple2(10, 20.5);

    // Compare the two tuples using the == operator
    if (tuple1 == tuple2) {
        std::cout << "tuple1 and tuple2 are equal." << std::endl;
    } else {
        std::cout << "tuple1 and tuple2 are not equal." << std::endl;
    }
// bool store=(dict==t);
//     std::cout<<store;
std::cout<<"--------------------------------------------------------------------------------"<<std::endl;
//test();

ScoreBoard<int> scoreBoard;

    // Add scores for users
    scoreBoard.addScore("Alice", 100);
    scoreBoard.addScore("Bob", 75);
    scoreBoard.addScore("Charlie", 120);
    scoreBoard.addScore("David", 80);
    scoreBoard.addScore("Eve", 130);
    
    // Get and display scores
    std::cout << "Scores:" << std::endl;
    std::cout << "Alice: " << scoreBoard.getScore("Alice") << std::endl;
    std::cout << "Bob: " << scoreBoard.getScore("Bob") << std::endl;
    std::cout << "Charlie: " << scoreBoard.getScore("Charlie") << std::endl;
    std::cout << "David: " << scoreBoard.getScore("David") << std::endl;
    std::cout << "Eve: " << scoreBoard.getScore("Eve") << std::endl;

    // Get and display the highest score
    std::cout << "Highest Score: " << scoreBoard.getHighScore() << std::endl;

    // Get and display users with the highest score
    Tuple<int, std::string*> highScoreUsers1 = scoreBoard.getHighScoreUser();
    std::cout << "Users with the Highest Score:" << std::endl;
    for (int i = 0; i < highScoreUsers1.getFirst(); i++) 
    {
        std::cout << "Do we enter the for loop" << std::endl;
     std::cout << highScoreUsers1.getSecond()[i] << std::endl;//whats wrong
    }
    std::cout << "We are outside the for loop" << std::endl;

    // Remove a user
    scoreBoard.removeScore("Bob");

    std::cout << "We have removed Bob from the list" << std::endl;

    // Get and display the updated highest score
   // std::cout << "Highest Score (after removing Bob): " << scoreBoard.getHighScore() << std::endl;

    Tuple<int,string*> test= scoreboard.getHighScoreUser();
    cout << test.getSecond()[0] << std::endl;

    std::cout << "We have reached the end of the program" << std::endl;
delete[] test.getSecond();
delete[] highScoreUsers1.getSecond();
delete[] highScoreUsers.getSecond();
    return 0;
}
