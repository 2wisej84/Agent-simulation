#include "Signing_on_fee.h"


bool signing_on_fee_offer(Player client, Team &team) {

	//put name of player into a string. easier to use
	string client_name = client.get_last_name();
	//convert name to lowercase
	client_name = convertlower(client_name);
	//put name of team into a string
	string team_name = team.get_name();
	
	//if team is players current team
	if (team_name == client.get_current_club()) {
		cout << team_name << ": We would like to offer " << client_name << " a signing on bonus for signing a new contract with us. ";
		cin.ignore();
		cin.get();
	}

	cout << team_name << ": How big of a signing on bonus does " << client_name << " want?: "; 

	int signing_on_fee;
	//counts how many times the  demands werent accepted. as will get a different output message from the club each time
	int count_how_may_offers = 1;
	bool can_match_signing_on_fee = false;
	//stay in loop while no agreement has been reached. is given an option to exit negotiations after 3 attempts
	while (can_match_signing_on_fee == false) {
		cin >> signing_on_fee;
		bool result = can_team_afford_signing_on_fee(team, signing_on_fee);
		if (result == true) {
			cout << team_name << " Fantastic! We are happy to pay this amount. " << endl;
			cout << team_name << ": Are you happy to confirm these numbers for the signing on fee? (yes/no): ";
			string confirm;
			bool valid = false;
			//stays in loop until confirm equals "yes" or "no"
			while (valid == false) {
				cin >> confirm;
				if (confirm == "yes") {
					valid = true;
					//add agreement into team "signing on fee offer" variable 
					team.add_signing_on_fee_offer(signing_on_fee);
					can_match_signing_on_fee = true;
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
				cout << team_name << " We are unable to match these demands. The chairman will not sign this off. Enter new number: ";
				count_how_may_offers++;

			}
			else if (count_how_may_offers == 2) {
				cout << team_name << " We are still unable to match this sort of bonus. But we are getting closer. Enter new number: " ;
				count_how_may_offers++;
			}

			else if (count_how_may_offers == 3) {
				cout << team_name << " This is still out of our budget. We may not be able to come to an agreement. Would you like to exit negotiations or carry on?" << endl;
				cout << "EXIT NEGOTIATIONS? (yes/no): ";
				string exit;
				cin >> exit;
				if (exit == "yes")
					break;
				else if (exit == "no") {
					cout << team_name << ": Enter new number: ";
					continue;
				}
				else
					cout << "INVALID INPUT SELECTED" << endl;
			}
		}
	}

	return can_match_signing_on_fee;

}

bool can_team_afford_signing_on_fee(Team team, int signing_on_fee) {
	
	// if team object funds are high, then they can afford bigger wages
	if (team.get_funds() == "HIGH") {
		{
			//return true if sinign fee demand is equal or less than 10 million
			if (signing_on_fee <= 10000000)
				return true;
			else
				return false;
		}

	}

	else if (team.get_funds() == "MEDIUM") {
		if (signing_on_fee <= 5000000)
			return true;
		else
			return false;

	}

	else
		if (signing_on_fee <= 2000000)
			return true;
		else
			return false;


}