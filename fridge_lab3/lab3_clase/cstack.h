#pragma once
#ifndef CSTACK_H
#define CSTACK_H

#include "Product.h"
using namespace std;
typedef enum {
	ADD, REMOVE
}OperationType;

typedef struct {
	OperationType type;
	Product prod;
}Operation;

typedef Operation Element;

const int MAX_STACK_SIZE = 100;


class Stack
{
public:
	int top;
	Element elements[MAX_STACK_SIZE];
	Stack() :top{ -1 } {};
	//Stack()=default;
	bool push(Element e);
	Element pop();
	void printstack();
};



#endif // CSTACK_H
