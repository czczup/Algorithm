#include <iostream>
/*汉诺塔问题
1.将n-1个盘子移动到B
2.将最后一个盘子移动到C
3.将B上的n-1个盘子移动到C 
*/ 
using namespace std;
void Hanoi(int n,char src,char mid,char dest)
{//将src上的n个盘子，以mid为中转，移动到dest 
    if(n==1){//只需移动一个盘子 
        cout << src << "->" << dest << endl; 
        //直接将盘子从src移动到dest
        return; 
    }
    Hanoi(n-1,src,dest,mid);
    //将n-1个盘子从src移动到mid 
    cout << src << "->" << dest <<endl;
    //再将一个盘子从src移动到dest 
    Hanoi(n-1,mid,src,dest);
    //最后将n-1个盘子从mid移动到dest
    return; 
}
int main()
{
    int n;
    cin >> n;
    Hanoi(n,'A','B','C');
    return 0;
}

