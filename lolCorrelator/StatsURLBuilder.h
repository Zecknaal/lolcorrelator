#pragma once

#include "URLBuilderBase.h"

class StatsURLBuilder : public URLBuilderBase {
public:
	StatsURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
	}
	virtual std::string getURL() override {
		return std::string();
	};
};