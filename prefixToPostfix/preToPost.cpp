/**
*	preFix to postFix
*	working on MacOS g++ and Windows Dev C++
*	Author:	isu10303118a
*	Date:	2016/1/9
**/
#include <deque>
#include <iostream>
#define isOperator(i) (i == '+' || i == '-' || i == '*' || i == '/' || i == '$')
using namespace std;
deque<string> stack;

string charToStr(char i) {
	string tmp = "";
	tmp += i;
	return tmp;
}

int main(void)
{
	char preFix[1024];
	puts("Input your prefix data:");
	scanf("%1023s",preFix);

	for(int i = strlen(preFix) ; i-- ;) 
	{	
		if (isOperator(preFix[i])) 
		{
			string total = stack[0];
			total.append(stack[1]);
			total.append( charToStr( preFix[i] ) );
			stack.pop_front();
			stack.pop_front();
			stack.push_front( total );
		}
		else 
			stack.push_front( charToStr( preFix[i] ) );
	}
	printf("postfix:%s\n" ,stack[0].c_str());
}
