#include "Wages.h"



bool wages_offer(Player client, Team &team) {
	//get name of client as a string
	string client_name = (client.get_last_name());
	client_name = convertlower(client_name);
	

	string team_name = team.get_name();
	//if team passed in is the players current club
	if (team_name == client.get_current_club()) {
		cout << team_name << ": We are aware that " << client_name << " is potentially looking for a move away from our club, So we would like to open negotiations regarding a new contract for him. ";
		cin.get();	
	}

	else {
		//if team passed in is players preffereed club
		cout << client.get_preffered_club_1() << ": We would like to offer " << client_name << " a contract, to persuade him to join our club. ";
		cin.get();
	}
		


	cout << team_name << ": Let's begin with discussing wages. Please enter the amount of wages per week you are looking for: ";
	int wages;
	//counts how many times the wage demands werent accepted. as will get a different output message from the club each time
	int count_how_may_offers = 1;
	bool can_match_wages = false;
	//will stay in loop until agreement is reached
	while (can_match_wages == false) {
		cin >> wages;
		//negotiation function where user inputs demands and club will accept or reject
		bool result = can_team_afford_wages(team, wages, client);
		if (result == true) {
			cout << team_name << ": Great! We are able to match these wage demands " << endl;
			cout << team_name << ": Are you happy to confirm these numbers for wages? (yes/no): ";
			string confirm;
			bool valid = false;
			//will stay in lopp until "confirm" vaiable reads yes or No
			while (valid == false) {
				cin >> confirm;
				if (confirm == "yes") {
					valid = true;
					team.add_wage_offer(wages);
					can_match_wages = true;
				}

				else if (confirm == "no") {
					cout << "Enter new wage demand: ";
					valid = true;
				}
				else {
					cout << "INVALID INPUT SELECTED" << endl;
					cout << "Enter yes or no: ";
				}
			}
		}
		else {
			if (count_how_may_offers == 1) {
				cout << team_name << " We are unable to match these demands. The chairman will not sign this off. Enter new wage demand: ";
				count_how_may_offers++;

			}
			else if (count_how_may_offers == 2) {
				cout << team_name << " We are still unable to match these wages. But we are getting closer. Enter new wage demand: ";
				count_how_may_offers++;
			}

			else if (count_how_may_offers == 3) {
				cout << team_name << " This is still out of our budget. We may not be able to come to an agreement. Would you like to exit negotiations for wages or carry on?" << endl;
				cout << "EXIT NEGOTIATIONS? (yes/no): ";
				string exit;
				cin >> exit;
				if (exit == "yes")
					break;
				else if (exit == "no") {
					cout << team_name << ": Enter new wage demand: ";
					continue;
				}
				else
					cout << "INVALID INPUT SELECTED" << endl;
			}
		}
	}

	//returns true if agreement was reached
	return can_match_wages;

}





bool can_team_afford_wages(Team team, int wages, Player client) {

	//calculate if team can afford wages 

	if (team.get_funds() == "HIGH") {
		{
			//if team funds are high, they can afford to pay this amount for wages
			if (wages <= 1500000)
				return true;
			else
				return false;
		}

	}

	else if (team.get_funds() == "MEDIUM") {
		if (wages <= 1000000)
			return true;
		else
			return false;

	}

	else
		if (wages <= 700000)
			return true;
		else
			return false;


}

