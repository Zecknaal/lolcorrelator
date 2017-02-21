#pragma once

#include "JsonWrapper.h"
#include "JsonParser.h"

enum class JsonParserType{ Lohmann };

class JsonFactory {
	public:
		JsonFactory();
		//JsonWrapper<JsonParser>* createJson();
		JsonWrapper* createJson(JsonParserType parserType);
};