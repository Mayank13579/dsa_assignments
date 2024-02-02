#include<bits/stdc++.h>
using namespace std;

void worst(int process[],int n,int blocksize[],int m,int aloc[]){
        for (int i = 0; i < n; i++)
        {
            aloc[i]=-1;
        }
        for (int i = 0; i < n; i++)
        {       int max=INT_MIN;
                int idx=-1;
            for (int j = 0; j < m; j++)
            {   
                if(process[i]<blocksize[j]){
                    if(blocksize[j]>max){
                        max=blocksize[j];
                        idx=j;
                    }
                }
            }
            if(idx!=-1){
                blocksize[idx]-=process[i];
                aloc[i]=idx+1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout<<aloc[i]<<endl;
        }  
}

int main() {
 int  blocksize[]   = {100, 500, 200, 300, 600};
     int   processsize[] = {212, 417, 112, 426}; 
     int aloc[4];
     worst(processsize,4, blocksize,5,aloc);
}