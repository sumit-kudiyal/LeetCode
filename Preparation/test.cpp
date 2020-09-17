//my template
vi vp[1000000];
vi vp1[1000000];
vi ans[1000000];
int vis[1000000];
stack<int> st;
void toposort(int x)
{
vis[x]=1;
rep(i, 0, vp[x].size())
{
if(!vis[vp[x][i]])
toposort(vp[x][i]);
}
st.push(x);
}
int main()
{
fast
str s1,s2;
ll inp,n,a,b,t,q,k,m,wt;
vi v1,v2;
vic v;
char c1,c2;
FILL(vis, 0);
in>>n>>m;
rep(i, 0, m)
{
in>>a>>b;
// a++;b++;
vp[a].pb(b);
vp1[b].pb(a);

//sortv(vp[a]);
}
rep(i,1,n+1)
{
sort(vp[a].rbegin(),vp[a].rend());
}
//now i will be applying the topoligical sort
for(int i=n;i>=1;i--)
{
if(!vis[i])
toposort(i);
}
while(!st.empty())
{
out st.top()<<" ";
st.pop();
}
/*int asf=5;
rep(i, 0, 1000)
{
out i;
if(i==asf)goto kas;
}
kas:
out "this is the end";
//out "hi";*/

}
