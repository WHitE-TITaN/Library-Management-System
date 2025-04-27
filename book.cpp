#include "book.h"


book::book(){
}





//add new book
bool book::addNewBook(string name, int count){
    bookName = name;
    total_count = count;
    current_count = count;
    return true;
}



//📚🧑 issue book...
bool book::issuedTo(int id){
    if(current_count <= 1){
        cout<<"Book not avilable for issue !";
        return false;
    }

    time_t systemDate = time(0);;
    tm date = *localtime(&systemDate);

    auto locator = issures.find(id);

    if(locator == issures.end()){
        tm issueExpireDate = date;
        issueExpireDate.tm_mday += 15;

        mktime(&issueExpireDate);
        //✨ mktime adjusts the tm struct so that if days/months go over their limit,
        // it carries over to the next month/year automatically.


        issures[id] = {date, issueExpireDate};
        current_count--;

        cout<<"\n Issued till - "<<
            issueExpireDate.tm_mday<<" / "<<
            issueExpireDate.tm_mon<<" / "<<
            issueExpireDate.tm_year;

        return true;
    }
    cout<<"\n* User already have this book *\n";
    cout<<"* Till - "<<locator->second.second.tm_mday<<" / "
         <<locator->second.second.tm_mon<<" / "
         <<locator->second.second.tm_year;

    return false;
}

book::~book()
{
}

#include <sstream> // 💬 for stringstream!

string book::allIssuers(){
    members personalDetail;
    stringstream ss;  // Create a stringstream

    ss << "book - " << bookName << "\n";
    for(auto person : issures){

        ss<<personalDetail.getUserSummary(person.first)<<"\n"<<"BOOK ISSUE FROM & TILL - \n";

        ss << "From - " << person.second.first.tm_mday << " / "
           << person.second.first.tm_mon << " / "
           << person.second.first.tm_year << "\n";

        ss << "To - " << person.second.second.tm_mday << " / "
           << person.second.second.tm_mon << " / "
           << person.second.second.tm_year << "\n\n";
    }

    cout<<ss.str();
    return ss.str(); // Return the entire built string
}
