#include <iostream>
#include "stock.h"
#include "api.h"
#include "history.h"

using namespace std;

void Stock::searchStock()
{
    string symbol;

    cout << "Enter Stock Symbol: ";
    cin >> symbol;

    History history;
    history.saveHistory(symbol);

    API api;
    api.getNews(symbol);
}
void Stock::getStockPrice()
{
    string symbol;

    cout << "\nEnter Stock Symbol: ";
    cin >> symbol;

    History history;
    history.saveHistory(symbol);

    API api;
    api.getPrice(symbol);
}
void Stock::companyProfile()
{
    string symbol;

    cout << "\nEnter Stock Symbol: ";
    cin >> symbol;

    History history;
    history.saveHistory(symbol);

    API api;
    api.getCompanyProfile(symbol);
}