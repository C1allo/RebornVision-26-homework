# 构造函数
- `Matrix()`：默认构造，空矩阵。  

- `Matrix(int r, int c)：`创建 r 行 c 列矩阵，元素初始为0。

- `Matrix(int r, int c, double value)`：创建 r 行 c 列矩阵，元素初始为 value。 
 

# 运算符
- `+`：矩阵加法，要求行列数相同。 

- `*`：矩阵乘法，要求左列数等于右行数。  

- `<<`：输出矩阵，格式为行数、列数及元素。  
 

# 方法
- `setValue/getValue`：设置 / 获取指定位置元素，带越界检查。  

- `getRows/getCols`：获取行数 / 列数。  

- `isSameDimension/canMultiply`：检查加法 / 乘法维度是否合法。  
 

# 异常
- `MatrixException` 类在维度错误、越界等情况抛出，含详细错误信息。