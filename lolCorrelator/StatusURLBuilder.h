#pragma once

#include "URLBuilderBase.h"

class StatusURLBuilder : public URLBuilderBase {
public:
	StatusURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
	}
	virtual std::string getURL() override {
		return std::string();
	};
};