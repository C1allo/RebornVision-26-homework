#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>

class MatrixException {
private:
    std::string message;
    
public:
    MatrixException(const std::string& msg) : message(msg) {}
    
    const char* what() const {
        return message.c_str();
    }
};

// 矩阵类
class Matrix {
private:
    int rows;  // 行数
    int cols;  // 列数
    std::vector<std::vector<double>> data;  // 存储矩阵数据

public:
    // 构造函数
    Matrix();                              // 默认构造函数
    Matrix(int r, int c);                   // 指定维度
    Matrix(int r, int c, double value);     // 指定维度和初始值
    
    // 运算符重载
    Matrix operator+(const Matrix& other) const;  // 矩阵加法
    Matrix operator*(const Matrix& other) const;  // 矩阵乘法
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix); // 输出运算符
    
    // 基本操作
    void setValue(int row, int col, double value);  // 设置元素值
    double getValue(int row, int col) const;        // 获取元素值
    
    // 工具函数
    int getRows() const;     // 获取行数
    int getCols() const;     // 获取列数
    
    // 检查函数
    bool isSameDimension(const Matrix& other) const;      // 检查能否相加
    bool canMultiply(const Matrix& other) const;         // 检查能否相乘
};


