#include <iostream>
#include <cstring>

using namespace std;

class Book {
private:
    char* title;
    char* author;
    int pageCount;
    bool formatType;
    float* chapterPages;
    int numChapters;

public:
    Book() {
        title = new char[1];
        title[0] = '\0';
        author = new char[1];
        author[0] = '\0';
        pageCount = 0;
        formatType = false;
        numChapters = 0;
        chapterPages = 0;
    }

    Book(const char* t, const char* a, int pCount, bool fType, int nChapters) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        author = new char[strlen(a) + 1];
        strcpy(author, a);
        pageCount = pCount;
        formatType = fType;
        numChapters = nChapters;
        if (numChapters > 0) {
            chapterPages = new float[numChapters];
            float pagesPerChapter = static_cast<float>(pageCount) / numChapters;
            for (int i = 0; i < numChapters; i++) {
                chapterPages[i] = pagesPerChapter;
            }
        } else {
            chapterPages = 0;
        }
    }

    Book(const Book &other) {
        pageCount = other.pageCount;
        formatType = other.formatType;
        numChapters = other.numChapters;
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);
        if (numChapters > 0 && other.chapterPages != 0) {
            chapterPages = new float[numChapters];
            for (int i = 0; i < numChapters; i++) {
                chapterPages[i] = other.chapterPages[i];
            }
        } else {
            chapterPages = 0;
        }
    }

    ~Book() {
        delete[] title;
        delete[] author;
        delete[] chapterPages;
    }

    void modifyChapterPages(int chapterIndex, float newPageCount) {
        if (chapterIndex >= 0 && chapterIndex < numChapters && chapterPages != 0) {
            chapterPages[chapterIndex] = newPageCount;
        } else {
            cout << "Invalid chapter index!" << endl;
        }
    }

    void display() const {
        cout << "\nBook Details:" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Total Pages: " << pageCount << endl;
        cout << "Format: " << (formatType ? "Hardcover" : "Paperback") << endl;
        cout << "Chapters: " << numChapters << endl;
        if (chapterPages != 0) {
            for (int i = 0; i < numChapters; i++) {
                cout << "  Chapter " << i + 1 << ": " << chapterPages[i] << " pages" << endl;
            }
        } else {
            cout << "  No chapters available." << endl;
        }
    }
};

int main() {
    cout << "Creating book1 with default constructor." << endl;
    Book book1;
    book1.display();

    cout << "\nCreating book2 with parameterized constructor." << endl;
    Book book2("C++ Basics", "Alice", 200, true, 4);
    book2.display();

    cout << "\nModifying chapter 2 of book2." << endl;
    book2.modifyChapterPages(1, 70);
    book2.display();

    cout << "\nCreating book3 as a copy of book2." << endl;
    Book book3 = book2;
    book3.display();

    cout << "\nModifying chapter 3 of book3." << endl;
    book3.modifyChapterPages(2, 80);
    cout << "Book3 after modification:" << endl;
    book3.display();

    cout << "\nBook2 remains unchanged:" << endl;
    book2.display();

    return 0;
}

