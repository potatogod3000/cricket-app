#include "game.h"
using namespace std;

Game::Game() {
    playersPerTeam=4,maxBalls=6,totalPlayers=11;

    player[0]="Rohit Sharma",player[1]="Rishabh Pant",player[2]="Virat Kohli",
    player[3]="Suryakumar Yadav",player[4]="Deepak Hooda",player[5]="Hardik Pandya",player[6]="Dinesh Karthik";
    player[7]="Buvaneshwar Kumar",player[8]="Jasprit Bumrah",player[9]="Arshdeep Singh",player[10]="Yuzvendra Chahal";

    isFirstInnings=false;
    teamA.name="Team A";
    teamB.name="Team B";
    teamA.playerId=0;
	teamB.playerId=0;
    teamA.tossWinner=false;
    teamB.tossWinner=false;
}

void Game::welcome() {
        cout<<"|-------------------------------------|"<<endl;
        cout<<"|   ::Welcome to the Cricket game::   |"<<endl;
        cout<<"|-------------------------------------|"<<endl<<endl;

        cout<<"|-------------------------------------|"<<endl;
        cout<<"|            <Instructions>           |"<<endl;
        cout<<"|-------------------------------------|"<<endl;
        cout<<"|                                     |"<<endl;
        cout<<"| 1. Create 2 teams with 4 players    |"<<endl;
        cout<<"|    each from the given 11 players.  |"<<endl;
        cout<<"| 2. Toss will decide who bats first. |"<<endl;
        cout<<"| 3. Each innings will be of 6 balls. |"<<endl;
        cout<<"|-------------------------------------|"<<endl;
    }

void Game::displayPlayersList() {
	cout<<"|------------------------------------|"<<endl;
	cout<<"|          ::PLAYERS LIST::          |"<<endl;
	cout<<"|------------------------------------|"<<endl;

	for(int i=0;i<11;i++) {
		cout<<"|>>"<<i+1<<"\t"<<player[i]<<endl;
	}
	cout<<"|------------------------------------|"<<endl<<endl;
}

bool Game::validPlayers(int selection) {
	int n;
	vector<Player> players;

	players=teamA.players;
	n=players.size();
	for (int i=0;i<n;i++) {
		if (players[i].id==selection) {
			return false;
		}
	}

	players=teamB.players;
	n=players.size();
	for (int i=0;i<n;i++) {
		if (players[i].id==selection) {
			return false;
		}
	}

	return true;
}

void Game::selection() {
	int selection=0;

	cout<<"|------------------------------------|"<<endl;
	cout<<"|        ::Player Selection::        |"<<endl;
	cout<<"|------------------------------------|"<<endl<<endl;

//Selecting Team A Players and Displaying as confirmation.
	cout<<"\nEnter the ID of players that you want to select in Team A (Any 4)..."<<endl;
	for(int i=0;i<playersPerTeam;i++) {
		cout<<"Player "<<i+1<<" for Team A:- ";

		SelectionA:
			while (!(cin>>selection&&selection>0&&selection<totalPlayers+1)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"Please enter a valid selection ID for Player "<<i+1<<" in Team A:- ";
			}
			if (!validPlayers(selection)) {
				cout<<"Players has already been selected! Please select another player for Team A..."<<endl;
				cout<<"Player "<<i+1<<" for Team A:- ";
				goto SelectionA;
			}

		teamA.selected[i]=selection;
		Player teamAPlayer;
		teamAPlayer.id=teamA.selected[i];
		teamAPlayer.name=player[teamAPlayer.id-1];
		teamA.players.push_back(teamAPlayer);
	}

//Selection of Team B Players and displaying as confirmation.

	cout<<"\nEnter the ID of players that you want to select in Team B (Any 4)..."<<endl;
	for(int k=0;k<playersPerTeam;k++) {
		cout<<"Player "<<k+1<<" for Team B:- ";

		SelectionB:
			while (!(cin>>selection&&selection>0&&selection<totalPlayers+1)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"Please enter a valid selection number for Player "<<k+1<<" in Team B:- ";
			}
			if (!validPlayers(selection)) {
				cout<<"Players have already been selected! Please select another player for Team B..."<<endl;
				cout<<"Player "<<k+1<<" for Team B:- ";
				goto SelectionB;
			}

	teamB.selected[k]=selection;
	Player teamBPlayer;
	teamBPlayer.id=teamB.selected[k];
	teamBPlayer.name=player[teamBPlayer.id-1];
	teamB.players.push_back(teamBPlayer);
	}
}

