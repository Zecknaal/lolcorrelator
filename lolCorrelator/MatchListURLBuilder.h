#pragma once

#include "URLBuilderBase.h"

class MatchListURLBuilder : public URLBuilderBase {
public:
	MatchListURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
	}
	virtual std::string getURL() override {
		return std::string();
	};
};