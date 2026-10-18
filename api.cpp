#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "api.h"
#include "ui.h"

using namespace std;
using json = nlohmann::json;

// Callback function
size_t WriteCallback(void *contents, size_t size, size_t nmemb, string *output)
{
    output->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void API::getNews(string symbol)
{
    // Replace with your own API key
    string apiKey = "YOUR_API_KEY_HERE";

    string url =
        "https://finnhub.io/api/v1/company-news?symbol=" +
        symbol +
        "&from=2025-07-01&to=2025-07-31&token=" +
        apiKey;

    CURL *curl = curl_easy_init();
    string response;

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode result = curl_easy_perform(curl);

        if (result == CURLE_OK)
        {
            json data = json::parse(response);

            if (data.empty())
            {
                cout << "\nNo news found.\n";
            }
            else
            {
                cout << "\n=====================================\n";
                UI ui;

                ui.blue();

                ui.line();

                cout << " Latest News for " << symbol << endl;

                ui.line();

                ui.reset();
                
                cout << "=====================================\n";

                for (int i = 0; i < 5 && i < data.size(); i++)
                {
                    cout << "\nNews " << i + 1 << endl;

                    cout << "Headline : "
                         << data[i]["headline"] << endl;

                    cout << "Source   : "
                         << data[i]["source"] << endl;

                    cout << "-------------------------------------\n";
                }
            }
        }
        else
        {
            cout << "\nCURL Error : "
                 << curl_easy_strerror(result) << endl;
        }

        curl_easy_cleanup(curl);
    }
    else
    {
        cout << "Unable to initialize CURL." << endl;
    }
}
void API::getPrice(string symbol)
{
    string apiKey = "YOUR_API_KEY_HERE";

    string url =
        "https://finnhub.io/api/v1/quote?symbol=" +
        symbol +
        "&token=" +
        apiKey;

    CURL *curl = curl_easy_init();
    string response;

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode result = curl_easy_perform(curl);

        if (result == CURLE_OK)
        {
            json data = json::parse(response);

            cout << "\n=====================================\n";
            UI ui;

            ui.blue();

            ui.line();

            cout << " Live Stock Price\n";

            ui.line();

            ui.reset();
            
            cout << "=====================================\n";

            cout << "Symbol         : " << symbol << endl;
            cout << "Current Price  : " << data["c"] << endl;
            cout << "Open Price     : " << data["o"] << endl;
            cout << "High Price     : " << data["h"] << endl;
            cout << "Low Price      : " << data["l"] << endl;
            cout << "Previous Close : " << data["pc"] << endl;
        }
        else
        {
            cout << "\nCURL Error: "
                 << curl_easy_strerror(result) << endl;
        }

        curl_easy_cleanup(curl);
    }
}
void API::getCompanyProfile(string symbol)
{
    string apiKey = "YOUR_API_KEY_HERE";

    string url =
        "https://finnhub.io/api/v1/stock/profile2?symbol=" +
        symbol +
        "&token=" +
        apiKey;

    CURL *curl = curl_easy_init();
    string response;

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode result = curl_easy_perform(curl);

        if(result == CURLE_OK)
        {
            json data = json::parse(response);

            if(data.empty())
            {
                cout << "\nCompany not found.\n";
            }
            else
            {
                cout << "\n=========================================\n";
                UI ui;

                ui.blue();

                ui.line();

                cout << "        COMPANY PROFILE\n";

                ui.line();

                ui.reset();
                
                cout << "=========================================\n";

                cout << "Company Name        : " << data["name"] << endl;
                cout << "Ticker              : " << data["ticker"] << endl;
                cout << "Country             : " << data["country"] << endl;
                cout << "Exchange            : " << data["exchange"] << endl;
                cout << "Currency            : " << data["currency"] << endl;
                cout << "Industry            : " << data["finnhubIndustry"] << endl;
                cout << "IPO Date            : " << data["ipo"] << endl;
                cout << "Website             : " << data["weburl"] << endl;
                cout << "Market Cap (Billion): " << data["marketCapitalization"] << endl;
            }
        }
        else
        {
            cout << "\nCURL Error : "
                 << curl_easy_strerror(result) << endl;
        }

        curl_easy_cleanup(curl);
    }
}