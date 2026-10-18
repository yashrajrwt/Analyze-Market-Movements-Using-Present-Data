#ifndef HISTORY_H
#define HISTORY_H

#include <string>

using namespace std;

class History
{
public:
    void saveHistory(string symbol);
    void showHistory();
};

#endif