#pragma once
#include <string>
using namespace std;


class Player {

protected:
	string first_name;
	string last_name;
	string current_club;
	string preferred_club_1;
	string preferred_club_2;
	int signing_on_fee_demand;
	unsigned int age;
	int value;
	int current_wages;
	unsigned int current_contract_length;

public:

	//constructor
	Player(string first_name, string last_name, string current_club, string preffered_club_1, string preffered_club_2,
		int signing_on_fee_demand, unsigned int age, int value, int current_wages, unsigned int current_contract_length);
	//destructor
	~Player() = default;
	//getters
	string get_first_name() { return first_name; }
	string get_last_name() { return last_name; }
	string get_current_club() { return current_club; }
	string get_preffered_club_1() { return preferred_club_1; }
	string get_preffered_club_2() { return preferred_club_2; }
	int get_signing_on_fee_demand() { return signing_on_fee_demand; }
	unsigned int get_age() { return age; }
	int get_value() { return value; }
    int get_current_wages() { return current_wages; }
	unsigned int get_current_contract_length() { return current_contract_length; }


};


