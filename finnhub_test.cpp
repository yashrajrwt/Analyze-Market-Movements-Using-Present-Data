#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

// Callback function to store downloaded data
size_t WriteCallback(void *contents, size_t size, size_t nmemb, string *output)
{
    output->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
    string symbol;
    cout << "Enter Stock Symbol: ";
    cin >> symbol;

    // Replace with your own API key
    string apiKey = "YOUR_API_KEY_HERE";

    string url =
        "https://finnhub.io/api/v1/company-news?symbol=" +
        symbol +
        "&from=2025-07-01&to=2025-07-31&token=" +
        apiKey;

    cout << "\nURL:\n" << url << endl;

    CURL *curl = curl_easy_init();
    CURLcode result;
    string response;

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        result = curl_easy_perform(curl);

        if (result == CURLE_OK)
        {
            cout << "\nDownloaded JSON:\n\n";
            cout << response << endl;
        }
        else
        {
            cout << "\nError: " << curl_easy_strerror(result) << endl;
        }

        curl_easy_cleanup(curl);
    }
    else
    {
        cout << "Failed to initialize CURL." << endl;
    }

    return 0;
}