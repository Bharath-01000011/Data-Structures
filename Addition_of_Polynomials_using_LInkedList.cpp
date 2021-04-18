#include<bits/stdc++.h> 
using namespace std; 
struct Node 
{ 
	int coeff; 
	int pow; 
	struct Node *next; 
}; 
void create_node(int x, int y, struct Node **temp) 
{ 
	struct Node *r, *z; 
	z = *temp; 
	if(z == NULL) 
	{ 
		r =(struct Node*)malloc(sizeof(struct Node)); 
		r->coeff = x; 
		r->pow = y; 
		*temp = r; 
		r->next = (struct Node*)malloc(sizeof(struct Node)); 
		r = r->next; 
		r->next = NULL; 
	} 
	else
	{ 
		r->coeff = x; 
		r->pow = y; 
		r->next = (struct Node*)malloc(sizeof(struct Node)); 
		r = r->next; 
		r->next = NULL; 
	} 
}
void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly) 
{ 
while(poly1->next && poly2->next) 
	{ 
		if(poly1->pow > poly2->pow) 
		{ 
			poly->pow = poly1->pow; 
			poly->coeff = poly1->coeff; 
			poly1 = poly1->next; 
		} 
		else if(poly1->pow < poly2->pow) 
		{ 
			poly->pow = poly2->pow; 
			poly->coeff = poly2->coeff; 
			poly2 = poly2->next; 
		} 
		else
		{ 
			poly->pow = poly1->pow; 
			poly->coeff = poly1->coeff+poly2->coeff; 
			poly1 = poly1->next; 
			poly2 = poly2->next; 
		} 
		poly->next = (struct Node *)malloc(sizeof(struct Node)); 
		poly = poly->next; 
		poly->next = NULL; 
	} 
while(poly1->next || poly2->next) 
	{ 
		if(poly1->next) 
		{ 
			poly->pow = poly1->pow; 
			poly->coeff = poly1->coeff; 
			poly1 = poly1->next; 
		} 
		if(poly2->next) 
		{ 
			poly->pow = poly2->pow; 
			poly->coeff = poly2->coeff; 
			poly2 = poly2->next; 
		} 
		poly->next = (struct Node *)malloc(sizeof(struct Node)); 
		poly = poly->next; 
		poly->next = NULL; 
	} 
} 
void show(struct Node *node) 
{ 
while(node->next != NULL) 
	{ 
	cout<<node->coeff<<"^"<<node->pow;
	node = node->next; 
	if(node->next != NULL) 
		printf(" + "); 
	} 
} 
int main() 
{ 
	int coef,power;
	char choice;
	struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL; 
	cout<<"FILENAME : BHARATH.C    1917108..."<<endl;
	cout<<"First Polynomial:"<<endl;
	do
	{
	cout<<"Enter the coefficient :"<<endl;
	cin>>coef;
	cout<<"Enter the power :"<<endl;
	cin>>power;
	cout<<"Do you want to add another term (y/n)?"<<endl;
	cin>>choice;
	create_node(coef,power,&poly1); 
    }while(choice!='n');
	cout<<"Second Polynomial :"<<endl;
	do
	{
	cout<<"Enter the coefficient :"<<endl;
	cin>>coef;
	cout<<"Enter the power :"<<endl;
	cin>>power;
	cout<<"Do you want to add another term (y/n)?"<<endl;
	cin>>choice;
	create_node(coef,power,&poly2); 
    }while(choice!='n');
	printf("1st Number: "); 
	show(poly1); 
	printf("\n2nd Number: "); 
	show(poly2); 
	poly = (struct Node *)malloc(sizeof(struct Node)); 
	polyadd(poly1, poly2, poly); 
	printf("\nAdded polynomial: "); 
	show(poly); 
return 0; 
} 

