#pragma once

#include "URLBuilderBase.h"

class LeagueURLBuilder : public URLBuilderBase {
public:
	LeagueURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
	}
	virtual std::string getURL() override {
		return std::string();
	};
};