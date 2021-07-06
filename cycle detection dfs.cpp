#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool cycle(ll i,ll par,vector<ll> a[],vector<ll>& vis){
    vis[i]=1;
    for(auto it:a[i]){
        if(!vis[it]){
            vis[it]=1;
            if(cycle(it,i,a,vis)) return true;
        } else if(par!=it) return true;
    }
    return false;
}

bool cycleDetection(ll n,vector<ll> a[]){
    vector<ll> vis(n+1,0);
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            if(cycle(i,-1,a,vis)) return true;
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
