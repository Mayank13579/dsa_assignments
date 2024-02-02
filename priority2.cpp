#include<bits/stdc++.h>
using namespace std;

# define n 5
int arr[5]={1,2,3,4,5};
int bt[5]={3,5,1,7,4};
int priority[5]={3,4,1,7,8};
int wt[5],tat[5];
bool compare(int a ,int b){
    if(arr[a]==arr[b]){
        return priority[a]<priority[b];
    }
    else{
        return arr[a]<arr[b];
    }
}

void waiting(){
    int service[5];
    wt[0]=0;
   service[0]=arr[0];
   for (int i = 1; i < n; i++)
   {
    service[i]=service[i-1]+bt[i-1];
    wt[i]=service[i]-arr[i];
    wt[i]=max(0,wt[i]);

   }
}
void turnaround(){
    for (int i = 0; i < n; i++)
    {
        tat[i]=bt[i]+wt[i];
    }

}
int main() {
    int order[n];
   for (int i = 0; i < n; i++)
   {
        order[i]=i;

   }
sort(order,order+n,compare);
   waiting();
   turnaround();
   for (int i = 0; i < n; i++)
   {
        cout<<"process\twaiting\tturnaround"<<endl;
        cout<<order[i]+1<< "    " <<wt[i] <<"    " <<tat[i]<<endl;
   }
   
}