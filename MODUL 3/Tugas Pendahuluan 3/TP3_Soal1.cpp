// NIM / NAMA   : 19623023 / ABRAR ABHIRAMA WIDYADHANA
// FAKULTAS     : STEI-K

#include <iostream>

class LinearLine 
{
private:
    float x1, y1, x2, y2;

public:
    LinearLine(float x1, float y1, float x2, float y2) : x1(x1), y1(y1), x2(x2), y2(y2) {     
    }

    float gradient() {
        return (y2 - y1) / (x2 - x1);
    }

    float y_intercept() {
        return y1 - gradient() * x1;
    }

    void operator+(float a) {
        x1 += a;
        x2 += a;
    }

    void printEquation() {
        std::cout << "y = " << gradient() << "x + " << y_intercept() << std::endl;
    }

    void printPoints() {
        std::cout << "(" << x1 << ", " << y1 << ") = (" << x2 << ", " << y2 << ")" << std::endl;
    }
};

int main() {
    LinearLine line(1.0f, 8.0f, 2.0f, 3.0f);

    std::cout << "(x1, y1) = (" << line.x1 << ", " << line.y1 << ")" << std::endl;
    std::cout << "(x2, y2) = (" << line.x2 << ", " << line.y2 << ")" << std::endl;

    std::cout << "Gradient = " << line.gradient() << std::endl;
    std::cout << "Y-Intercept = " << line.y_intercept() << std::endl;

    line.printEquation();

    int a = 3;
    line + a;

    std::cout << a << std::endl;
    line.printEquation();

    return 0;
}