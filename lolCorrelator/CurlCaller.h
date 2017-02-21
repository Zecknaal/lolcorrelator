#pragma once

#include "CurlWrapper.h"
#include <iostream>
#include "curl/include/curl/curl.h"

class CurlCaller : public CurlWrapper{
	public:
		CurlCaller();
		virtual const char* sendCurl(const char* url) override;
		virtual void setupCurl(const char* proxy = nullptr) override;
	protected:
		std::string readBuffer;
		CURL* curl;
		//Must be static - the callback will fail otherwise
		static size_t writeCallback(void * contents, size_t size, size_t nmemb, void * userp);
};