/*
 * CheckConfig.cpp
 *
 *  Created on: 21 Aug 2018
 *      Author: roberty
 */
#include "CheckConnection.h"

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
	std::ofstream ofs("/dev/null");

	ofs << buffer;
   return size * nmemb;
}
bool CheckConnection::CheckNetwork()
{

	CURL *curl;
	  CURLcode res;

	  curl = curl_easy_init();
	  if(curl) {
		   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

	    curl_easy_setopt(curl, CURLOPT_URL, "www.google.com");
	  while ((res = curl_easy_perform(curl)) != CURLE_OK)
	  {
	    switch (res)
	    {
	        case CURLE_COULDNT_CONNECT:
	        case CURLE_COULDNT_RESOLVE_HOST:
	        case CURLE_COULDNT_RESOLVE_PROXY:
	             return false;
	            break;
	        default:
	            return false;
	    }
	    }

	    /* always cleanup */
	    curl_easy_cleanup(curl);
  }
      return true;

}



