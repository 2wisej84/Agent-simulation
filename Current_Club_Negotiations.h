#pragma once
#include "Player.h"
#include "Team.h"
#include "Wages.h"
#include "Manipulate_string.h"
#include <vector>
#include <iostream>
#include <iomanip>



Team get_team(vector<Team> teams, Player client, string club);
bool club_contract_offer(Team &club, Player client);
