/*数字三角形的记忆递归型动规程序*/
#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX];
int n;
int maxSum[MAX][MAX]; 
//求第i行第j列到底边的最大和 
int MaxSum(int i,int j){
	if(maxSum[i][j]!=-1)//不是-1说明已经算出来了 
		return maxSum[i][j];//直接返回 
	if(i==n)//最底边 
		maxSum[i][j] = D[i][j];
	else{
		int x = MaxSum(i+1,j);
		int y = MaxSum(i+1,j+1);
		maxSum[i][j] = max(x,y) + D[i][j];
	}
	return maxSum[i][j];
}//时间复杂度O(n^2) 
int main()
{
	int i,j;
	cin >> n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin >> D[i][j];
			maxSum[i][j] = -1;//表示还未算出来过 
	cout << MaxSum(1,1) <<endl;
}

