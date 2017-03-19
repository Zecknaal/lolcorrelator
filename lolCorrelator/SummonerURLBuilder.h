#pragma once

#include "URLBuilderBase.h"

class SummonerURLBuilder : public URLBuilderBase {
	public:
		SummonerURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {}

		virtual std::string getURL() override {
			std::string url;
			url = constantBuilder->getPrefix() +
				constantBuilder->mapRegionToPrefix(apiParameters.region) +
				"/api/lol/" +
				constantBuilder->mapRegionToPrefixShort(apiParameters.region) +
				"/v1.4/summoner" +
				getCoreURLByType(apiParameters.parameters["Type"][0]) +
				constantBuilder->convertParamsToCommaSeparatedString(apiParameters.parameters["summonerNames"]) +
				"?" +
				constantBuilder->getKeyPrefix() +
				apiParameters.key;
			return url;
		}

		std::string getCoreURLByType(std::string typeParam) {
			if (typeParam == "ByName")
				return "/by-name/";
			else if (typeParam == "ByID")
				return "";
			else if (typeParam == "GetName")
				return "";
			else
				return "";
		}
};