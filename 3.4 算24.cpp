/*思路：
总共4个数,任意从中取两2个,分别进行加减乘除
算得1个数,加上之前剩下的2个数,共3个数
对3个数算24,直到剩1个数为止,用这个数和24比较 
*/
#include <iostream>
#include <cmath>
using namespace std;
double a[5];
#define EPS 1e-6
bool isZero(double x){
	return fabs(x)<=EPS;
}//比较浮点数的大小 
bool count24(double a[],int n)
{
	if(n==1){//递归边界条件 
		if(isZero(a[0]-24))
			return true;
		else
			return false;
	}
	double b[5];//临时存放 
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){//枚举两个数的组合 
			int m = 0;//还剩下m个数,m = n - 2 
			for(int k=0;k<n;k++)
				if(k!=i&&k!=j)//筛掉已经选出的2个数 
					b[m++] = a[k];//把其余数放入b 
			b[m] = a[i] + a[j];//加法 
			if(count24(b,m+1))//m + 1 = n - 1 
				return true;
			b[m] = a[i] - a[j];//减法 
			if(count24(b,m+1))
				return true;		
			b[m] = a[j] - a[i];//减法
			if(count24(b,m+1))
				return true;
			b[m] = a[i] * a[j];//乘法 
			if(count24(b,m+1))
				return true;
			if(!isZero(a[j])){//除法 
				b[m] = a[i] / a[j];
				if(count24(b,m+1))
					return true;
			}
			if(!isZero(a[i])){//除法 
				b[m] = a[j] / a[i];
				if(count24(b,m+1))
					return true;
			}
		}
	return false;
	}
}
int main()
{
	for(int i=0;i<4;i++)
		cin >> a[i];
	if(count24(a,4))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
