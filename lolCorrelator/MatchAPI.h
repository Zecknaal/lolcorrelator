#pragma once

#include "RiotAPIReaderWrapper.h"
#include "RiotAPIReader.h"
#include "URLBuilderFactory.h"
#include "MatchAPITypes.h"

#include <map>

class MatchAPI {
public:
	MatchAPI(RiotAPIReaderWrapper* reader = nullptr);
	std::map<std::string, MatchData> getSummonerMatch(APIParameters params, URLBuilderWrapper* urlBuilder = nullptr);
	APIParameters setupMatchParams();
protected:
	RiotAPIReaderWrapper* apiReader;

	MatchData parseMatchData(JsonWrapper* json = nullptr);
};