#include <iostream> 
using namespace std; 
struct stack 
{ 
	int data; 
	struct stack *next; 
}; 
void initStack(struct stack **s) 
{ 
	*s = NULL; 
} 
int isEmpty(struct stack *s) 
{ 
	if (s == NULL) 
		return 1; 
	return 0; 
} 
void push(struct stack **s, int x) 
{ 	
	stack *p = new stack;
	if (p == NULL) 
	{ 
		fprintf(stderr, "Memory allocation failed.\n"); 
		return; 
	} 
	p->data = x; 
	p->next = *s; 
	*s = p; 
} 
int pop(struct stack **s) 
{ 
	int x; 
	struct stack *temp; 
	x = (*s)->data; 
	temp = *s; 
	(*s) = (*s)->next; 
	return x; 
} 
int top(struct stack *s) 
{ 
	return (s->data); 
} 
void sortedInsert(struct stack **s, int x) 
{ 
	if (isEmpty(*s) or x > top(*s)) 
	{ 
		push(s, x); 
		return; 
	} 
	int temp = pop(s); 
	sortedInsert(s, x); 
	push(s, temp); 
} 
void sortStack(struct stack **s) 
{ 
	if (!isEmpty(*s)) 
	{ 
		int x = pop(s); 
		sortStack(s); 
		sortedInsert(s, x); 
	} 
} 
void printStack(struct stack *s) 
{ 
	while (s) 
	{ 
		cout << s->data << "--> "; 
		s = s->next; 
	} 
	cout << "\n"; 
} 
int main(void) 
{ 
	struct stack *top; 
	int no;
	int i;
	int value;
	initStack(&top); 
	cout<<"FILENAME ; BHARATH.C    (1917108)"<<endl;
	cout<<"Enter the number of values to be inserted :"<<endl;
	cin>>no;
	cout<<"Enter "<<no<<" values of the stack to be sorted :"<<endl;
	for(i=0;i<no;i++)
	{
	cin>>value;
	push(&top,value);
	}	
	cout << "Stack elements before sorting:\n"; 
	printStack(top); 
	sortStack(&top); 
	cout << "\n"; 
	cout << "Stack elements after sorting:\n"; 
	printStack(top); 
	return 0; 
} 

