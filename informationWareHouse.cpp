#include "informationWareHouse.h"

unordered_map<string, book *> informationWareHouse::allBooks; //global static variable!

informationWareHouse::informationWareHouse()
{
}

bool informationWareHouse::addBook(string bookName, int totalCount){
    book *obj = new book();
    obj->addNewBook(bookName, totalCount);

    allBooks[bookName] = obj;
    return true;
}



//issue main driver Function
bool informationWareHouse::issueBook(string bookName, int id){
    auto ptrToBook = allBooks.find(bookName);

    if(ptrToBook == allBooks.end()){
        cout<<"$ Book not avialble\n";
        return false;
    }

    members *issueBook = new members();
    if(!issueBook->canIssueBook(id, bookName)){
        return false;
    }

    book *requiredBook = ptrToBook->second;
    if(!requiredBook->issuedTo(id)){
        return false;
    }
    issueBook->haveIssued(id, bookName);

    delete issueBook;
    return true;
}

informationWareHouse::~informationWareHouse()
{
}


string informationWareHouse::allIssuers(string bookName){
    auto locator = allBooks.find(bookName);

    if(locator == allBooks.end()){
        cout<<"no book of the name - "<<bookName;
        return "";
    }
    return locator->second->allIssuers();
}


int informationWareHouse::returningBook(string& bookName, int id){
    auto locator = allBooks.find(bookName);
    if(locator == allBooks.end()){
        return -1;
    }
    else{
        return locator->second->returnBook(id);
    }
    return -1;
}
