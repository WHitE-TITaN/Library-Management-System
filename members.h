#pragma once

#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <limits>
#include <string>
#include <iostream>
#include <vector>
#include <functional>

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

    void haveIssued(int id, string bookName);
    void issuedBookOnUser(int id);
    bool registerUser(string userName, string userAddress, long long userMobileNo);
    bool isValidMember(int id);
    bool canIssueBook(int id, string bookName);
};

//defining the static variable
unordered_map<int, members::Member*> members::allMembers;

//constructor ->>
members::members()
{
}



//🆕 add new user function ->>
bool members::registerUser(string userName, string userAddress, long long userMobileNo){
    string rawInput;
    
    //cleaning input buffer.
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
  
    // get todays date;
    time_t systemDay = time(0);
    tm validTill = *localtime(&systemDay);
    string date = ctime(&systemDay);

    rawInput = userName + date;
    
    int hashValue = hash<string>{}(rawInput) % 1000000;
    cout<<"\nlibrary System $\n     - Id - "<<hashValue<<" \n";

    Member *newMember = new Member();
    newMember->name = userName;
    newMember->address = userAddress;
    newMember->mobileNo = userMobileNo;
    newMember->subscription.first = validTill;

    validTill.tm_mon += 1;
    mktime(&validTill);

    //✨ mktime adjusts the tm struct so that if days/months go over their 
    //limit, it carries over to the next month/year automatically.

    newMember->subscription.second = validTill;

    allMembers[hashValue] = newMember;

    return isValidMember(hashValue); 
}




//✅ check validity for user !
bool members::isValidMember(int id){
    auto locator = allMembers.find(id);

    //✅ check if user exist in the list or not.
    if(locator == allMembers.end()){
        cout<<"user Not Fount !\n";
        return false;
    }

    // get todays date;
    time_t systemDay = time(0);
    tm *current = localtime(&systemDay);
    bool expire = false;

    pair<tm, tm> validity = locator->second->subscription;
    
    if(validity.second.tm_year < current->tm_year){
        expire = true;
    }  
    if(validity.second.tm_mon < current->tm_mon){
        expire = true;
    }
    if(validity.second.tm_mday < current->tm_mday && 
        validity.second.tm_mon <= current->tm_mon){
        expire = true;
    }

    if(expire == true){
        cout<<"validity has be expire - ";
        if(locator->second->booksIssued.size() != 0){
            cout<<"\nplease return the under written book - \n";
            
            for(auto name : locator->second->booksIssued){
                cout<<"\n"<<name;
            }
        }
        return false;
    }

    cout<<"\n name -"<<locator->second->name;
    cout<<"\n valid till -"<<validity.second.tm_mday<<" / "
        <<validity.second.tm_mon<<" / "<<
        validity.second.tm_year;

    return true;
}

members::~members()
{
}

bool members::canIssueBook(int id, string bookName){
    auto locator = allMembers.find(id);

    if(locator == allMembers.end()){
        cout<<"User Not found";
        return false;
    }

    if(locator->second->booksIssued.find(bookName) != locator->second->booksIssued.end()){
        cout<<locator->second->name<<"\nalready have the same book -";
        return false;
    }

    time_t currentdate = time(0);
    tm *today = localtime(&currentdate);
    today->tm_mday += 15;
    mktime(today);

    if(locator->second->subscription.second.tm_year < today->tm_year){
        cout<<"Expiring Subscription Cant Issue Book -";
        return false;
    }
    if(locator->second->subscription.second.tm_mon < 
    today->tm_mon){
        cout<<"Expiring Subscription Cant Issue Book -";
        return false;
    }
    if(locator->second->subscription.second.tm_mon < 
        today->tm_mon && locator->second->subscription.second.tm_mday < 
        today->tm_mday){
            cout<<"Expiring Subscription Cant Issue Book -";
            return false;
    }

    return true;
}


void members::issuedBookOnUser(int id){
    auto locator = allMembers.find(id);
    if(!isValidMember(id)){
        return;
    }

    Member *person = locator->second;

    if(person->booksIssued.size() == 0){
        cout<<"person have not issued any books -";
        return;
    }

    cout<<"\n\tall the issued books by - "<<person->name<<"\n\tare under - ";
    for(auto books : person->booksIssued){
        cout<<books<<"\n";
    }
    return;
}


void members::haveIssued(int id, string bookName){
    auto locator = allMembers.find(id);
    locator->second->booksIssued.insert(bookName);
}
