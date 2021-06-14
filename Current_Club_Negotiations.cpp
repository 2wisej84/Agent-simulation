#include "Current_Club_Negotiations.h"
#include "Signing_on_fee.h"

//returns euther players current club or preffered club, depending what string parameter was passed in 
Team get_team(vector<Team> teams, Player client, string club)
{
	if (club == "current") {
		for (auto i : teams) {
			if (client.get_current_club() == i.get_name())
				return i;
		}
	}
	else {
		for (auto i : teams) {
			if (client.get_preffered_club_1() == i.get_name())
				return i;
		}
	}
}





bool club_contract_offer(Team &club, Player client) {
	
	    //put name of club in a string
		string current_club_name = club.get_name();

		bool wages_agreed;
		//if wages are accepted
			if (wages_offer(client, club) == true) {
				cout << "You have successfully agreed on wages." << endl;
				wages_agreed = true;
				cout << setw(full_width) << setfill('-') << "" << endl;
				cout << setfill(' ') << "" << endl;

			}
			else {
				wages_agreed = false;
				 cout << "You was unable to agree on wages with " << current_club_name << ". You can revist negotiations for wages. You will now enter negotiations for a signing on fee." << endl;
				 cout << setw(full_width) << setfill('-') << "" << endl;
				 cout << setfill(' ') << "" << endl;
			}
			bool signing_on_fee_agreed;
			//if signing on fee was agreed
			if (signing_on_fee_offer(client, club) == true) {
				cout << "You have successfully agreed a signing on fee. ";
				signing_on_fee_agreed = true;
				cin.ignore();
				cin.get();
			}
			else {
				signing_on_fee_agreed = false;
				cout << "You was unable to agree on a signing on fee with " << current_club_name  << endl;
			}


			//agent fee
			cout << "\n" << current_club_name <<  ": The chairman has made it clear that the agent fees will be non negotiable. The club would like to pay you " << (char)156 << add_commas_to_values_and_wages(club.get_agent_fee()) << " for your services negotiating this deal.";
			cin.get();
	
			//if wages and signing on fee terms were both agreed, return true
			if (wages_agreed == true && signing_on_fee_agreed == true)
				return true;
			else
				return false;

}
