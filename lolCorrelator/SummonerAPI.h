#pragma once
#pragma once

#include "RiotAPIReaderWrapper.h"
#include "SummonerURLBuilder.h"
#include <string>

class SummonerAPI{

	public:
		SummonerAPI(URLBuilderWrapper* builder = nullptr);
		std::string getSummonerName(APIParameters params);
};