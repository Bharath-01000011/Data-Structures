#include<iostream>
using namespace std;
class node
{
	public:
	int data=0;
	node *next=NULL;
	
};
node *front = NULL;
node *rear = NULL;
bool isEmpty()
{
	if(front==NULL && rear==NULL)
		return true;
	else
		 return false;
}
void enqueue(int value)
{
	node *ptr = new node;
	ptr->data = value;
	ptr->next = NULL;
	if(front==NULL)
	{
		front = ptr;
		rear = ptr;
	}
	else
	{
		rear->next = ptr;
		rear = ptr;
	}
}
int dequeue()
{
	int value;
	if(isEmpty())
	{
		cout<<"Queue is Empty...."<<endl;
		return 0;
	}
	else if(front == rear)
	{
		node *ptr = front;
		value = ptr->data;
		front = NULL;
		rear = NULL;
	}
	else
	{
		node *ptr = front;
		value = ptr->data;
		front = ptr->next;
		
	}
	return value;
}
int showfront()
{
	int value;
	if(isEmpty())
	{
		cout<<"Queue is Empty..."<<endl;
		return 0;
	}
	else
	{
		node *ptr = front;
		value = ptr->data;
		return value;
	}
}
void display()
{
	node *ptr = front;
	if(isEmpty())
	{
		cout<<"Queue is Empty.."<<endl;
	}
	else
	{
		while(ptr!=NULL)
		{
			cout<<" "<<ptr->data;
			ptr = ptr->next;
		}
	}
}
int main()
{
	node s1;
	int value,option;
	cout<<"FILENAME ; BHARATH.C   1917108..."<<endl;
	do
	{
	  cout<<endl;
	  cout<<"Enter the option:"<<endl;
	  cout<<"1.Enqueue..."<<endl;
	  cout<<"2.Dequeue..."<<endl;
	  cout<<"3.Show the front element..."<<endl;
	  cout<<"4.Display all the values..."<<endl;
	  cout<<"5.Exit..."<<endl;
	  cin>>option;
	  switch(option)
	  {
	  	case 1:
	  		cout<<"Enqueue function called..."<<endl;
	  		cout<<"Enter the value:"<<endl;
	  		cin>>value;
	  		enqueue(value);
	  		break;
	  	case 2:
		  	cout<<"Dequeue function called..."<<endl;
		  	cout<<dequeue()<<" is removed from the queue..."<<endl;
		  	break;
		case 3:
			cout<<"Front function is called..."<<endl;
			cout<<showfront()<<" is the front element..."<<endl;
			break;
		case 4:
			cout<<"Display function is called..."<<endl;
			display();
			break;
		case 5:
			break;
		default:
			cout<<"Enter a valid option..."<<endl;	  	
		  		
	
		  }	
	}while(option!=5);
	return 0;
}

