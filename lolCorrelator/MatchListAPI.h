#pragma once

#include "MatchListTypes.h"
#include "RiotAPIReaderWrapper.h"
#include "RiotAPIReader.h"
#include "URLBuilderWrapper.h"
#include "URLBuilderFactory.h"
#include <string>

class MatchListAPI {
	public:
		MatchListAPI(RiotAPIReaderWrapper* reader = nullptr);
		std::map<std::string, MatchListData> getSummonerMatchList(APIParameters params, URLBuilderWrapper* urlBuilder = nullptr);
		APIParameters setupMatchListParams();
	protected:
		RiotAPIReaderWrapper* apiReader;

		MatchListData parseJsonIntoMatchListData(JsonWrapper* json = nullptr);
		std::vector<MatchListSingleData> parseMatchData(std::vector<std::string> data, JsonWrapper* json = nullptr);
};