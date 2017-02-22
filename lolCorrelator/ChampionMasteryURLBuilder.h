#pragma once

#include "URLBuilderBase.h"

class ChampionMasteryURLBuilder : public URLBuilderBase {
public:
	ChampionMasteryURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
	}
	virtual std::string getURL() override {
		return std::string();
	};
};
