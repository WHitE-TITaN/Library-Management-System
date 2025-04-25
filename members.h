#pragma once

#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <sstream>

#include <string>

using namespace std;

class members{
private:
    class Member{
        public:
        string name, address;
        pair<tm, tm> subscription;
        unordered_set<string> booksIssued;
        int mobileNo;
    };

    static unordered_map<int, Member *> allMembers;            //id - > {name , valid memebrship date ->>};

public:
    members();
    ~members();

    string getUserSummary(int id);
    void haveIssued(int id, string bookName);
    void issuedBookOnUser(int id);
    int registerUser(string userName, string userAddress, long long userMobileNo);
    bool isValidMember(int id);
    bool canIssueBook(int id, string bookName);
};
