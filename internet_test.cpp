#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

// This function stores the downloaded data
size_t WriteCallback(void *contents, size_t size, size_t nmemb, string *output)
{
    output->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode result;

    string response;

    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/todos/1");

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        result = curl_easy_perform(curl);

        cout << "CURL Result Code = " << result << endl;
        cout << "Message = " << curl_easy_strerror(result) << endl;

        cout << "\nResponse received:\n";
        cout << response << endl;

        curl_easy_cleanup(curl);
    }

    return 0;
}