// Burse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "iostream"
#include "list"
#include "windows.h"
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int, int);

class node
{
	int data;
	node *next;
	node *pre;
public:
	node(int x, node *n, node *p)
	{
		data = x;
		next = n;
		pre = p;
	}
	/*void setData(int d)
	{
		data = d;
	}*/

	friend class D_Stack;
};

class D_Stack
{
	//node *Head;
public:
	/*D_Stack()
	{
		Head = NULL;
	}

	D_Stack(node *p)
	{
		Head = p;
	}*/

	node *pop(node *Head)//حذف از انتها
	{
		/*if (Head != NULL)
		{
		node *temp = Head;
		Head = Head->next;
		Head->pre = NULL;
		return temp->data;
		}
		else
		return -1;*/
		if (Head == NULL || Head->next == NULL)
		{
			Head->next = NULL;
			Head = NULL;
			return Head;
		}
		else
		{
			node *n = Head;
			while (n->next->next != NULL)
				n = n->next;
			node *temp = n->next;
			n->next = NULL;
			delete temp;
			return Head;
		}
	}

	node *push(node *Head, int x)//درج ب انتها
	{
		/*node *m = new node(x, NULL, NULL);
		if (Head != NULL)
			while (Head->next != NULL)
			{
				m->next = Head;
				Head->pre = m;
				Head = m;
			}
		else
			Head = m;*/
		/*if (Head->next != NULL)
			Head = pop(Head);*/
		/*if (Head->data != 0)
			Head = pop(Head);*/
		node *m = new node(x, NULL, NULL);
		node *n = Head;
		if (n != NULL)
		{
			while (n->next != NULL)
				n = n->next;
			n->next = m;
			m->pre = n;
		}
		else
			Head = m;
		return Head;
	}

	void Print(node *Head, int X)//چاپ لیست
	{
		node *n = Head;
		int i = 6;
		if (n != NULL)
			while (n != NULL)
			{
				gotoxy(X, i);
				cout << n->data << "  ";
				n = n->next;
				i++;
			}
		else
			cout << "Not found item! ):";
	}

	node *ComputeSpans(node *Head)
	{
		node *H = NULL;// = new node(NULL, NULL);
		node *p, *q;
		int count;
		p = q = Head;
		while (p != NULL)
		{
			count = 1;
			while (q->pre != NULL)
			{
				if (p->data >= q->pre->data)
					count++;
				else
					break;
				q = q->pre;
			}
			H = push(H, count);
			p = p->next;
			q = p;
		}
		while (H->pre != NULL)
			H = H->pre;
		return H;
	}
};

void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hConsole, pos);
	}
}

void Bax(int y)
{
	int x = 25;
	cout << (char)201;
	for (int i = 0; i < x; i++)
		cout << (char)205;
	cout << (char)203;
	for (int i = 0; i < x; i++)
		cout << (char)205;
	cout << (char)187 << endl;
	////////////////////////////////
	for (int i = 0; i < 3; i++)
	{
		cout << (char)186;
		for (int j = 0; j < x; j++)
			cout << " ";
		cout << (char)186;
		for (int j = 0; j < x; j++)
			cout << " ";
		cout << (char)186 << endl;
	}
	////////////////////////////////
	cout << (char)204;
	for (int i = 0; i < x; i++)
		cout << (char)205;
	cout << (char)206;
	for (int i = 0; i < x; i++)
		cout << (char)205;
	cout << (char)185 << endl;
	////////////////////////////////
	for (int i = 0; i < y; i++)
	{
		cout << (char)186;
		for (int j = 0; j < x; j++)
			cout << " ";
		cout << (char)186;
		for (int j = 0; j < x; j++)
			cout << " ";
		cout << (char)186 << endl;
	}
	////////////////////////////////
	cout << (char)200;
	for (int i = 0; i < x; i++)
		cout << (char)205;
	cout << (char)202;
	for (int i = 0; i < x; i++)
		cout << (char)205;
	cout << (char)188;
}

void Method1()
{
	D_Stack D;
	node *P = NULL;
	node *S = NULL;
	int NumOfDays;
	int StockPrice;
	////////////////////////////////////
	cout << "Please enter the number of days the stock price of a particular company is registered: ";
	cin >> NumOfDays;
	for (int i = 0; i < NumOfDays; i++)
	{
		cout << "Please enter the stock price of this company on the " << i + 1 << " day :";
		cin >> StockPrice;
		P = D.push(P, StockPrice);
	}
	////////////////////////////////////
	system("cls");
	SetConsoleTextAttribute(hConsole, 155);
	Bax(NumOfDays + 2);
	SetConsoleTextAttribute(hConsole, 151);
	gotoxy(8, 2);
	cout << "Stock Price";
	gotoxy(29, 2);
	cout << "Stock Exchange Period";
	///////////////////////////////////
	D.Print(P, 13);
	S = D.ComputeSpans(P);
	D.Print(S, 39);
}

void Method2()
{
	D_Stack D;
	node *P = NULL;
	node *S = NULL;
	/*D_Stack P;
	D_Stack S;*/
	int NumOfDays;
	int StockPrice;
	cout << "Please enter the number of days the stock price of a particular company is registered: ";
	cin >> NumOfDays;
	system("cls");
	SetConsoleTextAttribute(hConsole, 155);
	Bax(NumOfDays + 2);
	SetConsoleTextAttribute(hConsole, 151);
	gotoxy(8, 2);
	cout << "Stock Price";
	gotoxy(29, 2);
	cout << "Stock Exchange Period";
	for (int i = 0; i < NumOfDays; i++)
	{
		gotoxy(13, i + 6);
		cin >> StockPrice;
		P = D.push(P, StockPrice);
		S = D.ComputeSpans(P);
		D.Print(S, 39);
	}
}

void _tmain()
{
	/*Method1();
	_getch();
	gotoxy(54, 0);*/
	Method2();
	_getch();
}

/*
پروژه دوم
برای هر عدد در ارایه پی بایستی تعداد اعداد متوالی کمتر مساوی این عدد را 
شمرده و در ارایه اس ذخیره کنیم. برای این منظور پشته ی دی را داریم. 
روی پشته ی دی اعداد به شرطی ذخیره میشوند که فرض کنیم ما میخاهیم
اندیس آی را بررسی کنیم ابتدا تمام تمام اعدادی که بالای پشته
هستند و از مقدار ارایه پی در اندیس آی کوچکترن برداشته میشوند 
و ما به اولین مقدار روی پشته برسیم که مقدار ارایه پی بزگتر باشد 
یعنی این روز رو نباید بشمریم. تفاوت مقدار اندیس آی و مقدار اندیس بالای پشته 
میشه تعداد روزهایی که کمتر یا مساوی مقدار بودند
*/
/*int count;
int *P = new int[5];
int *S = new int[5];
for (int i = 0; i < 5; i++)
cin >> P[i];
for (int i = 0; i < 5; i++)
{
count = 0;
for (int j = 5; j > 0; j--)
{
if (P[i] >= P[j])
count++;
}
S[i] = count;
}
for (int i = 0; i < 5; i++)
cout << S[i] << "  ";*/