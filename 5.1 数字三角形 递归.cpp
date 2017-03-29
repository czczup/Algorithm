#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX];
int n;
//求第i行第j列到底边的最大和 
int MaxSum(int i,int j){
	if(i==n)
		return D[i][j];
	int x = MaxSum(i+1,j);
	int y = MaxSum(i+1,j+1);
	return max(x,y)+D[i][j];
} 
int main()
{
	int i,j;
	cin >> n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin >> D[i][j];
	cout << MaxSum(1,1) <<endl;
}
/*超时,原因:重复计算
深度遍历每条路径,存在大量重复计算
时间复杂度为2^n*/
