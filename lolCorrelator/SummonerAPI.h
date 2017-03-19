#pragma once
#pragma once

#include "RiotAPIReaderWrapper.h"
#include "SummonerURLBuilder.h"
#include "JsonFactory.h"
#include "SummonerAPITypes.h"
#include <map>
#include <vector>

class SummonerAPI{

	public:
		SummonerAPI(RiotAPIReaderWrapper* reader = nullptr);
		std::map<std::string, SummonerData> getSummonerName(APIParameters params, URLBuilderWrapper* urlBuilder = nullptr);
		APIParameters setupByNameParams();
	protected:
		SummonerData parseJsonIntoSummonerData(JsonWrapper* json = nullptr);

		RiotAPIReaderWrapper* apiReader;
};

