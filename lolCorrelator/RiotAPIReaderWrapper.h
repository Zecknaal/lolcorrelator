#pragma once

#include <string>
#include <map>
#include "RiotAPIReaderTypes.h"
#include "CurlWrapper.h"
#include "CurlFactory.h"
#include "JsonFactory.h"

class RiotAPIReaderWrapper {
	public:
		virtual std::string callAPI(std::string url) = 0;
		template<class objectType, typename dataType> std::map<std::string, dataType> parseData(std::string rawData, apiParam keys, objectType* object, dataType(objectType::*parser)(JsonWrapper*), JsonWrapper* json = nullptr) {
			JsonWrapper* elementJson;
			std::map<std::string, dataType> results;
			if (json == nullptr) {
				json = JsonFactory().createJson(JsonParserType::Lohmann);
			}

			elementJson = JsonFactory().createJson(JsonParserType::Lohmann);
			json->parseJson(rawData.c_str());

			for (auto& key : keys) {
				elementJson->parseJson(json->read(key).c_str());
				results[key] = (*object.*parser)(elementJson);
			}

			return results;
		};
		template<class objectType, typename dataType> std::map<std::string, dataType> parseData(std::string rawData, objectType* object, dataType(objectType::*parser)(JsonWrapper*), JsonWrapper* json = nullptr) {
			JsonWrapper* elementJson;
			std::map<std::string, dataType> results;
			if (json == nullptr) {
				json = JsonFactory().createJson(JsonParserType::Lohmann);
			}

			elementJson = JsonFactory().createJson(JsonParserType::Lohmann);
			json->parseJson(rawData.c_str());

			results["result"] = (*object.*parser)(json);
			return results;
		};//test
};