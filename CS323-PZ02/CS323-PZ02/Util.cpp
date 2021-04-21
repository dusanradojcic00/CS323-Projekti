#include "Util.h"

const string Util::API_KEY = "X-CMC_PRO_API_KEY: d1b79ee0-bf9a-405e-8aa1-9384c7afb14d";
const string Util::DEFAULT_URL = "https://pro-api.coinmarketcap.com/v1/cryptocurrency/";
namespace util
{
	size_t callback(
		const char* in,
		size_t size,
		size_t num,
		string* out)
	{
		const size_t totalBytes(size * num);
		out->append(in, totalBytes);
		return totalBytes;
	}
}


double Util::cryptoToFiat(string crypto, string fiat) 
{
	//Inicijalizacija curl objekta
	CURL* curl = curl_easy_init();

	//Kreiranje header liste
	struct curl_slist* list = NULL;
	list = curl_slist_append(list, Util::API_KEY.c_str());
	list = curl_slist_append(list, "Accept: application / json");

	//Podesavanje curl zahteva
	//"https://pro-api.coinmarketcap.com/v1/cryptocurrency/quotes/latest?symbol=" + crypto + "&convert=" + fiat;
	string url = Util::DEFAULT_URL + "quotes/latest?symbol=" + crypto + "&convert=" + fiat;
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

	//Promenjive za cuvanje statusa zahteva i podataka dobijenih iz zahteva (JSON)
	int httpCode(0);
	unique_ptr<string> httpData(new string());

	//Kreiranje callback funkcije i dodeljivanje dodataka promenjivoj httpData
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, util::callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());


	CURLcode result = curl_easy_perform(curl);

	//Dobijanje podataka o http statusnom kodu
	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

	//Ciscenje liste i zahteva
	curl_slist_free_all(list);
	curl_easy_cleanup(curl);

	if (httpCode == 200)
	{
		// Response looks good - done using Curl now.  Try to parse the results
		// and print them out.
		Json::Value jsonData;
		Json::CharReaderBuilder builder;
		const std::unique_ptr<Json::CharReader> jsonReader(builder.newCharReader());

		JSONCPP_STRING err;


		if (jsonReader->parse(httpData.get()->c_str(), httpData.get()->c_str() + httpData.get()->length(), &jsonData, &err))
		{
			double result2 = jsonData["data"][crypto]["quote"][fiat]["price"].asDouble();
			return result2;
		}
		else
		{
			cout << "Could not parse HTTP data as JSON" << std::endl;
			cout << "HTTP data was:\n" << *httpData.get() << std::endl;
		}
	}
	
}

double Util::cryptoToCrypto(string crypto1, string crypto2) {
	//Inicijalizacija curl objekta
	CURL* curl = curl_easy_init();

	//Kreiranje header liste
	struct curl_slist* list = NULL;
	list = curl_slist_append(list, Util::API_KEY.c_str());
	list = curl_slist_append(list, "Accept: application / json");

	//Podesavanje curl zahteva
	//"https://pro-api.coinmarketcap.com/v1/cryptocurrency/quotes/latest?symbol=" + crypto1 + "&convert=" + crypto2;
	string url = Util::DEFAULT_URL + "quotes/latest?symbol=" + crypto1 + "&convert=" + crypto2;
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

	//Promenjive za cuvanje statusa zahteva i podataka dobijenih iz zahteva (JSON)
	int httpCode(0);
	unique_ptr<string> httpData(new string());

	//Kreiranje callback funkcije i dodeljivanje dodataka promenjivoj httpData
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, util::callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());


	CURLcode result = curl_easy_perform(curl);

	//Dobijanje podataka o http statusnom kodu
	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

	//Ciscenje liste i zahteva
	curl_slist_free_all(list);
	curl_easy_cleanup(curl);

	if (httpCode == 200)
	{

		// Response looks good - done using Curl now.  Try to parse the results
		// and print them out.
		Json::Value jsonData;
		Json::CharReaderBuilder builder;
		const std::unique_ptr<Json::CharReader> jsonReader(builder.newCharReader());

		JSONCPP_STRING err;


		if (jsonReader->parse(httpData.get()->c_str(), httpData.get()->c_str() + httpData.get()->length(), &jsonData, &err))
		{
			double result2 = jsonData["data"][crypto1]["quote"][crypto2]["price"].asDouble();
			return result2;
		}
		else
		{
			cout << "Could not parse HTTP data as JSON" << std::endl;
			cout << "HTTP data was:\n" << *httpData.get() << std::endl;
		}
	}
}