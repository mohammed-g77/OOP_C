
#include <iostream>
#include <string>

using namespace std;

class string {
	char* s;
public:
	string() :s(NULL) {}
	string(char* t) :s(NULL) { sets(t); }
  ~string() {
		delete[]s;
			s = NULL;
	}
  void sets(char* r) { s = r; }
  char* gets()const {
	  return s;
  }
  void sort(char*s){}
};