#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class cuboid {


private:
	int l, w, h;
public:
	cuboid(int a = 1, int b = 1, int c = 1) {
		setl(a);
		setw(b);
		seth(c);
	}
	cuboid(const cuboid& r)  {
		setl(r.l);
		setw(r.w);
		seth(r.h);
	}

	~cuboid(){}
	inline void setl(int t) {
		this->l = t;
	}
	inline void setw(int e) {
		this->w =e;
	}
	inline void seth(int r) {
		this->h = r;
	}
	inline int getl()const {
		return l;
	}
	inline int getw()const {
		return w;
	}
	inline int geth()const {
		return h;
	}


	friend istream& operator>>(istream& input, cuboid& r) {
		cout << "Enter length, width, and height: ";
		input >> r.l>> r.w>> r.h;
		return input;
	}
	friend ostream& operator<<(ostream& out, const cuboid& r) {
		out << "Cuboid (L: " << r.getl() << ", W: " << r.getw() << ", H: " << r.geth() << ")";
		return out;
	}

	int getarea()const {
		return getl() * getw();
	}
	int getvolume()const {
		return getl() * getw() * geth();
	}

	double getLateralSurfaceArea() const {
		return 2 * (double(getl() * getw()) + (getw() * geth()) + (geth() * getl()));
	}

	double getPerimeter() const {
		return 4 *(double(getl()) + getw() + geth());
	}

	double getDiagonal() const {//sgrt(l*l+w*w+h*h)
		return sqrt(getl() * getl() + getw() * getw() + geth() * geth());
	}

	double getTotalSurfaceArea() const {
		return 2 * (double(getl() * getw()) + (getw() * geth()) + (geth() * getl()));
	}

	double getBaseArea() const {
		return (double(getl())* getw());
	}


};

class ListC {
private:
    struct Node {
        cuboid data;
        Node* next;
        Node(const cuboid& c) : data(c), next(NULL) {}
    };

    Node* root;

public:
    ListC() : root(NULL) {}

    ~ListC() {
        while (root != NULL) {
            Node* temp = root;
            root = root->next;
            delete temp;
        }
    }

    void insert(const cuboid& r) {
        Node* p = new Node(r);//creat a new node 

        if (!root || r.getvolume() <= root->data.getvolume()) {
            p->next = root;
            root = p;
        }
        else {
            Node* cur = root;
            while (cur->next && r.getvolume() > cur->next->data.getvolume()) {
                cur = cur->next;
            }
            p->next = cur->next;
            cur->next = p;
        }
    }

    bool search(const cuboid& r) {
        Node* cur = root;
        while (cur) {
            if (cur->data.getl() == r.getl() &&
                cur->data.getw() == r.getw() &&
                cur->data.geth() == r.geth()) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    double averageVolume() {
        double sum = 0;
        int count = 0;
        Node* cur = root;
        while (cur) {
            sum += cur->data.getvolume();
            count++;
            cur = cur->next;
        }
        return count > 0 ? sum / count : 0.0;
    }

    void display() {
        Node* cur = root;
        while (cur) {
            cout << cur->data << endl;
            cur = cur->next;
        }
    }
};

int main() {
    ListC c;//list of cuboid

    int n ;//number of cuboid
    cout << "Enter the number of cuboids: ";
    cin >> n ;

    for (int i = 0; i < n ; i++) {//inseart a cuboide
        cuboid r;
        cin >> r;
        c.insert(r);
    }

    cout << "Sorted list of cuboids:" << endl;
    c.display();

    cuboid key;
    cout << "Enter a cuboid to search for:" << endl;
    cin >> key;

    if (c.search(key)) {
        cout << " cuboid is found ." << endl;
    }
    else {
        cout << " cuboid is not found ." << endl;
    }

    double avgVolume = c.averageVolume();
    cout << "Average volume of all cuboids: " << avgVolume << endl;

    return 0;
}