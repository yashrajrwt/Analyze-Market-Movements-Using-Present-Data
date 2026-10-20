#include<iostream>
#include<iomanip>
#include<thread>
#include<chrono>

#include "ui.h"

using namespace std;

void UI::line()
{
    cout<<"==============================================================\n";
}
void UI::title()
{
    cyan();

    line();

    cout << "\tAnalyze Market Movements Using Present Data\n";


    cyan();

    line();

    reset();
}
void UI::menu()
{
    title();

    green();

    cout << " 1. Latest Stock News\n";
    cout << " 2. Live Stock Price\n";
    cout << " 3. Company Profile\n";
    cout << " 4. Search History\n";
    cout << " 5. Watchlist\n";

    red();

    cout << " 6. Exit\n";

    reset();

    line();

    cout << "Enter Choice : ";
}
void UI::loading()
{
    yellow();

    cout << "\nConnecting to Finnhub API";

    for(int i = 0; i < 5; i++)
    {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    cout << "\n";

    reset();
}
void UI::green()
{
    cout << "\033[32m";
}

void UI::red()
{
    cout << "\033[31m";
}

void UI::blue()
{
    cout << "\033[34m";
}

void UI::yellow()
{
    cout << "\033[33m";
}

void UI::cyan()
{
    cout << "\033[36m";
}

void UI::white()
{
    cout << "\033[37m";
}

void UI::reset()
{
    cout << "\033[0m";
}
