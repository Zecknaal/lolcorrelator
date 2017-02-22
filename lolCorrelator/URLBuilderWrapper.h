#pragma once

#include "RiotAPIReaderTypes.h"

class URLBuilderWrapper {
	public:
		virtual std::string getURL() = 0;
};