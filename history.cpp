#include <iostream>
#include <fstream>
#include "history.h"

using namespace std;

void History::saveHistory(string symbol)
{
    ofstream file("history.txt", ios::app);

    if(file.is_open())
    {
        file << symbol << endl;
        file.close();
    }
}

void History::showHistory()
{
    ifstream file("history.txt");

    string symbol;

    cout << "\n=====================================\n";
    cout << "        SEARCH HISTORY\n";
    cout << "=====================================\n";

    if(!file)
    {
        cout << "No history found.\n";
        return;
    }

    int count = 1;

    while(getline(file, symbol))
    {
        cout << count << ". " << symbol << endl;
        count++;
    }

    file.close();
}