#include<bits/stdc++.h>
using namespace std;

int least(int pages[],int n, int cap){
    int pfault=0;
    vector<int >v(cap);int count=0;
    for (int i = 0; i < n; i++)
    {
        int page=pages[i];
        auto it=find(v.begin(),v.end(),page);

        if(it!=v.end()){
            v.erase(it);
            v.push_back(page);

        }
        else {
            if(v.size()==cap){
                v.erase(v.begin());
            }
            count++;
            v.push_back(page);


        }
    }
    return count;

}

int main() {
        int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
        int cap=3;
        cout<<least(pages,12,3)<<endl;

}