#pragma once

#include "RiotAPIReaderTypes.h"
class URLConstantBuilderWrapper {
	public:
		virtual std::string mapRegionToPrefix(SERVER_REGION region) = 0;
		virtual std::string getPrefix() = 0;
};