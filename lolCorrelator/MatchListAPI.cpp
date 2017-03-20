#pragma once

#include "MatchListAPI.h"

MatchListAPI::MatchListAPI(RiotAPIReaderWrapper * reader){
	if (reader == nullptr)
		apiReader = new RiotAPIReader(SERVER_REGION::NORTH_AMERICA);// , "http://proxy.cat.com:80");
	else
		apiReader = reader;
}

std::map<std::string, MatchListData> MatchListAPI::getSummonerMatchList(APIParameters params, URLBuilderWrapper * urlBuilder){
	URLBuilderWrapper* url;
	if (urlBuilder == nullptr)
		url = new MatchListURLBuilder(params);
	else
		url = urlBuilder;

	auto apiResponse = apiReader->callAPI(url->getURL());
	return apiReader->parseData<MatchListAPI, MatchListData>(apiResponse, this, &MatchListAPI::parseJsonIntoMatchListData);
}

APIParameters MatchListAPI::setupMatchListParams(){
	APIParameters params;
	std::vector<std::string> vec;

	vec.push_back("ByName");
	params.api = APIType::MatchList;
	params.parameters["Type"] = vec;

	return params;
}

MatchListData MatchListAPI::parseJsonIntoMatchListData(JsonWrapper * json){
	MatchListData matchListData;
	matchListData.startIndex = stoi(json->read("startIndex"));
	matchListData.endIndex = stoi(json->read("endIndex"));
	matchListData.totalGames = stoi(json->read("totalGames"));
	matchListData.matches = parseMatchData(json->dumpByElement("matches"));
	return matchListData;
}

std::vector<MatchListSingleData> MatchListAPI::parseMatchData(std::vector<string> data, JsonWrapper * json){
	MatchListSingleData matchData;
	std::vector<MatchListSingleData> matches;
	if (json == nullptr)
		json = JsonFactory().createJson(JsonParserType::Lohmann);
	for (auto& matchDataRaw : data) {
		json->parseJson(matchDataRaw.c_str());
		matchData.timestamp = json->read("timestamp");
		matchData.champion = stoi(json->read("champion"));
		matchData.region = json->read("region");
		matchData.queue = json->read("queue");
		matchData.season = json->read("season");
		matchData.matchId = json->read("matchId");
		matchData.role = json->read("role");
		matchData.platformId = json->read("platformId");
		matchData.lane = json->read("lane");

		matches.push_back(matchData);
	}
	return matches;
}
