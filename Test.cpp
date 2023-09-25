#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> res;
    vector<vector<int>> seg;

    int n=seg.size();
    unordered_map<int,int> mp;
    int ctr=0;

    for(int i=0;i<n;i++){
        int l = seg[i][0];
        int h = seg[i][1];
        for(int j=l;j<=h;j++){
            if(!mp.count(j)){
                ctr++;
                mp[j]=1;
            }
        }
        res.push_back(ctr);

    }


    return 0;
}