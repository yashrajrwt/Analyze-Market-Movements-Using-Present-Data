#include <iostream>
#include "stock.h"
#include "history.h"
#include "watchlist.h"
#include "ui.h"

using namespace std;

int main()
{
    UI ui;
    Stock stock;
    History history;
    Watchlist watch;

    int choice;

    while(true)
    {
        ui.menu();

        cin >> choice;

        switch(choice)
        {
            case 1:
                stock.searchStock();
                break;

            case 2:
                stock.getStockPrice();
                break;

            case 3:
                stock.companyProfile();
                break;

            case 4:
                history.showHistory();
                break;

            case 5:
            {
                int ch;

                do
                {
                    ui.cyan();
                    cout << "\n=========================================================\n";
                    cout << "                  WATCHLIST MENU\n";
                    cout << "=========================================================\n";
                    ui.reset();

                    ui.green();
                    cout << " 1. Add Stock\n";
                    cout << " 2. View Watchlist\n";
                    cout << " 3. Remove Stock\n";

                    ui.red();
                    cout << " 4. Back to Main Menu\n";
                    ui.reset();

                    ui.cyan();
                    cout << "=========================================================\n";
                    ui.reset();

                    cout << "Enter Choice : ";
                    cin >> ch;

                    switch(ch)
                    {
                        case 1:
                            watch.addStock();
                            break;

                        case 2:
                            watch.viewWatchlist();
                            break;

                        case 3:
                            watch.removeStock();
                            break;

                        case 4:
                            cout << "\nReturning to Main Menu...\n";
                            break;

                        default:
                            ui.red();
                            cout << "\nInvalid Choice!\n";
                            ui.reset();
                    }

                } while(ch != 4);

                break;
            }

            case 6:
                cout << "\nThank You!\n";
                return 0;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }
}