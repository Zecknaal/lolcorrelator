#include "RiotAPIManager.h"

RiotAPIManager::RiotAPIManager(){
	summonerAPI = new SummonerAPI();
	matchListAPI = new MatchListAPI();
	matchAPI = new MatchAPI();
}

std::map<std::string, SummonerData> RiotAPIManager::readSummonerData(std::vector<string> summonerNames){
	auto params = summonerAPI->setupByNameParams();
	params.region = SERVER_REGION::NORTH_AMERICA;
	params.key = readKey();
	params.parameters["summonerNames"] = summonerNames;

	return summonerAPI->getSummonerName(params);
}

std::map<std::string, MatchListData> RiotAPIManager::readMatchListData(int summonerID){
	auto params = matchListAPI->setupMatchListParams();
	params.region = SERVER_REGION::NORTH_AMERICA;
	params.key = readKey();

	std::vector<std::string> summonerIDs;
	summonerIDs.push_back(to_string(summonerID));
	params.parameters["summonerIDs"] = summonerIDs;

	return matchListAPI->getSummonerMatchList(params);
}

std::map<std::string, MatchData> RiotAPIManager::readMatchData(std::string matchID){
	auto params = matchAPI->setupMatchParams();
	params.region = SERVER_REGION::NORTH_AMERICA;
	params.key = readKey();

	std::vector<std::string> matchIDs;
	matchIDs.push_back(matchID);
	params.parameters["matchIDs"] = matchIDs;

	return matchAPI->getSummonerMatch(params);
}

std::string RiotAPIManager::readKey(){
	return "cf493893-d798-47e2-997f-adced88d62b9";
}
