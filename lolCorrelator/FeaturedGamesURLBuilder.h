#pragma once

#include "URLBuilderBase.h"

class FeaturedGamesURLBuilder : public URLBuilderBase {
public:
	FeaturedGamesURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
	}
	virtual std::string getURL() override {
		return std::string();
	};
};