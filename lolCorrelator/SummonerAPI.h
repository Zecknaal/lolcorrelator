#pragma once
#pragma once

#include "RiotAPIReaderWrapper.h"
#include "SummonerURLBuilder.h"
#include "JsonFactory.h"
#include <map>

class SummonerAPI{

	public:
		SummonerAPI(URLBuilderWrapper* builder = nullptr);
		std::map<std::string, std::string> getSummonerName(APIParameters params);
};