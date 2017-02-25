#pragma once

#include "SummonerAPI.h"

#include <iostream>

class RiotAPIManager {
	public:
		RiotAPIManager();
		
		void readSummonerData();
	protected:
		std::string readKey();
		SummonerAPI* summonerAPI;
};