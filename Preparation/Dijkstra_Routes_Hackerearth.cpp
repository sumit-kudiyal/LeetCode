/*
i/p :
1000
4
5
1 2 1 2500
1 3 1 3000
1 4 2 7000
2 4 1 3000
3 4 1 2000
1
4

o/p : 1->3->4 3 8000

*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10;
vector<pair<int,pair<int,int>>> adj[MAX];
bool vis[MAX];
int dist[MAX];
int distt[MAX];
int parent[MAX];

int dijkstra(int s,int d,int k){
    multiset<pair<int,int>> ms;
    ms.insert({0,s});
    dist[s]=0;
    distt[s]=0;
    parent[s]=-1;
    while(!ms.empty())
    {
        pair<int,int> p= *ms.begin();
        ms.erase(ms.begin());
        int x=p.second;
        if(x==d)return distt[d];

        for(int i=0;i < adj[x].size();i++){

            int y = adj[x][i].first;
            int t = adj[x][i].second.first;
            int c = adj[x][i].second.second;

            if(y==d){
                if(dist[y]>dist[x]+k*t+c)
                {
                    dist[y]=dist[x]+k*t+c;
                    distt[y]=distt[x]+t;
                    parent[y]=x;
                    ms.insert({dist[y],y});
                }
            }
                else
                {
                    if(dist[y]>dist[x]+k*(t+1)+c){
                        dist[y]=dist[x]+k*(t+1)+c;
                        distt[y]=distt[x]+t+1;
                        parent[y]=x;
                        ms.insert({dist[y],y});
                    }
                }

        }
    }
    return -1;
}

void display(int s,int d){
    int x=d;
    vector<int> v;
    while(x!=s){
        v.push_back(x);
        x=parent[x];
    }
    v.push_back(s);
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i];
        if(i<v.size()-1) cout<< "->";
        else cout<< ' ';
    }
}


int main(int argc, char* argv[]) {
    if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
    if(argc == 3) freopen(argv[2], "w", stdout);
    ios::sync_with_stdio(false);
    int n, k, m, y, x, t, c, s, d;
    cin >> k >> n >> m;
    if (!(1 <= k and k <= 1000)) {
        cout << "Error" << endl;
        return 0;
    }
    if (!(1 <= m and m <= (n*(n-1))/2)) {
        cout << "Error" << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> t >> c;
        if (!(1 <= x and x <= n)) {
            cout << "Error" << endl;
            return 0;
        }
        if (!(1 <= y and y <= n)) {
            cout << "Error" << endl;
            return 0;
        }
        adj[x].push_back({y, {t, c}});
        adj[y].push_back({x, {t, c}});
    }
    cin >> s >> d;
    if (!(1 <= d and d <= n)) {
        cout << "Error" << endl;
        return 0;
    }
    if (!(1 <= s and s <= n)) {
        cout << "Error" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        distt[i] = INT_MAX;
    }
    int anst = dijkstra(s, d, k);
    if (anst == -1) cout << "Error" << endl;
    else {
        display(s, d);
        cout << anst << ' ' << dist[d] << endl;
    }
    return 0;
}
