﻿/*枚举：基于逐个尝试答案的一种问题求解策略*/ 
#include <stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    for(int a=2;a<=N;a++)
        for(int b=2;b<a;b++)
            for(int c=b;c<a;c++)
                for(int d=c;d<a;d++)
                    if(a*a*a==b*b*b+c*c*c+d*d*d)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
    return 0;
}

