#include "cstack.h"
#include "Product.h"
#include <iostream>
using namespace std;
bool Stack::push(Element e)
{
	if (top >= (MAX_STACK_SIZE-1))
	{
		cout << "Stack Overflow" << endl;
		return false;
	}
	else
	{
		top = top + 1;
		elements[top] = e;
		//char s[2000] = "";
		//cout << e.prod << " pushed into stack" << endl;
		//toString(e.prod, s);
		e.prod.toString();
		cout << "->pushed into stack" << endl;
		return true;
	}
}
Element Stack::pop()
{
	if (top < 0)
	{
		cout << "Stack Underflow" << endl;
	}
	else
	{
		//char s[2000] = "";
		//toString(st->elements[st->top].prod, s);
		elements[top].prod.toString();
		Element topel = elements[(top)--];
		cout << "->popped out of the stack" << endl;
		return topel;
	}
}
void Stack::printstack()
{
	//char s[2000] = "";
	cout << "Stack content: " << endl;
	for (int i = top; i >= 0; i--)
	{
		//toString(st->elements[i].prod, s);
		elements[i].prod.toString();
		//cout << "~~~~~~~ " << s << endl;
	}
	cout << endl;
}