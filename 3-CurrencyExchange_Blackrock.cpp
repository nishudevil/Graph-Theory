#include<bits/stdc++.h>
using namespace std;
/*struct Node{
int data;
struct Node* next;
}; */
float ans;
void dfs(unordered_map<string,unordered_map<string,float> > &mp,string node,
string dest,unordered_map<string,int> vis,float dist_till)
{




if(vis.count(node)) return ;
vis[node]=1;
if(node==dest)
{
//cout<<"Dist till "<<dist_till<<endl;
ans=max(ans,dist_till);
return ;
}


for(auto &next_curr:mp[node])
{
//cout<<next_curr.first<<" "<<dist_till*next_curr.second<<endl;
dfs(mp,next_curr.first,dest,vis,dist_till*next_curr.second);


}






}


int solve(vector<vector<string> >lis,string src,string dest,int n)
{
ans=-1.0;
unordered_map<string,unordered_map<string,float> >mp;
for(int i=0;i<n;i++)
{
//cout<<lis[i][0]<<" --- "<<lis[i][1]<<" = "<<stof(lis[i][2])<<endl;
string x=lis[i][0];
string y=lis[i][1];
mp[x][y]=stof(lis[i][2]);


}
unordered_map<string,int> vis;


dfs(mp,src,dest,vis,1.0);
cout<<"ans is "<<ans<<endl;;
return 0;
}




int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int t;
t=2;
while(t--){
int n;
cin>>n;
vector<vector<string> >lis;
string a,b,c;
for(int i=0;i<n;i++)
{
vector<string> temp;
cin>>a>>b>>c;
temp.push_back(a);
temp.push_back(b);
temp.push_back(c);
lis.push_back(temp);


}
string src,dest;
cin>>src>>dest;
solve(lis,src,dest,n);
}


}
