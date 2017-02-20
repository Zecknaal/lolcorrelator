#pragma once

class CurlWrapper {
	public:
		virtual const char* sendCurl(const char* url) = 0;
		virtual void setupCurl(const char* proxy = nullptr) = 0;
};