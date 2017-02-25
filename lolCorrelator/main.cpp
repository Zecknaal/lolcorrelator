#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "RiotAPIReader.h"
#include "RiotAPIManager.h"

#pragma once

int main() {
	std::string url = "https://na.api.pvp.net/api/lol/na/v1.4/summoner/by-name/Zecknaal?api_key=cf493893-d798-47e2-997f-adced88d62b9";

	RiotAPIReader api(SERVER_REGION::NORTH_AMERICA, "http://proxy.cat.com:80");
	api.callAPI(url.c_str());
	RiotAPIManager apiapi = RiotAPIManager();
	apiapi.readSummonerData();
	std::cin.get();
	return 0;
}