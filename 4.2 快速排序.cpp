﻿#include <iostream>
using namespace std;
void swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
} 
void QuickSort(int a[],int s,int e)
{//s开始位置,e结束位置 
	if(s>=e)
		return;
	int k = a[s];
	int i = s,j = e;//两个指针 
	while(i!=j){
		while(j>i && a[j]>=k)
			--j;
		swap(a[i],a[j]);
		while(i<j && a[i]<=k)
			++i;
		swap(a[i],a[j]); 
	}
	QuickSort(a,s,i-1);
	QuickSort(a,i+1,e); 
}
