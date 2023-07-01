#include "game.h"
using namespace std;

int main() {
    Game game;

    game.welcome();
    cout<<"\nPress Enter to continue..."<<endl<<endl<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    game.displayPlayersList();
    cout<<"\nPress Enter to continue..."<<endl<<endl<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    game.selection();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"\nPress Enter to display Team A and Team B..."<<endl<<endl<<endl;
    cin.ignore();

    game.displayTeam();
    cout<<"\nPress Enter to toss the coin..."<<endl<<endl<<endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    game.toss();

    game.firstInnings();

    game.secondInnings();

    game.winner();
}
