#include <cmath>
#include <iostream>
using namespace std;
int N;
int queenPos[100];
void NQueen(int k); 
int main()
{
    cin >> N;
    NQueen(0);
    return 0;
}

void NQueen(int k)
{//在0~k-1行的皇后已经摆好的情况下,摆放k行及其后的皇后 
    int i;
    if(k==N){//N个皇后已经摆好 
        for(i=0;i<N;i++)
            cout << queenPos[i] + 1 << " ";
        cout << endl;
        return; 
    }
    for(i=0;i<N;i++){//分别尝试将第k个皇后放在0~N-1上 
        int j;
        for(j=0;j<k;j++){//和已经摆好的k个皇后的位置比较,看是否冲突 
            if(queenPos[j]==i||abs(queenPos[j]-i)==abs(k-j))
            //k行号,j行号,queenPos[j]列号,i列号 
			   	break;//冲突，测试下一个位置 
        }//任何两个皇后不能同行同列同对角线
        if(j==k){//当前选的位置i不冲突
			queenPos[k] = i;
			NQueen(k+1); 
		} 
    }
}


