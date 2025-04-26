#include "book.h"


class informationWareHouse
{
private:
    static unordered_map<string, book *> allBooks;
public:
    informationWareHouse();
    ~informationWareHouse();

    bool addBook();
    bool issueBook(string bookname, int id); // to develop
    string allIssuers(string bookName);
};
