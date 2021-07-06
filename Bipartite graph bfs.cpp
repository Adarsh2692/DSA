#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool bipartite(ll i,vector<ll> a[],vector<ll> color){
    queue<ll> q;
    q.push(i);
    color[i]=1;
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        for(auto it:a[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                q.push(it);
            }else if(color[it]==color[node]) return false;
        }
    }
    return true;
}

bool checkBipartite(ll n, vector<ll> a[]){
    vector<ll> color(n+1,-1);
    for(ll i=1;i<=n;i++){
        if(color[i]==-1){
            if(!bipartite(i,a,color)) return false;
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
