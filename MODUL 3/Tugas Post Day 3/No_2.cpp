#include <iostream>
#include <vector>
#include <cmath>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(std::initializer_list<std::initializer_list<double>> values) {
        rows = values.size();
        cols = values.begin()->size();
        data.resize(rows, std::vector<double>(cols, 0.0));
        size_t i = 0, j = 0;
        for (const auto& row : values) {
            for (const auto& value : row) {
                data[i][j++] = value;
            }
            j = 0;
            ++i;
        }
    }

    Matrix(size_t rows, size_t cols, double initialValue = 0.0)
        : rows(rows), cols(cols), data(rows, std::vector<double>(cols, initialValue)) {}
    double& operator()(size_t row, size_t col) {
        return data[row][col];
    }
    const double& operator()(size_t row, size_t col) const {
        return data[row][col];
    }
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::runtime_error("Matrix multiplication error: invalid dimensions");
        }
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result(i, j) += data[i][k] * other(k, j);
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

class Swerve {
private:
    Matrix velocities;
    float r;           

    float x;    
    float y;          
    float theta;      

public:
    Swerve(float wheelDistance) : velocities(4, 1, 0.0), r(wheelDistance) {
        x = 0.0;
        y = 0.0;
        theta = 0.0;
    }
    void velocityCommand(float vx, float vy, float omega) {
        Matrix velocityMatrix({{1.0, 0.0, r, 0.0},
                               {0.0, 1.0, 0.0, r}});
        velocities = velocityMatrix * Matrix({{vx}, {vy}, {omega}, {0.0}});
    }

    void updatePose(float deltaTime) {
        x += velocities(0, 0) * deltaTime;
        y += velocities(1, 0) * deltaTime;
        theta += velocities(2, 0) * deltaTime;
        while (theta >= 2 * M_PI) {
            theta -= 2 * M_PI;
        }
        while (theta < 0) {
            theta += 2 * M_PI;
        }
    }
    void displayPose() const {
        std::cout << "Chassis Pose: x = " << x << ", y = " << y << ", theta = " << theta << std::endl;
    }
};

int main() {
    Swerve swerveDrive(0.26363);

    // Example usage
    swerveDrive.velocityCommand(1.0, 0.0, 0.5); 
    swerveDrive.updatePose(1.0); 
    swerveDrive.displayPose();

    return 0;
}
