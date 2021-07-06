#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool cycle(ll n,ll i,vector<ll> a[],vector<ll>& vis){
    queue<pair<ll,ll>> q;
    q.push({i,-1});
    vis[i]=1;
    while(!q.empty()){
        ll node=q.front().first;
        ll par=q.front().second;
        q.pop();
        for(auto it:a[node]){
            if(!vis[it]){
                q.push({it,node});
                vis[it]=1;
            } else if(par!=it){
                return true;
            }
        }
    }
    return false;
}

bool cycleDetection(ll n,vector<ll> a[]){
    vector<ll> vis(n+1,0);
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            if(cycle(n,i,a,vis)) return true;
        }
    }
    return false;
}

int main() {
    ll n,m,i;cin>>n>>m;
    vector<ll> a[n+1];
    for(i=0;i<m;i++){
        ll p,q;cin>>p>>q;
        a[p].push_back(q);
        a[q].push_back(p);
    }
    cout<<cycleDetection(n,a);
	return 0;
}
