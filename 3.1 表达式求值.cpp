//整数运算 
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int factor_value();
int term_value();
int expression_value();
int main()
{
	cout << expression_value() <<endl;
	return 0;
}
int expression_value()//求一个表达式的值 
{
	int result = term_value();//求第一项的值 
	bool more = true;//先假设有多项 
	while(more){
		char op = cin.peek();//看剩下的字符,不取走 
		if(op=='+'||op=='-'){
			cin.get();//从输入中取走一个字符 
			int value = term_value();
			if(op=='+')
				result += value;
			else
				result -= value;
		}else
			more = false; 
	}
	return result;
}
int term_value()//求一个项的值 
{
	int result = factor_value();//求第一个因子的值
	while(1){
		char op = cin.peek();//看剩下的字符,不取走 
		if(op=='*'||op=='/'){
			cin.get();//从输入中取走一个字符 
			int value = factor_value();
			if(op=='*')
				result *= value;
			else
				result /= value;
		}else
			break; 
	}
	return result;
}
int factor_value()
{
	int result = 0;
	char c = cin.peek();
	//因子可能是括号表达式或数 
	if(c=='('){
		cin.get();//拿走左括号 
		result = expression_value();
		cin.get();//拿走右括号 
	}else{
		while(isdigit(c)){
			result = 10 * result + c -'0';
			cin.get();
			c = cin.peek();
		} 
	} 
	return result;
}
