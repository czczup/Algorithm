#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
double exp(){
	//读入一个逆波兰表达式,并计算其值
	char s[20];
	scanf("%s",s);//每次递归读入输入的一部分,以空格划分 
	switch(s[0]){
		case '+': return exp() + exp();
		case '-': return exp() - exp();
		case '*': return exp() * exp();
		case '/': return exp() / exp();
		default:  return atof(s);
		//把一个字符串形式浮点数转换成double 
		break;
	} 
} 
int main()
{
	printf("%lf",exp());
	return 0;
}
