/**
*	Binary Tree: prefix, infix, postfix
*	working on MacOS g++ and Windows Dev C++
*	Author:	aaaddress1@gmail.com
*	Date:	2016/1/15
**/
#include <deque>
#include <iostream>
#define	prefixTag	200
#define postfixTag	300
using namespace std;

int levelOperator(char i) {
	if (i == '$') return 3;
	if (i == '*' || i == '/' || i == '%') return 2;
	if (i == '+' || i == '-') return 1;
	if (i == ')' || i == '(') return -1;
	else return 0;//normal number
}
string convertToInfix(char *input,int from) 
{
	deque<string> Stack;
/************************ 		Prefix 		************************/
	if (from == prefixTag)
	{
		for (int i = strlen(input); i-- ;) 
		{
			char currInput	= input[i] ;
			int currLevel	= levelOperator( currInput );

			if ( !currLevel ) {
				Stack.push_front( "" );
				Stack[0] = currInput;
			}
			else
			{
				string total = "(";
				total += Stack[0].c_str();
				total += currInput;
				total += Stack[1].c_str();
				total += ")";
				Stack.pop_front();
				Stack.pop_front();
				Stack.push_front( total );
			}
		}
	}
/************************ 		Postfix 		************************/	
	else if (from == postfixTag)
	{
		for (int i = 0; i < strlen(input); i++) 
		{
			char currInput	= input[i] ;
			int currLevel	= levelOperator( currInput );

			if ( !currLevel ) {
				Stack.push_front( "" );
				Stack[0] = currInput;
			}
			else
			{
				string total = "(";
				total += Stack[1].c_str();
				total += currInput;
				total += Stack[0].c_str();
				total += ")";
				Stack.pop_front();
				Stack.pop_front();
				Stack.push_front( total );
			}
		}
	}
	return Stack[0];
}

string convertInfix(char *input,int to) 
{
	string returnStr = "";
	deque<char> opStack;
	deque<char> result;
	/************************ 		Prefix 		************************/
	if (to == prefixTag) 
	{
		for (int i = strlen(input); i-- ;) 
		{
			char currInput	= input[i] ;
			int currLevel	= levelOperator( currInput );
			if ( !currLevel ) result.push_front( currInput );
			else 
			{
				if ( currInput == '(' ) {
					while ( opStack[0] != ')' ) {
						result.push_front( opStack[0] );
						opStack.pop_front();
					}
					opStack.pop_front();
				}
				else 
				{
					if ( currInput != ')' )
					{
						while ( opStack.size() && (levelOperator( opStack[0] ) > currLevel) ) {
							result.push_front( opStack[0] );
							opStack.pop_front();
						}
					}
					opStack.push_front( currInput );
				}
			}
		}
		for (int i = 0; i < opStack.size() ; result.push_front( opStack[i++] )) ;
	}
	/************************ 		Postfix 		************************/	
	else if ( to == postfixTag ) 
	{
		for (int i = 0; i < strlen(input); i++) 
		{
			char currInput	= input[i] ;
			int currLevel	= levelOperator( currInput );
			if ( !currLevel ) result.push_back( currInput );
			else 
			{
				if ( currInput == ')' ) {
					while ( opStack.back() != '(' ) {
						result.push_back( opStack.back() );
						opStack.pop_back();
					}
					opStack.pop_back();
				}
				else
				{
					if ( currInput != '(' )
					{
						while ( opStack.size() && (levelOperator( opStack.back() ) >= currLevel) ) {
							result.push_back( opStack.back() );
							opStack.pop_back();
						}
					}
					opStack.push_back( currInput );
				} 
			}
		}
		while (opStack.size()) { result.push_back( opStack.back() ); opStack.pop_back(); }
	}
	for (int i = 0; i < result.size() ; returnStr += result[i++]) ; 
	return returnStr;
}


int main(void)
{
	char userInput[1024] = "";
	char inOrder[1024]	 = {0};
	char choise = '\x00';

	puts( "Choise your input order type:\n[1] preFix\n[2] inFix\n[3] postFix\n" );
	scanf( "%c" , &choise );
	puts( "Input your data: " );
	scanf( "%1023s", userInput );	
	
	if ( choise == '1' ) strcpy( inOrder, convertToInfix(userInput,prefixTag).c_str() );
	if ( choise == '2' ) strcpy( inOrder, userInput );
	if ( choise == '3' ) strcpy( inOrder, convertToInfix(userInput,postfixTag).c_str() );
	printf("inOrder:\t%s\n" , inOrder);
	printf("preOder:\t%s\n" , convertInfix(inOrder, prefixTag).c_str());
	printf("postOrder:\t%s\n" , convertInfix(inOrder,postfixTag).c_str());
	return 0;
}
