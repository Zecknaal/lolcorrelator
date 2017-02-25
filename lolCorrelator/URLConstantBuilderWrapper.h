#pragma once

#include "RiotAPIReaderTypes.h"
class URLConstantBuilderWrapper {
	public:
		virtual std::string mapRegionToPrefix(SERVER_REGION region) = 0;
		virtual std::string getPrefix() = 0;
		virtual std::string convertParamsToCommaSeparatedString(apiParam params) = 0;
		virtual std::string getKeyPrefix() = 0;
		virtual std::string mapRegionToPrefixShort(SERVER_REGION region) = 0;
};