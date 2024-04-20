#include <bits/stdc++.h>

class Member {
private:
    std::string name;
    std::string userId;
    std::vector<std::string> bookList;
    int currentBook;
public:
    Member();
    Member(std::string name, std::string userId);
    std::string getName();
    void addBook();
    void readBookList();
    void readCurBook();
    void updateBook();
    void deleteBook();
    void changeCurBook();
};

class MemberList {
private:
    std::vector<Member> memList;
public:
    void memberMenu();
    void addMember();
    void viewMembers();
    void searchMember();
    void deleteMember();
};

int main() {
    int n = 0;
    MemberList memberList;

    while(1) {
        std::cout << "Welcome to Library Management:\n";
        std::cout << "Press 1 to Create New Member\n";
        std::cout << "Press 2 to Enter Member Menu (Update/Search/Add)\n";
        std::cout << "Press 3 to View All Members\n";
        std::cout << "Press 4 to Delete Member\n";
        std::cout << "Press 5 to Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> n;

        if (n == 1) {
            memberList.addMember();
        } else if (n == 2) {
            memberList.memberMenu();
        } else if (n == 3) {
            memberList.viewMembers();
        } else if (n == 4) {
            memberList.deleteMember();
        } 
        else if (n == 5) break;
        else std::cout << "Please Enter valid input!";

        std::cout << std::endl << std::endl;
    }
}

Member::Member() {
    name = "";
    userId = "";
    currentBook = -1;
}

Member::Member(std::string name, std::string userId) {
    this -> name = name;
    this -> userId = userId;
    currentBook = -1;
}

std::string Member::getName() { 
    return name; 
}

void Member::addBook() {
    std::string bookName;
    std::cout << "Enter Book Name: ";
    std::cin >> bookName;
    bookList.push_back(bookName);
    currentBook = bookList.size() - 1;
}

void Member::readBookList() {
    if (bookList.size() == 0) std::cout << "No Books present";
    else for (int i = 0; i < bookList.size(); i++) std::cout << bookList[i] << " ";
}

void Member::readCurBook() {
    if (currentBook == -1) std::cout << "No current books";
    else std::cout << bookList[currentBook];
}

void Member::updateBook() {
    std::string oldBook;
    std::cout << "Enter the book name to change: ";
    std::cin >> oldBook;
    int oldB = -1;
    for (int i = 0; i < bookList.size(); i++) 
        if (bookList[i] == oldBook) {
            oldB = i;
            break;
        }
    if (oldB == -1) std::cout << "No such book present in book list!";
    else {
        std::cout << "Enter new book name: ";
        std::cin >> bookList[oldB];
        std::cout << "Changes made successfully!";
    }
}

void Member::deleteBook() {
    std::string bookName;
    std::cout << "Enter book to delete: ";
    std::cin >> bookName;
    int present = 0;

    for (int i = 0; i < bookList.size(); i++) {
        if (bookName == bookList[i]) {
            bookList.erase(bookList.begin() + i);
            present = 1;
            break;
        }
    }
    if (present) std::cout << "Delete successful!";
    else std::cout << "Delete unsuccessful, book not present in list";
}

void Member::changeCurBook() {
    std::string bookName;
    std::cout << "Enter Book Name: ";
    std::cin >> bookName;
    int present = 0;
    for (int i = 0; i < bookList.size(); i++) {
        if (bookList[i] == bookName) {
            currentBook = i;
            present = 1;
            break;
        }
    }
    if (present) std::cout << "Updated current book successfully";
    else std::cout << "Update unsuccessful, book not present in list";
}

void MemberList::memberMenu() {
    std::string memberName;
    Member *curMem;
    std::cout << "Enter member name to select: ";
    std::cin >> memberName;

    int got = 0;
    for (int i = 0; i < memList.size(); i++) {
        if (memList[i].getName() == memberName) {
            curMem = &memList[i];
            got = 1;
        }
    }

    if (!got) std::cout << "No such member present!";
    else {
        int m = 0;
        while(1) {
            std::cout << "\n" << memberName << " Member Menu:\n";
            std::cout << "Press 1 to view books under member\n";
            std::cout << "Press 2 to add book\n";
            std::cout << "Press 3 to view curent book\n";
            std::cout << "Press 4 to update book\n";
            std::cout << "Press 5 to delete book\n";
            std::cout << "Press 6 to change current book\n";
            std::cout << "Press 7 to return to main menu\n";
            std::cout << "Enter your choice: ";
            std::cin >> m;

            if (m == 1) {
                (*curMem).readBookList();
            } else if (m == 2) {
                (*curMem).addBook();
            } else if (m == 3) {
                (*curMem).readCurBook();
            } else if (m == 4) {
                (*curMem).updateBook();
            } else if (m == 5) {
                (*curMem).deleteBook();
            } else if (m == 6) {
                (*curMem).changeCurBook();
            } else if (m == 7) {
                break;
            } else {
                std::cout << "Enter valid input!";
            }
            std::cout << std::endl << std::endl;
        }
    }
}

void MemberList::addMember() {
    std::string name, id;
    std::cout << "Enter name of member: ";
    std::cin >> name;
    std::cout << "Enter ID of member: ";
    std::cin >> id;
    Member newMem(name, id);
    memList.push_back(newMem);
}

void MemberList::viewMembers() {
    if (memList.size() == 0) std::cout << "No members present";
    else for (int i = 0; i < memList.size(); i++) std::cout << memList[i].getName() << " ";
}

void MemberList::searchMember() {
    std::string name;
    std::cout << "Enter member name to search: ";
    std::cin >> name;

    int got = 0;

    for (int i = 0; i < memList.size(); i++) {
        if (memList[i].getName() == name) {
            got = 1;
            std::cout << "Details of " << name << ":\n";
            memList[i].readBookList();
            break;
        }
    }

    if (!got) std::cout << "No such member exists.";
}

void MemberList::deleteMember() {
    std::string memName;
    std::cout << "Enter Member to delete: ";
    std::cin >> memName;
    int present = 0;

    for (int i = 0; i < memList.size(); i++) {
        if (memName == memList[i].getName()) {
            memList.erase(memList.begin() + i);
            present = 1;
            break;
        }
    }
    if (present) std::cout << "Delete successful!";
    else std::cout << "Delete unsuccessful, member not present in list";
}