#include <iostream>
#include <cstring>

using namespace std; 

class String {
private:
    char* s;

public:
    String() : s(nullptr) {}

    String(const char* t) : s(nullptr) {
        sets(t);
    }

    String(char t) : s(nullptr) {
        char r[2] = { t, '\0' };
        sets(r);
    }

    String(int t) : s(nullptr) {
        char r[20];
        snprintf(r, sizeof(r), "%d", t);
        sets(r);
    }

    String(const String& R) : s(nullptr) {
        sets(R.gets());
    }

    ~String() {
        if (s) {
            delete[] s;
            s = nullptr;
        }
    }

    void sets(const char* r) {
        if (s) {
            delete[] s;
            s = nullptr;
        }
        s = _strdup(r);
    }

    const char* gets() const {
        return s;
    }

    int len() const {
        return (strlen(s));
    }

    void Sort() {
        int l = len();
        for (int i = 1; i < l; ++i) {
            char key = s[i];
            int j = i - 1;
            while (j >= 0 && s[j] > key) {
                s[j + 1] = s[j];
                j = j - 1;
            }
            s[j + 1] = key;
        }
    }

    void Merge(const String& other) {
        int Len = len();
        int totalLen = Len + other.len();
        char* merged = new char[totalLen + 1];
        int i = 0;
        for (; i < Len; i++) {
            merged[i] = s[i];
        }
        for (int j = 0; j < other.len(); j++, i++) {
            merged[i] = other.s[j];
        }
        merged[totalLen] = '\0';
        delete[] s;
        s = merged;
    }

    void replace(const char* A, const char* B) {
        char* pos = strstr(s, A);
        if (pos) {
            int lenDiff = strlen(B) - strlen(A);
            int newLen = len() + lenDiff;
            char* newStr = new char[newLen + 1];

            int i = 0;
            while (s + i < pos) {
                newStr[i] = s[i];
                i++;
            }

            for (int j = 0; B[j] != '\0'; j++) {
                newStr[i] = B[j];
                i++;
            }

            for (int j = 0; s + i - j < s + len() - strlen(A); j++) {
                newStr[i] = s[i - j];
                i++;
            }

            newStr[newLen] = '\0';

            delete[] s;
            s = newStr;
        }
    }

    int search(const char* t) const {
        int tLen = strlen(t);
        int strLen = len();
        for (int i = 0; i <= strLen - tLen; i++) {
            bool found = true;
            for (int j = 0; j < tLen; j++) {
                if (s[i + j] != t[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }
        return -1;
    }

    String& operator=(const String& other) {
        if (this == &other) {
            return *this;
        }

        sets(other.gets());

        return *this;
    }

    bool operator==(const String& R) const {
        return strcmp(s, R.s) == 0;
    }

    bool operator<=(const String& R) const {
        return strcmp(s, R.s) <= 0;
    }

    bool operator>=(const String& R) const {
        return strcmp(s, R.s) >= 0;
    }

    bool operator!=(const String& R) const {
        return strcmp(s, R.s) != 0;
    }

    char& operator[](int index) {
        return s[index];
    }

    char operator()(int index) const {
        return s[index];
    }

    void display() const {
        cout << gets() << endl;
    }
};

int main() {
    String a("edcba");
    String b("12345");
    String c;

    cout << "Original String 'a': ";
    a.display();

    cout << "Original String 'b': ";
    b.display();

    a.Sort();
    cout << "Sorted String 'a': ";
    a.display();

    c = a;
    c.Merge(b);
    cout << "Merged String 'c': ";
    c.display();

    int index = b.search("234");
    if (index != -1) {
        cout << "'234' found at position: " << index << endl;
    }
    else {
        cout << "'234' not found." << endl;
    }

    a.replace("cde", "xyz");
    cout << "String 'a' after replacement: ";
    a.display();

    return 0;
}
