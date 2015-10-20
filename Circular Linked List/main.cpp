/**
*			Data Structures Homework1
*			Circular Linked List
*			Works on OSX(g++) , Windows(Dev C)
*	Author: aaaddress1@gmail.com(isu10303118a)
*	Date:	2015/10/20
**/
#include <iostream>
using namespace std;

class Node 
{
public:
	int data;
	Node *link;
};

class NodeChain
{
public:
	NodeChain() { create();number = 0;};
	~NodeChain() {erase();}

	NodeChain& AppendNode(const int& x) 
	{
	    Node *temp = new Node;
		temp->data = x;
		temp->link = First;
		number ++;
		Last->link = temp;
		Last = temp;	
		return *this;
	}

	NodeChain& Insertion(const int& x, int k) 
	{
		Node *temp = First;
		Node *InsertedNode = new Node;
		number++;
		for(int i(k);i--;) temp = temp -> link;
		InsertedNode -> data = x;
		InsertedNode -> link = temp -> link;
		temp -> link = InsertedNode;
		return *this;
	}

	NodeChain& Deletion(int k) 
	{
		Node *temp = First;
		for (int i = 1; i < k ; temp = temp->link,i++);
		if( (temp->link)->link == First)
			temp -> link = First;
		else
			temp -> link = (temp -> link) -> link;
		number--;
		//delete temp; //It invoke unlimited loop in DevC , But g++ works.
		return *this;
	}

	int GetCount() {return number;}

	void OutputChain() 
	{
		Node *current = First->link;
		cout << endl << "Current chain: { ";
		while(current != First) 
		{
			cout << current -> data << " ";
			current = current -> link;
		}
		cout << "}, Count = " << number << endl;
	}

private:
	Node *First;
	Node *Last;
	int number;

	void erase() 
	{
		for(Node *Next;number --;Next = First->link,delete First,First = Next); 
	}

	void create()
	{
		First = new Node;
		First -> data = 0;
		Last = First;
		First -> link = Last;
	}
};

int main(void)
{
	int inpt_Count(0);
	NodeChain ChA;

	cout << "Enter an number of items: ";
	cin >> inpt_Count;
	if (!inpt_Count) exit(0);
	for (int inpt(0);inpt_Count;inpt_Count--)
	{
		cout << "\nEnter an number: ";
		cin >> inpt;
		ChA.AppendNode(inpt);
	}
	
	int i(0),j(0);
	for (char choise('c'); choise != 'q';)
	{
		ChA.OutputChain();
		cout << "What operation want?\n";
		cout << "Insertion: Press 'i'\n";
		cout << "Deletion:  Press 'd'\n";
		cout << "Exit:      Press 'q'\n";
		cout << "Press: ";
		cin >> choise;
		switch (choise)
		{
			case 'i':
				cout << "Insert an item after: ";
				cin >> i;
				if(i > ChA.GetCount()) cout << "Index out of range!\n";
				else 
				{
					cout << "data = ";
					cin >> j;
					ChA.Insertion(j, i);
				}
				break;
			case 'd':
				cout << "Delete which item ";
				cin >> i;
				if(i > ChA.GetCount()) cout << "Index out of range!\n";			
				else ChA.Deletion(i);
				break;
			case 'q':
				break;
			default:
				cout << "illegal operation!\n";
				break;
		}
	}

	cout << "Overloading Assignment B = A";
	NodeChain ChB = ChA;
    ChB.OutputChain();

    cout << "Copy Constructor";
	NodeChain ChC(ChA);
	ChC.OutputChain();
    system("PAUSE");//Doesn't works on OSX Commandline.
	return 0;
}
