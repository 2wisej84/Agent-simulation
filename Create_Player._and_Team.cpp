#include "Create_Player_and_Team.h"
using namespace std;
std::vector <Player> Create_Player() {

	//create file object
	ifstream in_file;
	in_file.open("Player_details.txt");
	if (!in_file)
		cerr << "Problem opening file" << endl;


	string first_name;
	string last_name;
	string current_club;
	string preferred_club_1;
	string preferred_club_2;
	long signing_on_fee_demand;
	unsigned int age;
	long value;
	long current_wages;
	unsigned int current_contract_length;


	//create string  objects to allow use of std::getline
	string age_string, value_string, current_wages_string, current_contract_length_string, signing_on_fee_demand_string;
	string line;
	//vector to place all the player objects into once created
	vector<Player> Players;

	//read in data from player_details.txt and place into string variable 
	while (getline(in_file, line)) {
		stringstream ss(line);
		getline(ss, first_name, '-');
		getline(ss, last_name, '-');
		getline(ss, current_club, '-');
		getline(ss, preferred_club_1, '-');
		getline(ss, preferred_club_2, '-');
		getline(ss, signing_on_fee_demand_string, '-');
		getline(ss, age_string, '-');
		getline(ss, value_string, '-');
		getline(ss, current_wages_string, '-');
		getline(ss, current_contract_length_string, '-');

		//convert string variables back into integers
		signing_on_fee_demand = stol(signing_on_fee_demand_string);
		age = stoi(age_string);
		value = stol(value_string);
		current_wages = stol(current_wages_string);
		current_contract_length = stoi(current_contract_length_string);

		Player player = { first_name, last_name, current_club, preferred_club_1, preferred_club_2, signing_on_fee_demand, age, value, current_wages, current_contract_length };
		Players.push_back(player);
	}
	

	in_file.close();
	return Players;

}


//--------------------------------------

vector <Team> Create_Team() {

	//create file object
	ifstream in_file;
	in_file.open("Team.txt");
	if (!in_file)
		cerr << "Problem opening file" << endl;


	string name;
	string funds;
	int agent_fee;
	int wage_offer;
	int signing_on_fee_offer;


	//create string  objects to allow use of std::getline
	string agent_fee_string, wage_offer_string, signing_on_fee_offer_string;
	string line;
	//vector to place all the player objects into once created
	vector<Team> teams;

	//read in data from player_details.txt and place into string variable 
	while (getline(in_file, line)) {
		stringstream ss(line);
		getline(ss, name, '-');
		getline(ss, funds, '-');
		getline(ss, agent_fee_string, '-');
		getline(ss, wage_offer_string, '-');
		getline(ss, signing_on_fee_offer_string, '-');


		//convert string variables back into integers
		agent_fee = stoi(agent_fee_string);
		wage_offer = stoi(wage_offer_string);
		signing_on_fee_offer = stoi(signing_on_fee_offer_string);
		
		//create team object with given variables and place into a vector
		Team team = { name, funds, agent_fee, wage_offer, signing_on_fee_offer };
		teams.push_back(team);
	}

	//close file
	in_file.close();
	return teams;

}