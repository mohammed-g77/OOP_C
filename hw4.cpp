#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;



class d3Shape {
    double l;//side length

public:
    d3Shape(int a=1):l(a){}
    virtual double getarea() const = 0;
    virtual double getsurface() const = 0;
    virtual double getvolume() const = 0;
    virtual string IsA() const = 0;
    virtual void print() const = 0;
    virtual void read() = 0;


};

class Cuboid : public d3Shape {

private:
    double l;
    double w;
    double h;
public:
    Cuboid(double length, double width, double height)
        : l(length), w(width), h(height) {}

    double getarea() const  {
        return 2 * (l * w + l * h + w * h);
    }

    double getsurface() const  {
        return 2 * (l * w + l * h + w * h);
    }

    double getvolume() const  {
        return l * w * h;
    }

    string IsA() const  {
        return "Cuboid->";
    }

    void print() const  {
        cout << IsA() << " Length: " << l << ", Width: " << w <<  ", Height: " << h << endl;
    }

    void read()  {
        cout << IsA() << "Enter Length: ";
        cin >> l;
        cout << IsA() << "Enter Width: ";
        cin >> w;
        cout << IsA() << "Enter Height: ";
        cin >> h;
    }

};

class Cube : public d3Shape {
private:
    double l;

public:
    Cube(double side) : l(side) {}

    double getarea() const  {
        return 6 * l * l;
    }

    double getsurface() const  {
        return 6 * l * l;
    }

    double getvolume() const  {
        return l * l * l;
    }

    string IsA() const  {
        return "Cube->";
    }

    void print() const  {
        cout << IsA()<<"Length:" << l << endl;
    }

    void read() {
        cout << IsA() << "Enter Length: ";
        cin >> l;
    }
};

class Cone : public d3Shape {
private:
    double r;
    double h;

public:
    Cone(double R, double H) : r(R), h(H) {}

    double getarea() const {
        double baseArea = 3.14 * r * r;
        double sideArea = 3.14 * r * sqrt(r * r + h * h);
        return baseArea + sideArea;
    }

    double getsurface() const {
        
        return 3.14 * r * sqrt(r * r + h * h);
    }

    double getvolume() const {
        return (1.0 / 3.0) * 3.14 * r * r * h;
    }

    string IsA() const {
        return "Cone->";
    }

    void print() const {
        cout << IsA()<<" Radius: " << r <<", Height: " << h << endl;
    }

    void read() {
        cout << IsA() << "Enter Radius: ";
        cin >> r;
        cout << IsA() << "Enter Height: ";
        cin >> h;
    }
};

class Pyramid : public d3Shape {
private:
    double baseL;//base length
    double h;

public:
    Pyramid(double base, double H) : baseL(base), h(H) {}

    double getarea() const {
        double baseArea = baseL * baseL;
        double sideArea = baseL * sqrt(baseL * baseL / 4 + h * h);
        return baseArea + 4 * sideArea;
    }

    double getsurface() const {
        
        return 4 * baseL * sqrt(baseL * baseL / 4 + h * h);
    }

    double getvolume() const {
        return (1.0 / 3.0) * baseL * baseL * h;
    }

    string IsA() const {
        return "Pyramid->";
    }

    void print() const {
        cout << IsA() << "  Base Length: " << baseL << ", Height: " << h << endl;
    }

    void read() {
        cout << IsA() << "Enter Base Length: ";
        cin >> baseL;
        cout << IsA() << "Enter Height: ";
        cin >> h;
    }
};

class RegularTetrahedron : public d3Shape {
private:
    double L;

public:
    RegularTetrahedron(double side) : L(side) {}

    double getarea() const {
        return sqrt(3) * L * L;
    }

    double getsurface() const {
        return sqrt(3) * L * L;
    }

    double getvolume() const {
        return (1.0 / 12.0) * sqrt(2) * L * L * L;
    }

    string IsA() const {
        return "Regular Tetrahedron->";
    }

    void print() const {
        cout << IsA() << "Side Length: " << L << endl;
    }

    void read() {
        cout << IsA() << "Enter Side Length: ";
        cin >> L;
    }
};

class Sphere : public d3Shape {
private:
    double r;

public:
    Sphere(double R ) : r(R) {}

    double getarea() const {
        return 4 * 3.14159 * r * r;
    }

    double getsurface() const {
        return 4 * 3.14159 * r * r;
    }

