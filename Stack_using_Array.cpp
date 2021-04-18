#include <iostream>
using namespace std;
class Stack
{
    private:
    int top=-1;
    int arr[5]={0,0,0,0,0};
    public:
    bool isEmpty()
        {
            if(top==-1)
                return true;
            else
                return false; 
        }
    bool isFull()
        {
            if(top==4)
                return true;
            else
                return false;
        }
    void push(int value)
    {
        if(isFull())
        cout<<"Stack is Full...Stack overflow...\n";
        else
        {
            top++;
            arr[top]=value;
        }
    }
    int pop()
    {
        if(isEmpty())
        cout<<"Stack is Empty...Stack underflow..\n";
        else
        {
            int pop=arr[top];
            arr[top]=0;
            top--;
            return pop;
        }
    }
    int count()
    {
        int t;
        t=top+1;
        return t;
    }
    int peek(int pos)
    {
        if(isEmpty())
        cout<<"Stack is Empty...\n";
        else
        {
            return arr[pos];
        }
    }
    void change(int pos,int value)
    {
        arr[pos]=value;
        cout<<"Value Changed to "<<value<<"\n";
    }
    void display()
    {
        int i;
        cout<<"Values in the Stack are :\n";
        for(i=4;i>=0;i--)
        {
            cout<<arr[i]<<"\n";
        }
    }
};
int main()
{
    Stack s1;
    int option,value,pos;
    cout<<"FILENAME : BHARATH.C  1917108..."<<endl;
    do{
        cout<<"\n1.Push 2.Pop 3.IsEmpty 4.IsFull 5.Count 6.Peek 7.Change 8.Display 9.Exit";
        cout<<"\nEnter an option to be performed:";
        cin>>option;
        switch(option)
        {
            case 1:
            if(s1.isFull())
            {
                cout<<"\nStack is Full..Values cannot be pushed";
            }
            else
            {
                cout<<"\nEnter the value to push:";
                cin>>value;
                s1.push(value);
            }
                break;
            case 2:
            if(s1.isEmpty())
            {
                cout<<"\nStack is Empty...Cannot pop a value...";
            }
            else
            {
                cout<<"\nPop Function called...\nPoped value:"<<s1.pop();
            }
                break;
            case 3:
                if(s1.isEmpty())
                {
                cout<<"\nStack is Empty...";
                }
                else
                {
                cout<<"\nStack is Not Empty...";
                }
                break;
            case 4:
                if(s1.isFull())
                {
                    cout<<"\nStack is Full...";
                }
                else
                {
                    cout<<"\nStack is Not Full";
                }
                break;
            case 5:
                cout<<"\nTotal values in the Stack :"<<s1.count();
                break;
            case 6:
                cout<<"\nEnter the position of the value:";
                cin>>pos;
                cout<<"\nThe Value is "<<s1.peek(pos);
                break;
            case 7:
                cout<<"\nEnter the position:";
                cin>>pos;
                cout<<"\nEnter the new value:";
                cin>>value;
                s1.change(pos,value);
                break;
            case 8:
                s1.display();
                break;
            case 9:
                break;
            default:
                cout<<"\nEnter a proper option...";        
        }
    }while(option!=9);
    return 0;
}

