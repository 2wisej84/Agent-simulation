#include <iostream>
#include <iomanip>
#include "Player.h"
#include "Create_Player_and_Team.h"
#include <vector>
#include "Team.h"
#include "Choose_Player.h"
#include "Current_Club_Negotiations.h"
#include "Manipulate_string.h"

using namespace std;


void display_agreements(int margin, Team team);
int main() {

	const string welcome{ "WELCOME TO YOUR AGENT SIMULATION." };
	const string task{ "YOU WILL BE WORKING FOR ELITE SPORTS MANAGEMENT, WHERE YOU CAN SHOWCASE AND DEVELOP YOUR SKILLS AS AN AGENT." };
	const string player{ "YOU WILL BE GIVEN A SELECTION OF THE HIGHEST RATED PLAYERS IN THE GAME. IT IS YOUR JOB TO FIND THE BEST CONTRACT FOR YOUR CLIENT." };
	const string continue_ = { "Press Enter to keep progressing through the program. " };
	cout << "\n\n";
	//create space on each side of text to allow text to be in the middle
	cout << setw((full_width - welcome.length()) / 2) << "" << welcome << endl << endl;
	cout << setw((full_width - task.length()) / 2) << "" << task << endl << endl;
	cout << setw((full_width - player.length()) / 2) << "" << player << endl << endl;
	cout << setw((full_width - continue_.length()) / 2) << "" << continue_;
	cin.get();
	//add dashes across the screen
	cout << setw(full_width) << setfill('-') << "" << endl;
	//reseting setfill method to default-otherwise all spaces would be filled with dashes 
	cout << setfill(' ') << "" << endl;

	//the margin variable gives an integer of how far across text should start on the screen, which allows text to be centered
	int margin = (full_width - 165) / 2;
	//returns a vector of all players available
	vector<Player> players = Create_Player();
	//returns a vector of all teams that can negotiate with
	vector<Team> teams = Create_Team();


	cout << "\n\n";
	string selection{ "Below is the selection of players available." };
	cout << setw((full_width - selection.length()) / 2) << left << "" << selection << endl << endl;
	cout << setw(margin) << left << "" << setw(20) << left << "NAME"
		<< setw(25) << left << "CURRENT CLUB"
		<< setw(25) << left << "FIRST PREFFERED CLUB"
		<< setw(25) << left << "SECOND PREFFERED CLUB"
		<< setw(10) << left << "AGE"
		<< setw(20) << left << "MARKET VALUE"
		<< setw(20) << left << "CURRENT WAGES"
		<< "YEARS LEFT ON CURRENT DEAL" << endl
		<< setw(margin) << left << "" << setw(165) << setfill('-') << "" << endl
		<< setfill(' ') << "";

	//convert value and wages into strings to allow commas in between numbers

	for (auto i : players) {
		cout << setw(margin) << left << "" << setw(20) << left << i.get_last_name()
			<< setw(25) << left << i.get_current_club()
			<< setw(25) << left << i.get_preffered_club_1()
			<< setw(25) << left << i.get_preffered_club_2()
			<< setw(10) << left << i.get_age()
			<< (char)156 << setw(20) << left << add_commas_to_values_and_wages(i.get_value())
			<< (char)156 << setw(20) << left << add_commas_to_values_and_wages(i.get_current_wages())
			<< i.get_current_contract_length() << endl << endl;

	}

	cout << "Enter the name of the player that you wish to manage: ";
	
	//function returns the player object that the user chose
	Player client = choose_player(players);
	//get a string of the chosen player, to allow easy use of nam
	string client_name = client.get_last_name();
	client_name = convertlower(client_name);

	cout << "You have chosen " << client_name << " to be your client. ";
	cin.get();
	//print dashes across screen
	cout << setw(full_width) << setfill('-') << "" << endl;
	cout << setfill(' ') << "" << endl;

	// create a table showing chosen players information
	cout << client_name << ": Below are the clubs " << client_name << " wants to sign for and his main demands. ";
	cin.get();
	cout << "\n";
	cout << setw(margin) << left << "" << setw(30) << left << "FIRST PREFFERED CLUB"
		<< setw(30) << left << "SECOND PREFFERED CLUB"
		<< setw(20) << left << "WAGE DEMAND"
		<< setw(25) << left << "SIGNING ON FEE DEMAND" << endl << endl;

	cout << setw(margin) << left << "" << setw(30) << left << client.get_preffered_club_1()
		<< setw(30) << left << client.get_preffered_club_2()
		<< (char)156 << setw(20) << left << add_commas_to_values_and_wages(client.get_current_wages() * 2)
		<< (char)156 << setw(25) << left << add_commas_to_values_and_wages(client.get_signing_on_fee_demand()) << endl << endl;



	cout << "You will now enter negotiations with " << client_name << "'s current club regarding a new contract. ";
	cin.get();
	cout << setw(full_width) << setfill('-') << "" << endl;
	cout << setfill(' ') << "" << endl;
	//returns chosen players current team
	Team client_current_team = get_team(teams, client, "current");

    //enters contract negotiaion function. returns true if wage and signing on fee were agreed
	bool terms_agreed = club_contract_offer(client_current_team, client);
	string current_team_name = client_current_team.get_name();
	current_team_name = convertlower(current_team_name);
	
	if (terms_agreed == true) {

		//display table of terms agreed 
		display_agreements(margin, client_current_team);

	}
	else {
		cout << "\nYou have not managed to agree terms with " << client_current_team.get_name() << ".";
		cin.get();
	}


	// now enters negotiations with the players preffered club
	//--------------------------------------------------------------

	// returns players preffered team 
	Team client_preffered_team = get_team(teams, client, "preffered");
	string preffered_team_name = client_preffered_team.get_name();
	preffered_team_name = convertlower(preffered_team_name);


	cout << "It is now time to hear offers from " << client_name << "'s Preffered club, which is " << client.get_preffered_club_1();
	cin.get();
	
	//enters contract negotiaion function. returns true if wage and signing on fee were agreed
	terms_agreed = club_contract_offer(client_preffered_team, client);

	if (terms_agreed == true)
		//display table of terms agreed 
		display_agreements(margin, client_preffered_team);
	
	else {
		cout << "\nYou have not managed to agree terms with " << client_current_team.get_name() << ".";
		cin.get();
	}
	
	cout << setw(full_width) << setfill('-') << "" << endl;
	cout << setfill(' ') << "" << endl;
	cout << "It is now time to hear what your client thinks and his final decision. ";
	cin.get();
	cout << endl;

	//if current team offfers more wages AND signing on fee, he will stay at current club. any other result, he will choose his preffered club
	if (client_current_team.get_wage_offer() > client_preffered_team.get_wage_offer() && client_current_team.get_signing_on_fee_offer() > client_preffered_team.get_signing_on_fee_offer())
		cout << client_name << " After looking at both contracts, my final decision is to sign for " << client_current_team.get_name() << "." << endl;
	else 
		cout << client_name<<  " After looking at both contracts, my final decision is to sign for " << client_preffered_team.get_name() << "." << endl;
	

	
		
}


void display_agreements(int margin, Team team) {

	cout << "\nYou have managed to agree terms with " << team.get_name() << ". Below are the numbers that you have agreed on. ";
	cin.get();

	cout << setw(margin) << left << "" << setw(20) << left << "WAGES"
		<< setw(25) << left << "SIGNING ON FEE"
		<< setw(25) << left << "AGENT FEES" << endl << endl;
	
	// puts numbers of terms into a string, to allow the adddition of commas into the sum to make it more readable
	cout << setw(margin) << left << "" << (char)156 << setw(19) << left << add_commas_to_values_and_wages(team.get_wage_offer())
		<< (char)156 << setw(24) << left << add_commas_to_values_and_wages(team.get_signing_on_fee_offer())
		<< (char)156 << setw(25) << left << add_commas_to_values_and_wages(team.get_agent_fee()) << endl << endl;
	


}

 
