#include <iostream>
#include <cmath>
#include "matrix.h"
/*m1是2x3 全为1的矩阵 
  m2是2x3 全为2的矩阵
  m4是3x3 全为5的矩阵
*/
int main() {
    try {
        
    std::cout<<"===矩阵创建演示===： "<<std::endl;
    std::cout<<"2x3（全为1）： "<<std::endl;

    Matrix m1(2,3,1);
    std::cout<<m1<<std::endl;
    
    Matrix m2(2,3,2);
    std::cout<<"2x3（全为2）： "<<std::endl;
    std::cout<<m2<<std::endl;
    
    Matrix m4 (3,3,5);
    
    std::cout<<"=== 测试矩阵加法 ===: "<<std::endl;
    
    std::cout<<"m1:"<<std::endl;
    std::cout<<"2x3： "<<std::endl;
    std::cout<<m1<<std::endl;
    std::cout<<"m2"<<std::endl;
    std::cout<<"2x3： "<<std::endl;
    std::cout<<m2<<std::endl;

    std::cout<<"m1+m2："<<std::endl;
    Matrix m3=m1+m2;
    std::cout<<m3<<std::endl;
    
    //尝试乘法：
    std::cout<<"尝试m3xm4"<<std::endl;
    std::cout<<m3*m4<<std::endl;

    //一个3X3的矩阵与2X3的相加抛出异常
    std::cout<<"尝试 m3 + m4 (维度不匹配):"<<std::endl;
    std::cout<<m4+m3<<std::endl;


    //尝试乘法：
    std::cout<<"尝试m3xm4"<<std::endl;
    std::cout<<m3*m4<<std::endl;

    } catch (const MatrixException& e) {
        std::cout << "捕获到异常: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "未知异常" << std::endl;
    }
    return 0;
}
