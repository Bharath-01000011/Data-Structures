#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <queue> 
#include <cstring>
using namespace std;

struct process {
    int id;
    int at;
    int bt;
    int st;
    int ct;
    int tat;
    int wt;
    int rt;
};

bool compare1(process p1, process p2) 
{ 
    return p1.at < p2.at;
}

bool compare2(process p1, process p2) 
{  
    return p1.id < p2.id;
}

int main() {

    int n;
    int tq;
    struct process p[100];
    float avg_tat;
    float avg_wt;
    int total_tat = 0;
    int total_wt = 0;
    int total_rt = 0;
    int bt_rem[100];
    int idx;
	cout<<"FILENAME : BHARATH.C   1917108..."<<endl;
    cout << setprecision(2) << fixed;

    cout<<"Enter the number of processes (MAXIMUM:100): ";
    cin>>n;
    cout<<"Enter time quantum: ";
    cin>>tq;

    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].at;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].bt;
        bt_rem[i] = p[i].bt;
        p[i].id = i+1;
        cout<<endl;
    }

    sort(p,p+n,compare1);

    queue<int> q;
    int current_time = 0;
    q.push(0);
    int completed = 0;
    int mark[100];
    memset(mark,0,sizeof(mark));
    mark[0] = 1;

    while(completed != n) {
        idx = q.front();
        q.pop();

        if(bt_rem[idx] == p[idx].bt) {
            p[idx].st = max(current_time,p[idx].at);
            current_time = p[idx].st;
        }

        if(bt_rem[idx]-tq > 0) {
            bt_rem[idx] -= tq;
            current_time += tq;
        }
        else {
            current_time += bt_rem[idx];
            bt_rem[idx] = 0;
            completed++;

            p[idx].ct = current_time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].rt = p[idx].st - p[idx].at;

            total_tat += p[idx].tat;
            total_wt += p[idx].wt;
        }

        for(int i = 1; i < n; i++) {
            if(bt_rem[i] > 0 && p[i].at <= current_time && mark[i] == 0) {
                q.push(i);
                mark[i] = 1;
            }
        }
        if(bt_rem[idx] > 0) {
            q.push(idx);
        }

        if(q.empty()) {
            for(int i = 1; i < n; i++) {
                if(bt_rem[i] > 0) {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }


    }

    avg_tat = (float) total_tat / n;
    avg_wt = (float) total_wt / n;

    sort(p,p+n,compare2);

    cout<<endl;
    cout<<"AT - Arrival Time \nBT - Burst Time \nST - Start Time \nCT - Completing time \nTAT - TurnAround Time \nWT - Waiting Time \nRT - Response Time\n"<<endl;
	cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_tat<<endl;
    cout<<"Average Waiting Time = "<<avg_wt<<endl;
    


}
