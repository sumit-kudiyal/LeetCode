#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define be begin()
#define en end()
#define le length()
#define sz size()
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define eps 1e-6
#define pi 3.141592653589793
using namespace std;
template<class T> inline T gcd(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
template<class T> inline T mod(T x) { if(x < 0) return -x; else return x; }
typedef vector<int> VII;
typedef pair<int, int> PII;
typedef pair<int, PII > PPII;
typedef vector< PPII > VPPII;
typedef vector< PII > VPII;
const int MOD = 1e9 + 7;
const int INF = 1e9;
// Template End





#define TRACE
#ifdef TRACE
#define TR(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define TR(...)
#endif
typedef long long               LL;
typedef pair<int,int>           II;
typedef vector<int>             VI;
typedef vector<II>              VII;
#define REP(i,i1,n)             for(int i=i1;i<n;i++)
#define REPB(i,i1,n)            for(int i=i1;i>=n;i--)
#define PB                      push_back
#define MP                      make_pair
#define ALL(c)                  (c).begin(),(c).end()
#define F                       first
#define S                       second
#define log2                    0.30102999566398119521373889472449L
#define SZ(a)                   (int)a.size()
#define EPS                     1e-12
#define MOD                     1000000007
#define FAST_IO                 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define SI(c)                   scanf("%d",&c)
#define SLL(c)                  scanf("%lld",&c)
#define PIN(c)                  printf("%d\n",c)
#define PLLN(c)                 printf("%lld\n",c)
#define N                       200010
#define endl                    '\n'
#define FILL(ar,vl)             for(int i=0;i<N;i++)ar[i]=vl
#define FILL2(ar,vl)            for(int i=0;i<N;i++)for(int j=0;j<N;j++)ar[i][j]=vl
inline int mult(int a , int b) { LL x = a; x *= LL(b); if(x >= MOD) x %= MOD; return x; }
inline int add(int a , int b) { return a + b >= MOD ? a + b - MOD : a + b; }
LL powmod(LL a,LL b) { if(b==0)return 1; LL x=powmod(a,b/2); LL y=(x*x)%MOD; if(b%2) return (a*y)%MOD; return y%MOD; }
//--------------------------MAIN CODE STARTS HERE----------------
#define MAX 1e9
int main() {
    int T;
    SI(T);
    while(T--) {
        int A, B, n;
        SI(n);
        int X[n], Y[n], R[n], vis[N], mark_1[n], mark_2[n], dist[n];
        memset(vis,0,sizeof(vis));
        memset(mark_1,0,sizeof(mark_1));
        memset(mark_2,0,sizeof(mark_2));
        vector<int> g[n];
        for(int i = 0; i < n; i ++) {
            SI(X[i]);SI(Y[i]);SI(R[i]);
        }
        SI(A);SI(B);


        for(int i = 0; i < n ; i ++) {
            for(int j = i + 1; j < n; j ++) {
               LL dist_1 = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
               LL dist_2 =(R[i] + R[j]) * (R[i] + R[j]);
               if(dist_1 <= dist_2) {                  // constructing edge between overlapping rocks
                    g[i].push_back(j);
                    g[j].push_back(i);
               }
            }
        }
        // checking which of the rocks overlap with the shore (y=a) && (y=b)
        for(int i = 0; i < n; i++) {
            if(abs(Y[i] - A) <= R[i]) mark_1[i] = 1;
            if(abs(Y[i] - B) <= R[i]) mark_2[i] = 1;
        }
        priority_queue< II,vector<II>,greater<II> > Q;
        for(int i = 0; i < n; i++) dist[i] = MAX;
        for(int i = 0; i < n; i++) {
            if(mark_2[i]) {
                Q.push(MP(1,i));
                dist[i] = 1;
            }
        }
        int ans = MAX;
        while(!Q.empty()) {
            II idx = Q.top();
            int cost = idx.first, id = idx.second;
            Q.pop();
            if(vis[id]) continue;
            vis[id] = 1;
            if(mark_1[id]) {
                ans = min(ans,cost);
            }
            for(int i = 0; i < g[id].size(); i ++) {
                if(dist[g[id][i]] > cost + 1) {
                    dist[g[id][i]] = cost + 1;
                    Q.push(MP(cost + 1,g[id][i]));
                }
            }
        }
        if(ans!=MAX)
            PIN(ans);
        else PIN(-1);
    }
    return 0;
}
