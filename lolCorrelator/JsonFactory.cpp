#include "JsonFactory.h"

JsonFactory::JsonFactory(){
}

JsonWrapper* JsonFactory::createJson(JsonParserType parserType){
	JsonWrapper* createdObject = nullptr;
	if (parserType == JsonParserType::Lohmann)
		createdObject = new JsonParser();
	else
		createdObject = nullptr;
	return createdObject;
}
