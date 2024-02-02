#include<bits/stdc++.h>
using namespace std;

void firstfit(int process[],int n,int blocksize[],int m,int aloc[]){
    for(int i=0;i<4;i++){
        aloc[i]=-1;
    }
    for (int i = 0; i < n; i++)
    {  int ind=-1;
             for (int j = 0; j < m; j++)
    {
        if(process[i]<blocksize[j]){
            ind=j;break;
        }
    }  
    if(ind!=-1){
        aloc[i]=ind+1;
        blocksize[ind]-=process[i];
        
    }
    }

    for (int i = 0; i < 4; i++)
    {
        cout<<aloc[i]<<endl;
    }
    
    
}

int main() {    
   int blockSize[] = {100, 500, 200, 300, 600}; 
    int processSize[] = {212, 417, 112, 426};  
    int aloc[4];
    firstfit(processSize,4,blockSize,5,aloc);
   
}