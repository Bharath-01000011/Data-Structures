	#include <iostream>
using namespace std;
class queue
{ private:
	int front;
	int rear;
	int arr[7];
  public:
  	queue()
  	{
  		front =-1;
  		rear = -1;
  		for(int i=0;i<7;i++)
  		{
  			arr[i]=0;
		  }
  	
	  }
	bool isEmpty()
	{
		if(front==-1 && rear==-1)
			return true;
		else
			return false;
		}
	bool isFull()
	{
		if(rear==6)
			return true;
		else
			return false;	
			}		
	void enqueue(int value)
	{
		if(isFull())
		{
			cout<<"Queue is Full..."<<endl;
		}
		else if(isEmpty())
		{
			rear=0;
			front=0;
			arr[0]=value;
		}
		else
		{
			rear++;
			arr[rear]=value;
		}
	}
	int dequeue()
	{
		int x;
		if(isEmpty())
		{
			cout<<"Queue is Empty..."<<endl;
		}
		else if(front == rear)
		{
			x= arr[front];
			arr[front] = 0;
			front = -1;
			rear = -1;
			
			
		}
		else
		{
			x = arr[front];
			arr[front] = 0;
			front++;
		}
		return x;
		
	}
	int count()
	{
		return (rear-front+1);
	}
	void display()
	{
		cout<<"Values in the queue are:";
		for (int i=0;i<7;i++)
		{
			cout<<arr[i]<<"  ";
		}
	}
	
};
int main()
{
	queue s1;
	int value,option,dq;
	cout<<"FILENAME : BHARATH.C  1917108..."<<endl;
	do
	{
		cout<<"Enter the choice:"<<endl;
		cout<<"1.Enqueue"<<endl;
		cout<<"2.Dequeue"<<endl;
		cout<<"3.isEmpty"<<endl;
		cout<<"4.isFull"<<endl;
		cout<<"5.Count"<<endl;
		cout<<"6.Display"<<endl;
		cout<<"7.Exit"<<endl;
		cin>>option;
		switch(option)
		{
			case 1:
				cout<<"ENQUEUE OPERATION..."<<endl;
				cout<<"Enter a value to add in the queue:"<<endl;
				cin>>value;
				s1.enqueue(value);
				cout<<value<<" added to the queue..."<<endl;
				break;
			case 2:
				cout<<"DEQUEUE OPERATION..."<<endl;
				dq = s1.dequeue();
				cout<<dq<<" is removed from the queue..."<<endl;
				break;
			case 3:
				if(s1.isEmpty())
				cout<<"Queue is empty..."<<endl;
				else
				cout<<"Queue is not empty..."<<endl;
				break;
			case 4:
				if(s1.isFull())
				cout<<"Queue is Full..."<<endl;
				else
				cout<<"Queue is not full..."<<endl;
				break;
			case 5:	
				cout<<"No. of items in the queue:"<<s1.count()<<endl;
				break;
			case 6:
				s1.display();
				break;
			case 7:
				break;
			default:
				cout<<"Enter a valid option.."<<endl;
				
					
				
		}
	}while(option!=7);
	
	return 0;
}
