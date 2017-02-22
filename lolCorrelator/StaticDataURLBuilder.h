#pragma once

#include "URLBuilderBase.h"

class StaticDataURLBuilder : public URLBuilderBase {
public:
	StaticDataURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
	}
	virtual std::string getURL() override {
		return std::string();
	};
};