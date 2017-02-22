#pragma once

#include "URLBuilderBase.h"

class SummonerURLBuilder : public URLBuilderBase {
	public:
		SummonerURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
		}
		virtual std::string getURL() override {
			std::string url, region, type;
			url = constantBuilder->getPrefix() + constantBuilder->mapRegionToPrefix(apiParameters.region) + "/api/lol/na/v1.4/summoner/by-name/zecknaal?api_key=cf493893-d798-47e2-997f-adced88d62b9";
			return url;
			//return std::string("https://na.api.pvp.net/api/lol/na/v1.4/summoner/by-name/zecknaal?api_key=cf493893-d798-47e2-997f-adced88d62b9");
		}
};