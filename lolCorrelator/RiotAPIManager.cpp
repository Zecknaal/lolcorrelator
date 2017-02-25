#include "RiotAPIManager.h"

RiotAPIManager::RiotAPIManager(){
	summonerAPI = new SummonerAPI();
}

void RiotAPIManager::readSummonerData(){
	APIParameters params;
	std::vector<std::string> vec;
	vec.push_back("ByName");
	std::vector<std::string> vec2;
	vec.push_back("Zecknaal");
	params.api = APIType::Summoner;
	params.region = SERVER_REGION::NORTH_AMERICA;
	params.key = readKey();
	params.parameters["Type"] = vec;
	params.parameters["summonerNames"] = vec2;

	std::cout << summonerAPI->getSummonerName(params);
}

std::string RiotAPIManager::readKey(){
	return "cf493893-d798-47e2-997f-adced88d62b9";
}
