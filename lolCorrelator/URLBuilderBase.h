#pragma once

#include "URLBuilderWrapper.h"
#include "URLConstantBuilder.h"

class URLBuilderBase : public URLBuilderWrapper {
	public:
		URLBuilderBase(APIParameters params, URLConstantBuilderWrapper* builder = nullptr) {
			apiParameters = params;

			if (builder == nullptr)
				constantBuilder = new URLConstantBuilder();
			else
				constantBuilder = builder;
		}
	protected:
		APIParameters apiParameters;
		URLConstantBuilderWrapper* constantBuilder;
};