#include "Team.h"

Team::Team(string name, string funds, int agent_fee, int wage_offer, int signing_on_fee_offer)
	:name{ name }, funds{ funds }, agent_fee{ agent_fee }, wage_offer{ wage_offer }, signing_on_fee_offer{ signing_on_fee_offer }{

}

//add agreed wage numbers into team object
void Team::add_wage_offer(long wage)
{
	wage_offer = wage;
}

//add agreed signing fee numbers into team object
void Team::add_signing_on_fee_offer(long signing_on_fee) {
	signing_on_fee_offer = signing_on_fee;
}
