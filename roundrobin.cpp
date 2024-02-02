#include<bits/stdc++.h>
using namespace std;



void roundrobin(int processes[],int bt[],int rem_bt[],int tat[],int wt[],int n,int q){
    int t=0;
        for (int i = 0; i < n; i++)
        {
           rem_bt[i]=bt[i];
        }
        bool done=false;
        // int i=0;
        while (true) 
    { 
        bool done = true; 
 
        // Traverse all processes one by one repeatedly 
        for (int i = 0 ; i < n; i++) 
        { 
            // If burst time of a process is greater than 0 
            // then only need to process further 
            if (rem_bt[i] > 0) 
            { 
                done = false; // There is a pending process 
 
                if (rem_bt[i] > q) 
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t += q; 
 
                    // Decrease the burst_time of current process 
                    // by q 
                    rem_bt[i] -= q; 
                } 
 
                // If burst time is smaller than or equal to 
                // q. Last cycle for this process 
                else
                { 
                    // Increase the value of t i.e. shows 
                    // how much time a process has been processed 
                    t = t + rem_bt[i]; 
 
                    // Waiting time is current time minus time 
                    // used by this process 
                    wt[i] = t - bt[i]; 
 
                    // As the process gets fully executed 
                    // make its remaining burst time = 0 
                    rem_bt[i] = 0; 
                } 
            } 
        } 
 
        // If all processes are done 
        if (done == true) 
        break; 
    } 

        for (int i = 0; i < n; i++)
        {
            tat[i]=bt[i]+wt[i]; 
        }
        cout<<"pr"<<" "<<"bt"<<" "<<"wt"<<" "<<"tat"<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<i+1<<" "<<bt[i]<<" "<<wt[i]<<" "<<tat[i]<<endl;
        }
        
        
        
}

int main() {
    int  n=3;
    int q=2;
    int bt[3]={10,5,8};
    int processes[3]={1,2,3};
    int rem_bt[3];
    int tat[3]={0};
    int wt[3]={0};
    roundrobin(processes,bt,rem_bt,tat,wt,n,q);
     cout<<"started"<<endl;


}