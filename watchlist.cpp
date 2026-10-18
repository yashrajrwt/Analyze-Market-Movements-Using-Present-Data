#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "ui.h" 
#include "watchlist.h"

using namespace std;

void Watchlist::addStock()
{
    string symbol;

    cout << "\nEnter Stock Symbol : ";
    cin >> symbol;

    ofstream file("watchlist.txt", ios::app);

    if(file.is_open())
    {
        file << symbol << endl;

        UI ui;

        ui.green();

        cout << "\nStock Added Successfully.\n";

        ui.reset();

        file.close();
    }
    else
    {
        UI ui;

        ui.red();

        cout << "\nUnable to open file!!!\n";

        ui.reset();
    }
}

void Watchlist::viewWatchlist()
{
    ifstream file("watchlist.txt");

    if(!file)
    {
        cout << "\nNo Watchlist Found.\n";
        return;
    }

    string symbol;

    int count = 1;

    cout << "\n=====================================\n";
    cout << "          MY WATCHLIST\n";
    cout << "=====================================\n";

    while(getline(file,symbol))
    {
        cout << count << ". " << symbol << endl;
        count++;
    }

    file.close();
}

void Watchlist::removeStock()
{
    string removeSymbol;

    cout << "\nEnter Stock Symbol to Remove : ";
    cin >> removeSymbol;

    ifstream file("watchlist.txt");

    vector<string> stocks;

    string symbol;

    while(getline(file,symbol))
    {
        if(symbol != removeSymbol)
        {
            stocks.push_back(symbol);
        }
    }

    file.close();

    ofstream outFile("watchlist.txt");

    for(string s : stocks)
    {
        outFile << s << endl;
    }

    outFile.close();

    cout << "\nStock Removed Successfully.\n";
}