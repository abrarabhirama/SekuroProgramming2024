// NIM / NAMA   : 19623023 / ABRAR ABHIRAMA WIDYADHANA
// FAKULTAS     : STEI-K

#include <iostream>

class Shape {
private:
    float area;
    float keliling;

public:
    virtual float calculateArea() {return 0;}

    float calculateKeliling() {return 0;}
};

class Rectangle : public Shape {
private:
    float width;
    float length;

public:
    Rectangle(float w, float l) : width(w), length(l) {}
    float calculateArea() override {
        return width * length;
    }
    float calculateKeliling() override {
        return 2 * (width + length);
    }
};

int main() {
    Rectangle rect(5.0, 4.0);
    Shape* shape1 = &rect;
    float area = shape1->calculateArea();
    float keliling = shape1->calculateKeliling();
    std::cout << "Area: " << area << std::endl;
    std::cout << "Keliling: " << keliling << std::endl;

    return 0;
}