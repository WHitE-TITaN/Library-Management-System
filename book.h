#pragma once

#include <iostream>
#include <unordered_map>
#include <ctime>
#include <sstream>
#include "members.h"
#include <string>
#include <bitset>

using namespace std;


class book
{
private:
    string bookName;
    int total_count, current_count;
    unordered_map<int, pair<tm, tm>> issures;

    int dateCalculator(tm date);
public:
    book();
    ~book();

    bool issuedTo(int id);
    bool addNewBook(string name, int total_count);
    string allIssuers();
};