void Game::displayTeam() {

	cout<<"|------------------------------------|"<<endl;
	cout<<"|   The Players selected in Team A   |"<<endl;
	cout<<"|------------------------------------|"<<endl;

	for(int j=0;j<playersPerTeam;j++) {
	cout<<"|>> "<<teamA.selected[j]<<" ";
	teamA.playerId=teamA.selected[j]-1;
	cout<<player[teamA.playerId]<<endl;
	}
	cout<<"|------------------------------------|"<<endl;
	cout<<endl;

	cout<<"|------------------------------------|"<<endl;
	cout<<"|   The Players selected in Team B   |"<<endl;
	cout<<"|------------------------------------|"<<endl;

	for(int l=0;l<playersPerTeam;l++) {
	cout<<"|>> "<<teamB.selected[l]<<" ";
	teamB.playerId=teamB.selected[l]-1;
	cout<<player[teamB.playerId]<<endl;
	}
	cout<<"|------------------------------------|"<<endl;
	cout<<endl;
}

void Game::toss() {

	cout<<"|------------------------------------|"<<endl;
	cout<<"|        ::It's Toss Time!!::        |"<<endl;
	cout<<"|------------------------------------|"<<endl<<endl;
	cout<<"The coin is being tossed... "<<endl;
	usleep(2000000);

	srand(time(NULL));
	int toss=rand()%2;

	switch(toss){
	case 0:
		teamA.tossWinner=true;
		cout<<"The toss is won by Team A."<<endl<<endl;
		break;
	case 1:
		teamB.tossWinner=true;
		cout<<"The toss is won by Team B."<<endl<<endl;
		break;
	}

	int selection;
	cout<<"Enter 1 to bat or 2 to bowl:- ";
	while (!(cin>>selection&&(selection==1||selection==2))) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"Please enter a valid input [1 - bat or 2 - bowl]:- ";
	}
	switch (selection) {
	case 1:
		if (teamA.tossWinner==true) {
			cout<<endl<<"Team A has won the toss and elected to bat first."<<endl;
			battingTeam=&teamA;
			bowlingTeam=&teamB;
			teamA.firstInnings="Batting";
			teamB.firstInnings="Batting";
			teamA.secondInnings="Bowling";
			teamB.secondInnings="Bowling";
		} else {
			cout<<endl<<"Team B has won the toss and elected to bat first."<<endl;
			bowlingTeam=&teamA;
			battingTeam=&teamB;
			teamA.firstInnings="Bowling";
			teamB.firstInnings="Batting";
			teamA.secondInnings="Batting";
			teamB.secondInnings="Bowling";
		}
		break;
	case 2:
		if (teamA.tossWinner==true) {
			cout<<endl<<"Team A has won the toss and elected to bowl first."<<endl;
			battingTeam=&teamB;
			bowlingTeam=&teamA;
			teamA.firstInnings="Bowling";
			teamB.firstInnings="Batting";
			teamA.secondInnings="Batting";
			teamB.secondInnings="Bowling";
		} else {
			cout<<endl<<"Team B has won the toss and elected to bowl first."<<endl;
			bowlingTeam=&teamB;
			battingTeam=&teamA;
			teamA.firstInnings="Batting";
			teamB.firstInnings="Bowling";
			teamA.secondInnings="Bowling";
			teamB.secondInnings="Batting";
		}
		break;
	}
	usleep(2000000);
}

void Game::firstInnings() {

	cout<<endl<<endl;
	cout<<"|----------------------------------------|"<<endl;
	cout<<"|       F I R S T    I N N I N G S       |"<<endl;
	cout<<"|----------------------------------------|"<<endl<<endl;

	//Initializing batsman and bowler pointers
	batsman=&battingTeam->players[0];
	bowler=&bowlingTeam->players[0];

	cout<<battingTeam->name<<" Batsman - "<<batsman->name<<"."<<endl;
	cout<<bowlingTeam->name<<" Bowler - "<<bowler->name<<"."<<endl;

	//Innings loop
	cin.ignore();
	for (int i=0;i<maxBalls;i++) {
		cout<<endl<<"Press Enter to bowl ball "<<i+1<<"...";
		getchar();

		srand(time(NULL));
		int runsScored=rand()%7;

		cout<<bowler->name<<" to "<<batsman->name<<"... ";
		usleep(2000000);

		//Displaying Runs and Checking Whether Out
		if (runsScored!=0&&runsScored!=5) {
			cout<<runsScored<<" RUN(S)!"<<endl;

			batsman->runsScored+=runsScored;
			batsman->ballsPlayed+=1;
			battingTeam->totalRunsScored+=runsScored;
		} else if (runsScored==0) {
			bowler->wicketsTaken+=1;
			battingTeam->wicketsLost+=1;
			batsman->ballsPlayed+=1;
			cout<<runsScored<<" => OUT!!"<<endl<<batsman->name<<" - "<<batsman->runsScored<<" ("<<batsman->ballsPlayed<<")."<<endl;

			int nextPlayerID=bowler->wicketsTaken;
			batsman=&battingTeam->players[nextPlayerID];
			cout<<"The next batsman in is "<<batsman->name<<"."<<endl;
		} else {
			cout<<runsScored<<" => WIDE and 4 RUNS!!"<<endl;

			battingTeam->totalRunsScored+=runsScored;
			i--;
		}

		//bowling team
		bowler->ballsBowled+=1;
		bowler->runsGiven+=runsScored;
		bowlingTeam->totalBallsBowled+=1;

		if (bowler->wicketsTaken==playersPerTeam) {
			break;
		}
	}

	cout<<"|----------------------------------------|"<<endl;
	cout<<"|  E N D  O F  F I R S T  I N N I N G S  |"<<endl;
	cout<<"|----------------------------------------|"<<endl;
	cout<<"|=> "<<battingTeam->name<<" -> "<<battingTeam->totalRunsScored<<"-"<<battingTeam->wicketsLost<<" (1)"<<endl;
	cout<<"|=> "<<bowlingTeam->name<<" -> "<<bowler->name<<" - "<<bowler->wicketsTaken<<"/"<<bowler->runsGiven<<" (1)"<<endl;
	cout<<"|----------------------------------------|"<<endl;
}

