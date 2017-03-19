#pragma once

#include "SummonerAPI.h"
#include "MatchListAPI.h"
#include "MatchAPI.h"

#include <iostream>
#include <vector>
#include <map>

class RiotAPIManager {
	public:
		RiotAPIManager();
		
		std::map<std::string, SummonerData> readSummonerData(std::vector<string> summonerNames);
		std::map<std::string, MatchListData> readMatchListData(int summonerID);
		std::map<std::string, MatchData> readMatchData(std::string matchID);
	protected:
		std::string readKey();
		SummonerAPI* summonerAPI;
		MatchListAPI* matchListAPI;
		MatchAPI* matchAPI;
};