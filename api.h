#ifndef API_H
#define API_H

#include <string>

using namespace std;

class API
{
public:
    void getNews(string symbol);
    void getPrice(string symbol);
    void getCompanyProfile(string symbol);   
};

#endif