void Game::secondInnings() {

	cout<<endl<<endl;
	cout<<"|----------------------------------------|"<<endl;
	cout<<"|      S E C O N D    I N N I N G S      |"<<endl;
	cout<<"|----------------------------------------|"<<endl<<endl;

	//Initializing batsman and bowler pointers
	if (teamA.secondInnings=="Bowling"&&teamB.firstInnings=="Bowling") {
		bowlingTeam=&teamA;
		battingTeam=&teamB;
	} else if (teamB.secondInnings=="Bowling"&&teamA.firstInnings=="Bowling") {
		bowlingTeam=&teamB;
		battingTeam=&teamA;
	}

	batsman=&battingTeam->players[0];
	bowler=&bowlingTeam->players[0];

	cout<<battingTeam->name<<" Batsman - "<<batsman->name<<"."<<endl;
	cout<<bowlingTeam->name<<" Bowler - "<<bowler->name<<"."<<endl;

	//Innings loop
	cin.ignore();
	for (int i=0;i<maxBalls;i++) {
		cout<<endl<<"Press Enter to bowl ball "<<i+1<<"...";
		getchar();

		srand(time(NULL));
		int runsScored=rand()%7;

		cout<<bowler->name<<" to "<<batsman->name<<"... ";
		usleep(2000000);

		//Displaying Runs and Checking Whether Out
		if (runsScored!=0&&runsScored!=5) {
			cout<<runsScored<<" RUN(S)!"<<endl;

			batsman->runsScored+=runsScored;
			batsman->ballsPlayed+=1;
			battingTeam->totalRunsScored+=runsScored;
		} else if (runsScored==0) {
			bowler->wicketsTaken+=1;
			battingTeam->wicketsLost+=1;
			batsman->ballsPlayed+=1;
			cout<<runsScored<<" => OUT!!"<<endl<<batsman->name<<" - "<<batsman->runsScored<<" ("<<batsman->ballsPlayed<<")."<<endl;

			int nextPlayerID=bowler->wicketsTaken;
			batsman=&battingTeam->players[nextPlayerID];
			cout<<"The next batsman in is "<<batsman->name<<"."<<endl<<endl;
		} else {
			cout<<runsScored<<" => WIDE and 4 RUNS!!"<<endl;

			battingTeam->totalRunsScored+=runsScored;
			i--;
		}

		//Bowling Team
		bowler->ballsBowled+=1;
		bowler->runsGiven+=runsScored;
		bowlingTeam->totalBallsBowled+=1;
		if (bowler->wicketsTaken==playersPerTeam) {
			break;
		}

		/*Deciding Winner (USE RUNSREQUIRED TO DECIDE WINNER)
		if () {
			cout<<""<<endl;
			break;
		} else if () {
			cout<<""<<endl;
			break;
		}
		*/
	}

	cout<<"|----------------------------------------|"<<endl;
	cout<<"| E N D  O F  S E C O N D  I N N I N G S |"<<endl;
	cout<<"|----------------------------------------|"<<endl;
	cout<<"|=> "<<battingTeam->name<<" -> "<<battingTeam->totalRunsScored<<"-"<<battingTeam->wicketsLost<<" (1)"<<endl;
	cout<<"|=> "<<bowlingTeam->name<<" -> "<<bowler->name<<" - "<<bowler->wicketsTaken<<"/"<<bowler->runsGiven<<" (1)"<<endl;
	cout<<"|----------------------------------------|"<<endl;
}

void Game::winner() {

}
