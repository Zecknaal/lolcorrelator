#pragma once

#include "URLBuilderBase.h"

class ChampionURLBuilder : public URLBuilderBase {
public:
	ChampionURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
	}
	virtual std::string getURL() override {
		return std::string();
	};
};
