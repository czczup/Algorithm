/*
i个苹果,k个盘子 
k>i时,f(i,k) = f(i,i) 
k<=i时,f(i,k) = f(i,k-1) + f(i-k,k); 
*/
#include <iostream>
using namespace std;
int f(int m,int n){
	if(n>m)
		return f(m,m);
	if(m==0)//有盘子没苹果 
		return 1;
	if(n==0)//有苹果没盘子 
		return 0;
	return f(m,n-1) + f(m-n,n);
}
int main()
{
	int t,m,n;
	cin >> t;
	while(t--){
		cin >> m >> n;
		cout << f(m,n) << endl;
	}
	return 0;
}

