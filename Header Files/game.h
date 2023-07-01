#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unistd.h>
#include "team.h"

class Game {
    public:
        Game();
        std::string player[11];
        int playersPerTeam,maxBalls,totalPlayers;
        bool isFirstInnings;

        Team teamA,teamB;
        Team *bowlingTeam,*battingTeam;
        Player *batsman,*bowler;

        void welcome();
        void displayPlayersList();
        void selection();
        bool validPlayers(int);
        void displayTeam();
        void toss();
        void firstInnings();
        void secondInnings();
        void batting();
        void winner();
};
