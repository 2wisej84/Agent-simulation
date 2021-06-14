#include "Choose_Player.h"
#include <iostream>
using namespace std;

Player choose_player(vector<Player> players) {
 
	// if the users input doesnt match any of the listed players, an error message will show and will stay in the loop
	bool user_input = false;
	while (user_input == false) {
		string selection;
		//get user input and store in selection
		getline(cin, selection);
		//convert input to uppercase as thats how the names are stored in Team.txt file
		convertupper(selection);
	  // if input matches a name, return that player object
		for (int i = 0; i < players.size(); i++) {
			if (selection == players[i].get_last_name()) {
				user_input = true;
				return players[i];
			}
		}
		if (user_input == false)
			cout << "Incorrect input. Please check your spelling" << endl;
	}
}




