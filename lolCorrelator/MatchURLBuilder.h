#pragma once

#include "URLBuilderBase.h"

class MatchURLBuilder : public URLBuilderBase {
	public:
		MatchURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
		}
		virtual std::string getURL() override {
			std::string url;
			url = constantBuilder->getPrefix() +
				constantBuilder->mapRegionToPrefix(apiParameters.region) +
				"/api/lol/" +
				constantBuilder->mapRegionToPrefixShort(apiParameters.region) +
				"/v2.2/match/" +
				constantBuilder->convertParamsToCommaSeparatedString(apiParameters.parameters["matchIDs"]) +
				"?" +
				getTimeline(false) + 
				"&" +
				constantBuilder->getKeyPrefix() +
				apiParameters.key;
			return url;
		}

		std::string getTimeline(bool timeline) {
			return std::string("includeTimeline=") + (timeline ? std::string("true") : std::string("false"));
		}
};