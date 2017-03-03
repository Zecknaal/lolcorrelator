#pragma once
#include <map>
#include <vector>

//template<typename derived>
class JsonWrapper{
	public:
		virtual std::string parseJson(const char* json) = 0;
		//virtual derived operator=(const char* json) = 0;
		virtual std::string operator[](const std::string &element) = 0;
		virtual std::string read(std::string element) = 0;
		virtual std::string dump() = 0;
		virtual std::map<std::string, std::string>extractValuesByElement(std::string element, std::vector<std::string> key) = 0;
	protected:
		std::string jsonRaw;
};