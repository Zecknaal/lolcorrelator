#pragma once

#include "URLBuilderBase.h"

class GameURLBuilder : public URLBuilderBase {
public:
	GameURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
	}
	virtual std::string getURL() override {
		return std::string();
	};
};