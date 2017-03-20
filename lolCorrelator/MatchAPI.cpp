#include "MatchAPI.h"
#pragma once

MatchAPI::MatchAPI(RiotAPIReaderWrapper * reader){
	if (reader == nullptr)
		apiReader = new RiotAPIReader(SERVER_REGION::NORTH_AMERICA);// , "http://proxy.cat.com:80");
	else
		apiReader = reader;
}

std::map<std::string, MatchData> MatchAPI::getSummonerMatch(APIParameters params, URLBuilderWrapper * urlBuilder){
	URLBuilderWrapper* url;
	if (urlBuilder == nullptr)
		url = new MatchURLBuilder(params);
	else
		url = urlBuilder;

	if (apiReader == nullptr || url == nullptr)
		return std::map<std::string, MatchData>();
	auto apiResponse = apiReader->callAPI(url->getURL());
	return apiReader->parseData<MatchAPI, MatchData>(apiResponse, this, &MatchAPI::parseMatchData);
}

APIParameters MatchAPI::setupMatchParams(){
	APIParameters params;

	params.api = APIType::Match;

	return params;
}

MatchData MatchAPI::parseMatchData(JsonWrapper * json){
	MatchData matchData;
	matchData.queueType = json->read("queueType");
	matchData.matchVersion = json->read("matchVersion");
	matchData.platformId = json->read("platformId");
	matchData.season = json->read("season");
	matchData.region =json->read("region");
	matchData.matchId = json->read("matchId");
	matchData.mapId = stoi(json->read("mapId"));
	matchData.matchCreation = json->read("matchCreation");
	matchData.teams = json->read("teams");

	return matchData;
}
