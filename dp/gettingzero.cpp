#include <bits/stdc++.h>
using namespace std;
const int MOD = 32768;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; if(!(cin>>n)) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> dist(MOD, -1);
    queue<int> q;
    dist[0] = 0; q.push(0);

    while(!q.empty()){
        int v = q.front(); q.pop();
        int d = dist[v];

        int p1 = (v - 1 + MOD) % MOD;
        if(dist[p1] == -1){
            dist[p1] = d + 1;
            q.push(p1);
        }

        if(v % 2 == 0){
            int p2 = v / 2;
            if(dist[p2] == -1){
                dist[p2] = d + 1;
                q.push(p2);
            }
            int p3 = (v + MOD) / 2; 
            if(dist[p3] == -1){
                dist[p3] = d + 1;
                q.push(p3);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << dist[a[i]] << (i+1==n?'\n':' ');
    }
    return 0;
}
