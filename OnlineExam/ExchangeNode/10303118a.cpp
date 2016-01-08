/**
*       Exam:   Single Linkedlist For Exchange Chain
*       Date:   2015/11/9
*       Author: isu10303118A
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
    NodeChain() { create();number = 0;}
    ~NodeChain() {erase();}

    NodeChain& AppendNode(const int& x) 
    {
        Node *temp = new Node;
    	temp->data = x;
    	temp->link = NULL;
    	number++;
    	Last->link = temp;
    	Last = temp;	
    	return *this;
    }
	
	NodeChain& ExchgLeftCount(int k) 
	{
	        Node *temp = First;
	        Node* NewLastLink = First;
	        if (k > number) return *this;//index K must in range(small than count of current chain)
	        if (k <= 1)     return *this;// K need be an index or bigger than 1.(index 1 is current chain)
	        for (int i = 0; i < k ;temp = temp->link,i++);//Looking for Node K
	        for (int i = 1; i < k ;NewLastLink = NewLastLink->link,i++);//for Node (K-1)
	        Node* OldFirstLink = this->First->link;//Record current first Node.
	        this->First->link  = temp;//Set current first node to Node K.
	        while (temp->link) temp = temp->link;//Find Lastest Node from Node K.
	        this->Last = NewLastLink;//New last node = K-1
	        temp->link = OldFirstLink;//Lastest Node of Node K, set Next to old first Node.
	        NewLastLink->link = NULL; //Set next of Node (K-1) = NULL(Signed as eof)
	        return *this;
	}

	int GetCount() {return number;}

	void OutputChain() 
	{
		cout << endl << "Current chain: { ";
		for(Node *current = First->link;current;current = current->link)
            cout << current->data << " ";
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
		First->data = 0;
		Last = First;
		First->link = NULL;
	}
};

int main(void)
{
	int inpt_Count(0),k(0);
	NodeChain ChA;

	cout << "Enter an number of items: ";
	cin >> inpt_Count;
	if (!inpt_Count) return 0;
	for (int inpt(0);inpt_Count;inpt_Count--)
	{
		cout << "\nEnter an number: ";
		cin >> inpt;
		ChA.AppendNode(inpt);
	}
	ChA.OutputChain();
    cout << "Input you want to exchange item index = ";
    cin >> k;
    ChA.ExchgLeftCount(k);
    ChA.OutputChain();
    system("PAUSE");
}
