
#include <vector>
#include <iostream>
#include <string> 
#include <sstream>
#include "matrix.h"
using namespace std;


Matrix::Matrix() : rows(0), cols(0) {}

// 2. 创建指定大小的矩阵，初始值为0
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (r < 0 || c < 0) {
        throw MatrixException("矩阵维度不能为负数: " + to_string(r) + "x" + to_string(c));//to_string 转换为char
    }
    
    data.resize(rows);
    for (int i = 0; i < rows; i++) {
        data[i].resize(cols, 0.0);
    }
}

// 指定大小的矩阵，并用指定值初始化
Matrix::Matrix(int r, int c, double value) : rows(r), cols(c) {
    if (r < 0 || c < 0) {
        throw MatrixException("矩阵维度不能为负数: " + to_string(r) + "x" + to_string(c));
    }
    
    data.resize(rows);
    for (int i = 0; i < rows; i++) {
        data[i].resize(cols, value);
    }
}

// 4. 设置矩阵元素的值
void Matrix::setValue(int row, int col, double value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw MatrixException("位置"+to_string(row)+","+to_string(col) +"取值位置超出矩阵范围错误");
    }
    data[row][col] = value;
}

// 5. 获取矩阵元素的值
double Matrix::getValue(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        stringstream ss;//这个可以用<<拼接一堆，更加方便
        ss << "位置(" << row << "," << col << ")超出矩阵范围 " << rows << "x" << cols;
        throw MatrixException(ss.str());
    }
    return data[row][col];
}

// 6. 矩阵加法运算符重载
Matrix Matrix::operator+(const Matrix& other) const {
    if (!isSameDimension(other)) {
        stringstream ss;
        ss << "矩阵加法维度不匹配: " << rows << "x" << cols << " + " << other.rows << "x" << other.cols;
        throw MatrixException(ss.str());
    }
    
    Matrix result(rows, cols);
    for (int i = 0; i <rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// 7. 矩阵乘法运算符重载
Matrix Matrix::operator*(const Matrix& other) const {
    if(!canMultiply(other)){
         stringstream ss;
        ss << "矩阵乘法法维度不匹配: " << rows << "x" << cols << " x " << other.rows << "x" << other.cols;
        throw MatrixException(ss.str());
    }
     Matrix result(rows, other.cols);
     for (int i = 0;i<rows ;i++){
        for(int j=0;j<other.cols;j++){
            for(int k=0;k<cols;k++){
                result.data[i][j]+= data[i][k] * other.data[k][j];

            }
        }
     }

     return result;


}
// 8. 输出运算符重载
ostream& operator<<(ostream & os, const Matrix& matrix) {
    os<< "矩阵 " << matrix.rows << "x" << matrix.cols << ":" << endl;
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os<< matrix.data[i][j] << "\t";
        }
        os<< endl;
    }
    return os;
}

// 9. 获取行数
int Matrix::getRows() const {
    return rows;
}

// 10. 获取列数
int Matrix::getCols() const {
    return cols;
}

// 11. 检查两个矩阵能否相加
bool Matrix::isSameDimension(const Matrix& other) const {
    return (rows == other.rows && cols == other.cols);
}

// 12. 检查两个矩阵能否相乘
bool Matrix::canMultiply(const Matrix& other) const {
    return (cols == other.rows);
}
