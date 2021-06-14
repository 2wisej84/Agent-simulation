#pragma once
using namespace std;
#include <string>
class Team
{
protected:
	string name;
	string funds;
	int agent_fee;
	int wage_offer;
	int signing_on_fee_offer;
public:
	//constructor
	Team(string name, string funds, int agent_fee, int wage_offer, int signing_on_fee_offer);
	//destructor
	~Team() = default;

	//methods
	void add_wage_offer(long wages);
	void add_signing_on_fee_offer(long signing_on_fee);
	string get_name() {return name;}
	string get_funds() {return funds; }
	int get_agent_fee() { return agent_fee; }
	int get_wage_offer() { return wage_offer; }
	int get_signing_on_fee_offer() { return signing_on_fee_offer; }



};

