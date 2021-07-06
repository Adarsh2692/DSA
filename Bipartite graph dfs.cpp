#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool bipartite(ll i,ll c,vector<ll> a[],vector<ll> color){
    color[i]=c;
    for(auto it:a[i]){
        if(color[it]==-1){
            if(!bipartite(it,1-color[i],a,color)) return false;
        }else if(color[it]==color[i]) return false;
    }
    return true;
}

bool checkBipartite(ll n, vector<ll> a[]){
    vector<ll> color(n+1,-1);
    for(ll i=1;i<=n;i++){
        if(color[i]==-1){
            if(!bipartite(i,1,a,color)) return false;
        }
    }
    return true;
}

int main() {
    ll n,m,i;cin>>n>>m;
    vector<ll> a[n+1];
    for(i=0;i<m;i++){
        ll p,q;cin>>p>>q;
        a[p].push_back(q);
        a[q].push_back(p);
    }
    cout<<checkBipartite(n,a);
	return 0;
}
