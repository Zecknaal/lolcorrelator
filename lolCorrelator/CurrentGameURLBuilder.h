#pragma once

#include "URLBuilderBase.h"

class CurrentGameURLBuilder : public URLBuilderBase {
public:
	CurrentGameURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
	}
	virtual std::string getURL() override {
		return std::string();
	};
};
