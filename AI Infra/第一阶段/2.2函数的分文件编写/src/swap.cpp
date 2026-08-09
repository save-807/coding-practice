#include "swap.h"

// 函数的定义
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    std::cout << "a= " << a << std::endl;
    std::cout << "b= " << b << std::endl;
}