    double getvolume() const {
        return (4.0 / 3.0) * 3.14159 * r * r * r;
    }

    string IsA() const {
        return "Sphere->";
    }

    void print() const {
        cout << IsA() << " Radius: " << r << endl;
    }

    void read() {
        cout << IsA() << "Enter Radius: ";
        cin >> r;
    }
};

class Cylinder : public d3Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double r, double h) : radius(r), height(h) {}

    double getarea() const {
        double baseArea = 3.14159 * radius * radius;
        double sideArea = 2 * 3.14159 * radius * height;
        return 2 * baseArea + sideArea;
    }

    double getsurface() const {
        return getarea();
    }

    double getvolume() const {
        return 3.14159 * radius * radius * height;
    }

    string IsA() const {
        return "Cylinder->";
    }

    void print() const {
        cout << IsA() << "Radius: " << radius  << ", Height: " << height << endl;
    }

    void read() {
        cout << IsA() << "Enter Radius: ";
        cin >> radius;
        cout << IsA() << "Enter Height: ";
        cin >> height;
    }
};

int main() {
    const int maxSize = 10;
    d3Shape* S[maxSize];
    int sCount = 0;//number of shapes
    int c;

    while (true) {
        cout << endl;
        cout << "1. Add Shape" << endl;
        cout << "2. Print Information" << endl;
        cout << "3. Sort by Surface Area" << endl;
        cout << "4. Find Min and Max Volume" << endl;
        cout << "5. Delete Shape" << endl;
        cout << "6. Exit" << endl;
        cout << endl;

        cout << "Enter your choice: ";cout << endl;

        cin >> c;

        switch (c) {
        case 1:
            if (sCount < maxSize) {
                int ch;
                cout << "Select shape type: 1 for Cuboid, 2 for Cube,3 for Cone ,4 for Pyramid,5 for RegularTetrahedron,6 for Sphere,7 for Cylinder" << endl;
                cin >> ch;

                d3Shape* S2=NULL;
                if (ch == 1) {
                    S2 = new Cuboid(0, 0, 0);
                }
                else if (ch == 2) {
                    S2 = new Cube(0);
                }
                else if (ch == 3) {
                    S2 = new Cone(0,0);
                }
                else if (ch == 4) {
                    S2 = new  Pyramid(0,0);
                }
                else if (ch == 5) {
                    S2 = new RegularTetrahedron(0);
                }
                else if (ch == 6) {
                    S2 = new Sphere(0);
                }
                else if (ch == 7) {
                    S2 = new Cylinder(0,0);
                }

                S2->read();
                S[sCount] = S2;
                sCount++;
            }
            else {
                cout << "Array is full. Cannot add more shapes." << endl;
            }
            break;

        case 2:
            for (int i = 0; i < sCount; i++) {
                S[i]->print();
            }
            break;

        case 3:
            sort(S, S + sCount, [](const d3Shape* a, const d3Shape* b) {
                return a->getsurface() < b->getsurface();
                });
            cout << "Shapes sorted by surface area." << endl;
            break;

        case 4:
            if (sCount > 0) {
                d3Shape* minVolumeShape = *min_element(S, S + sCount, [](const d3Shape* a, const d3Shape* b) {
                    return a->getvolume() < b->getvolume();
                    });

                d3Shape* maxVolumeShape = *max_element(S, S + sCount, [](const d3Shape* a, const d3Shape* b) {
                    return a->getvolume() < b->getvolume();
                    });

                cout << "Shape with minimum volume: ";
                minVolumeShape->print();
                cout << "Shape with maximum volume: ";
                maxVolumeShape->print();
            }
            else {
                cout << "No shapes to find min and max volume." << endl;
            }
            break;

        case 5:
            if (sCount > 0) {
                int Index;
                cout << "Enter the index of the shape to delete: ";
                cin >> Index;

                if (Index >= 0 && Index < sCount) {
                    delete S[Index];
                    for (int i = Index; i < sCount - 1; i++) {
                        S[i] = S[i + 1];
                    }
                    sCount--;
                    cout << "Shape deleted." << endl;
                }
                else {
                    cout << "Invalid index. No shape deleted." << endl;
                }
            }
            else {
                cout << "No shapes to delete." << endl;
            }
            break;

        case 6:
            // Clean up dynamically allocated memory
            for (int i = 0; i < sCount; i++) {
                delete S[i];
            }
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (c != 6);

    return 0;
}





