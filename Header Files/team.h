#include "player.h"
#include <vector>

class Team {
    public:
        Team();
        std::string name,firstInnings,secondInnings;
        int selected[4],playerId,totalRunsScored,wicketsLost,totalBallsBowled;
        bool tossWinner;
        std::vector<Player> players;
};
