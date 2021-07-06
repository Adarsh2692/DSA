#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void bfs(ll n,vector<ll> a[]){
    vector<ll> vis(n+1);
    queue<ll> q;
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            q.push(i);
            vis[i]=1;
            cout<<i<<" ";
            while(!q.empty()){
                int k=q.front();
                q.pop();
                for(auto it:a[k]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                        cout<<it<<" ";
                    }
                }
            }
            cout<<"\n";
        }
    }
}

int main() {
    ll n,m,i;cin>>n>>m;
    vector<ll> a[n+1];
    for(i=0;i<m;i++){
        ll p,q;cin>>p>>q;
        a[p].push_back(q);
        a[q].push_back(p);
    }
    bfs(n,a);
	return 0;
}
