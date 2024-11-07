#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Базовий клас
class A {
public:
    virtual void FileOpen(const char* path) {
        ifstream file(path);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
        else {
            cerr << "Error opening file: " << path << endl;
        }
    }
};

// Перший клас-нащадок
class B : public A {
public:
    void FileOpen(const char* path) override {
        ifstream file(path);
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                cout << static_cast<int>(ch) << " ";
            }
            cout << endl;
            file.close();
        }
        else {
            cerr << "Error opening file: " << path << endl;
        }
    }
};

// Другий клас-нащадок
class C : public A {
public:
    void FileOpen(const char* path) override {
        ifstream file(path, ios::binary);
        if (file.is_open()) {
            char ch;
            while (file.get(ch)) {
                for (int i = 7; i >= 0; --i) {
                    cout << ((ch >> i) & 1);
                }
                cout << " ";
            }
            cout << endl;
            file.close();
        }
        else {
            cerr << "Error opening file: " << path << endl;
        }
    }
};

int main() {
    char path[256];
    cout << "Input the path to the file: ";
    cin >> path;

    A a;
    B b;
    C c;

    cout << "Base class output:" << endl;
    a.FileOpen(path);

    cout << "\nDerived class B output (ASCII codes):" << endl;
    b.FileOpen(path);

    cout << "\nDerived class C output (Binary):" << endl;
    c.FileOpen(path);

    return 0;
}
