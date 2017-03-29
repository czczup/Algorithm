/*把一个任务分成形式和原任务相同,但规模更小的几个部分任务
(通常是两个部分),分别完成,或只需选一部分完成。然后再处理
完成后的这一个或几个部分的结果,实现整个任务的完成 
1 4 9 12
2 5 8 13
1 2 4 5 8 9 12 13
*/
#include <iostream>
using namespace std;
void Merge(int a[],int s,int m,int e,int tmp[])
{//将数组a的局部a[s,m]和a[m+1,e]合并到tmp,并保证tmp有序,然后拷回a[s,m]
 //归并操作时间复杂度:O(e-m+1),即O(n)
	int pb = 0;
	int p1 = s,p2 = m+1;
	while(p1<=m && p2<=e){
		if(a[p1]<a[p2])
			tmp[pb++] = a[p1++];
		else
			tmp[pb++] = a[p2++];
		//把小的记在tmp里 
	}
	while(p1<=m)//拷贝剩下的 
		tmp[pb++] = a[p1++];
	while(p2<=e)//拷贝剩下的
		tmp[pb++] = a[p2++];
	for(int i=0;i<e-s+1;i++)
		a[s+i] = tmp[i]; 
	//复制回去 
 } 
 
void MergeSort(int a[],int s,int e,int tmp[])
{
	if(s<e){
		int m = s + (e-s)/2;
		MergeSort(a,s,m,tmp);//前一半排序 
		MergeSort(a,m+1,e,tmp);//后一半排序 
		Merge(a,s,m,e,tmp);//归并 
	}
} 

int a[10] = {13,27,19,2,8,12,2,8,30,89};
int b[10];
int main()
{
	int size = sizeof(a)/sizeof(int);
	MergeSort(a,0,size-1,b);
	//起始数组,起始位置,终止位置,存放空间 
	for(int i=0;i<size;i++)
		cout << a[i] << ",";
	cout << endl;
	return 0;	 
} 


