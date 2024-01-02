#include <iostream>
#include <vector>

class matrix {
private:
    std::vector<std::vector<double>> data;
    size_t rows;
    size_t cols;

public:
    matrix(const std::vector<std::vector<double>>& input) : data(input), rows(input.size()), cols(input[0].size()) {}
    matrix(size_t numRows, size_t numCols) : rows(numRows), cols(numCols) {
        data.resize(numRows, std::vector<double>(numCols, 0));
    }
    matrix operator+(const matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cout << "The matrix dimension is not valid!" << std::endl;
            return matrix(1, 1);
        }
        matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    matrix operator-(const matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cout << "The matrix dimension is not valid!" << std::endl;
            return matrix(1, 1);
        }

        matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    matrix operator*(const matrix& other) const {
        if (cols != other.rows) {
            std::cout << "Multiplication cannot be done. The number of columns in the first matrix should be equal to the number of rows in the second." << std::endl;
            return matrix(1, 1);
        }

        matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    void display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Behavior Matrixnya
int main() {
    matrix A({{1, 2, 3}, {2, 3, 1}});
    matrix B({{0, 2, 4}, {1, 2, 5}, {8, 2, 1.2}});
    matrix C(2, 3);

    std::cout << "Matrix A\n";
    A.display();
    std::cout << "Matrix B\n";
    B.display();
    std::cout << "Matrix C\n";
    C.display();
    std::cout << '\n';

    matrix C1 = A + C;
    std::cout << "Matrix C1\n";
    C1.display();
    std::cout << '\n';

    matrix C2 = A - C;
    std::cout << "Matrix C2\n";
    C2.display();
    std::cout << '\n';

    matrix C3 = A * B;
    std::cout << "Matrix C3\n";
    C3.display();
    std::cout << '\n';

    matrix C4 = B * A;
    std::cout << "Matrix C4\n";
    C4.display();
    std::cout << '\n';

    return 0;
}

