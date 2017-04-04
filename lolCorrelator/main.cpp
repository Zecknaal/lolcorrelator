#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "RiotAPIReader.h"
#include "RiotAPIManager.h"

#pragma once

int main() {
	RiotAPIManager api = RiotAPIManager();

	std::vector<std::string> vec2;
	//vec2.push_back("azhi%20dahaki");
	vec2.push_back("zecknaal");
	api.readSummonerData(vec2);
	for (auto& summonerData : api.readSummonerData(vec2)) {
		std::cout << summonerData.second.id << std::endl;
		auto matchData = api.readMatchListData(summonerData.second.id)["result"].matches;
		for (auto& match : matchData) {
			std::cout << "sending" << std::endl;
			auto data = api.readMatchData(match.matchId)["result"].season;
			std::cout << data << std::endl;
		}
	}
	std::cin.get();
	return 0;
}