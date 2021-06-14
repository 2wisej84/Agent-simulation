#pragma once
#include "Team.h"
#include "Player.h"
#include <iostream>
#include"Manipulate_string.h"
using namespace std;

bool signing_on_fee_offer(Player client, Team &team);
bool can_team_afford_signing_on_fee(Team team, int signing_on_fee);

