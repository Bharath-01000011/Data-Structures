#include <iostream>
#include <algorithm> 
#include <iomanip> 
#include <queue>
using namespace std;

struct process {
    int id;
    int at;
    int bt;
    int st;
    int ct;
    int tat;
    int wt;
};

bool compAT(process p1, process p2) 
{ 
    return p1.at < p2.at;
}

bool compID(process p1, process p2) 
{  
    return p1.id < p2.id;
}

int main() {

    int n;
    struct process p[100];
    float avg_tat;
    float avg_wt;
    int total_tat = 0;
    int total_wt = 0;
	cout<<"FILENAME : BHARATH.C   1917108..."<<endl;
    cout << setprecision(2) << fixed;
	queue<int> q;
    cout<<"Enter the number of processes:(MAXIMUM : 100) ";
    cin>>n;
	
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].at;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].bt;
        p[i].id = i+1;
        cout<<endl;
    }

    sort(p,p+n,compAT);
	
    for(int i = 0; i < n; i++) {
        p[i].st = (i == 0)?p[i].at:max(p[i-1].ct,p[i].at);
        p[i].ct = p[i].st + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        total_tat += p[i].tat;
        total_wt += p[i].wt;
        if(i==0)
        {
    		q.push(i);    	
		}
		else 
		{
		if(p[i-1].ct<=p[i].ct)
		{
			q.pop();
			q.push(i);
		}
		else
		{
			q.push(i);
		}
			
		}
		
    }

    avg_tat = (float) total_tat / n;
    avg_wt = (float) total_wt / n;
    

    sort(p,p+n,compID);

    cout<<endl;
    cout<<"AT - Arrival Time \nBT - Burst Time \nST - Start Time \nCT - Completing time \nTAT - TurnAround Time \nWT - Waiting Time \n"<<endl;
    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_tat<<endl;
    cout<<"Average Waiting Time = "<<avg_wt<<endl;
    


}
