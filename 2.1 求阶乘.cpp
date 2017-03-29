#include <stdio.h>
int Factorial(int n)
{
    if(n==0)
        return 1;
    else
        return n * Factorial(n-1);
} 
/*
递归的作用
1.代替多重循环 
2.解决本来就是用递归形式定义的问题
3.将问题分解为规模更小的子问题进行求解 
