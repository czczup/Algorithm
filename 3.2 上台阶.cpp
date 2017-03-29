/*爬楼梯,可以一次走1级,也可以一次走2级,输出走法数 
n级台阶的走法 =
先走一级后,n-1级台阶的走法 + 
先走两级后,n-2级台阶的走法
f(n) = f(n-1) + f(n-2) 
*/
#include <stdio.h>
int f(int n){
	//边界条件 
	if(n==1)
		return 1;
	else if(n==2)
		return 2;
	return f(n-1) + f(n-2);
}
int main()
{
	int N;
	scanf("%d",&N);
	printf("%d",f(N)); 
	return 0; 
}

