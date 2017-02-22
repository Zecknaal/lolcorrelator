#pragma once

#include "URLBuilderBase.h"

class MatchURLBuilder : public URLBuilderBase {
	public:
		MatchURLBuilder(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) : URLBuilderBase(params, builder) {
		}
		virtual std::string getURL() override {
			return std::string();
		};
};