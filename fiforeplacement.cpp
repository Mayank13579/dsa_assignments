#include<bits/stdc++.h>
using namespace std;

int fifo(int pages[],int n,int cap){
    unordered_set<int>s;
    queue<int>indexes;
    int pagefault=0;
    for (int i = 0; i < n; i++)
    {
        if(s.size()<cap){
            if(s.find(pages[i])==s.end()){
                 s.insert(pages[i]);
                pagefault++;
                indexes.push(pages[i]);
            }
        }
        else{
            if(s.find(pages[i])==s.end()){
                int val=indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                pagefault++;
            }
        }
    }
    return pagefault;
}

int main() {
    int pages[]={7, 0, 1, 2, 0, 3, 0, 4, 
                   2, 3, 0, 3, 2};
    int cap=4;
    cout<<fifo(pages,13,4);
}