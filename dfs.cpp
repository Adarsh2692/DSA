#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void dfs(ll i,vector<ll> &vis,vector<ll> a[],vector<ll> &dfsarr){
    dfsarr.push_back(i);
    vis[i]=1;
    for(auto it:a[i]){
        if(!vis[it]){
            dfs(it,vis,a,dfsarr);
        }
    }
}

int main() {
    ll n,m,i;cin>>n>>m;
    vector<ll> a[n+1];
    for(i=0;i<m;i++){
        ll p,q;
        cin>>p>>q;
        a[p].push_back(q);
        a[q].push_back(q);
    }
    vector<ll> vis(n+1),dfsarr;
    for(i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,vis,a,dfsarr);
        }
    }
    for(auto it:dfsarr){
        cout<<it<<" ";
    }
	return 0;
}
