#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string book_id;
    string book_title;
    int year_of_publication;
    int price;
public:
    string getBookID() {
        return book_id;
    }
    string getBookTitle() {
        return book_title;
    }
    int getYearOfPublication() {
        return year_of_publication;
    }
    int getPrice() {
        return price;
    }
    friend istream& operator >> (istream& is, Book& book) {
        is >> book.book_id;
        is.ignore();
        getline(is, book.book_title);
        is >> book.year_of_publication;
        is >> book.price;
        return is;
    }

    friend ostream& operator << (ostream& os, Book book) {
        os << "[" << book.book_id << "] - " << book.book_title << "___" << book.year_of_publication << " //Price: " << book.price << "$";
        return os << '\n';
    }

    Book operator = (Book another) {
        this->book_id = another.book_id;
        this->book_title = another.book_title;
        this->year_of_publication = another.year_of_publication;
        this->price = another.price;
        return *this;
    }

    void setID(string id) {
        this->book_id = id;
    }
    void setTitle(string title) {
        this->book_title = title;
    }
};

class Solution {
private:
    vector<Book> books;
public:
    Solution() {}
    void printBookList() {
        for (const Book& book : books) {
            cout << book;
        }
    }
    int getSize() {
        return books.size();
    }
    //a
    void init() {
        int n; cin >> n;
        books.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> books[i];
        }
    }
    //b
    void search(string x, string y) {
        bool found = false;
        for (int i = 0; i < int(books.size()) - 1; ++i) {
            if (books[i].getBookTitle() == x) {
                found = true;
                books[i].setTitle(y);
            }
        }
        if (!found)
            cout << "There are no books titled " << x << '\n';
        else {
            cout << "Changed the id of book " << x << " to " << y << '\n';
            cout << "After changed\n";
            printBookList();
        }
    }
    //c
    int binarySearch(string x) {
        int left = 0, right = int(books.size()) - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (books[middle].getBookID() == x) {
                return middle;
            }
            else if (books[middle].getBookID() < x) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return -1;
    }
    void remove(int pos, string x) {
        if (pos != -1) {
            books.erase(begin(books) + pos);
            cout << "Deleted books with id = " << x << '\n';
        }
        else {
            cout << "Not found!\n";
        }
    }
    //d
    void SelectionSort() {
        int idx, n = int(books.size());
        for (int i = 0; i < n - 1; ++i) {
            idx = i;
            for (int j = i + 1; j < n; ++j) {
                if (books[j].getBookID() < books[i].getBookID()) {
                    idx = j;
                }
            }
            if (idx != i)
                swap(books[i], books[idx]);
        }
    }
    //e
    void InsertionSort() {
        int pos, n = int(books.size());
        Book data;
        for (int i = 1; i < n; ++i) {
            pos = i;
            data = books[pos];
            while (pos > 0 && books[pos - 1].getYearOfPublication() < data.getYearOfPublication()) {
                books[pos] = books[pos - 1];
                pos--;
            }
            books[pos] = data;
        }
    }
    //f
    void bubbleSort() {
        int n = int(books.size());
        for (int i = n - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (books[j].getBookTitle() < books[j + 1].getBookTitle()) {
                    swap(books[j], books[j + 1]);
                }
            }
        }
    }
    //g
    int partition(int left, int right) {
        int i = left - 1, j = right + 1;
        int pivot = books[left].getPrice();
        while (true) {
            do { --j; } while (books[j].getPrice() < pivot);
            do { ++i; } while (books[i].getPrice() > pivot);
            if (i >= j) {
                return j;
            }
            swap(books[i], books[j]);
        }
    }

    void quickSort(int left, int right) {
        if (left >= right) return;
        int mid = partition(left, right);
        quickSort(left, mid);
        quickSort(mid + 1, right);
    }
};

int main() {
    Solution Lab2_5;
    Lab2_5.init();
    cout << "Before\n";
    Lab2_5.printBookList();

    string x, y;
    cin.ignore();
    getline(cin, x);
    getline(cin, y);
    Lab2_5.search(x, y);

    string X;
    Lab2_5.SelectionSort();
    //cout << "After Selection Sort (Increasing by id)\n";
    Lab2_5.printBookList();
    getline(cin, X);
    Lab2_5.remove(Lab2_5.binarySearch(X), X);
    //cout << "After Delete " << X << "\n";
    Lab2_5.printBookList();

    Lab2_5.InsertionSort();
    //cout << "After Insertion Sort (Decreasing by year of publication)\n";
    Lab2_5.printBookList();

    Lab2_5.bubbleSort();
    //cout << "After Bubble Sort (Increasing by title)\n";
    Lab2_5.printBookList();

    Lab2_5.quickSort(0, Lab2_5.getSize() - 1);
    //cout << "After Quick Sort(Decreasing by price)\n";
    Lab2_5.printBookList();
    return 0;
}

/*
5
00001
Nhung Cau Chuyen Buon
1999
30
000050
Nhung cau chuyen nham nhi
1985
25
000120
Chuyen tinh Lan va Diep
2024
100
000100
Cach de lua mot con vit
2024
50
000055
Tat ca deu la anh em, hoa dong
2023
10
Nhung Cau Chuyen Buon
Nhung cau chuyen buon cuoi, doc xong vut ca sach
000050
*/