#pragma once

#include "JsonWrapper.h"
#include "jsonlohmann/json.hpp"

using json = nlohmann::json;

class JsonParser : public JsonWrapper{
	public:
		virtual void parseJson(const char* json) override;
		virtual std::string operator[](const std::string &element) override;
		virtual std::string read(std::string element) override;
		virtual std::string dump() override;
		virtual std::vector<std::string> dumpByElement(std::string element) override;
		virtual std::map<std::string, std::string>extractValuesByElement(std::string element, std::vector<std::string> key) override;
		//virtual JsonParser operator=(const char* json) override;
	protected:
		json jsonData;
};