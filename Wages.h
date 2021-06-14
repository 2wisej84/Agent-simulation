#pragma once
#include "Team.h"
#include "Player.h"
#include <iostream>
#include "Current_Club_Negotiations.h"

bool wages_offer(Player client, Team &team);
bool can_team_afford_wages(Team team, int wages, Player client);

