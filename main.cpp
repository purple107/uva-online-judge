#include<bits/stdc++.h>
#include <cstdlib>
#include<string>
#include <sstream>
#include <algorithm>
#define pi acos(-1)
#define ll long long
using namespace std;
int X[] = {0, 1, 0, -1};
int Y[] = {-1, 0, 1, 0};
vector<int>v[1000];
bool visit[1000];
int n,e;
int dfs(int s)
{
    int parrent[10000];
    //memset(parrent,0,sizeof parrent);
    queue<int>q;
    q.push(s);
    visit[s]=true;
    parrent[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++){
            int x=v[u][i];
            if(!visit[x]){
                visit[x]=true;
                q.push(x);
                parrent[x]=-1*parrent[u];
            }
            else if(parrent[x]==parrent[u])return true;
        }
    }
    return false;
}
int main()
{
   while((cin>>n>>e)and n!=0){
    memset(visit,0,sizeof visit);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt=0;
    bool ok=false;
    ok=dfs(0);
    if(ok){
        cout<<"NOT BICOLORABLE."<<endl;
    }
    else cout<<"BICOLORABLE."<<endl;
    for(int i=0;i<n;i++)v[i].clear();
   }
}

