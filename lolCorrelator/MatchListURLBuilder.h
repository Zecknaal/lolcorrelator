#pragma once

#include "URLBuilderBase.h"

class MatchListURLBuilder : public URLBuilderBase {
public:
	MatchListURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
	}
	virtual std::string getURL() override {
		std::string url;
		url = constantBuilder->getPrefix() +
			constantBuilder->mapRegionToPrefix(apiParameters.region) +
			"/api/lol/" +
			constantBuilder->mapRegionToPrefixShort(apiParameters.region) +
			"/v2.2/matchlist/by-summoner/" +
			constantBuilder->convertParamsToCommaSeparatedString(apiParameters.parameters["summonerIDs"]) +
			"?" +
			constantBuilder->getKeyPrefix() +
			apiParameters.key;
		return url;
	}
};