/*
"Dijkstra's Algorithm"
Algorithm Steps:

Set all vertices distances = infinity except for the source vertex, set the source distance = .

Push the source vertex in a min-priority queue in the form (distance , vertex), as the comparison in the min-priority queue will be according to vertices distances.

Pop the vertex with the minimum distance from the priority queue (at first the popped vertex = source).

Update the distances of the connected vertices to the popped vertex in case of "current vertex distance + edge weight < next vertex distance", then push the vertex
with the new distance to the priority queue.

If the popped vertex is visited before, just continue without using it.

Apply the same algorithm again until the priority queue is empty.

*/

#define SIZE 10000+1
vector<pair<int,int>> v[SIZE];       // each vertices has all connected vertices qith edges weight.
int dist[SIZE];
bool vis[SIZE]; 

void dijkstra()
{
  memset(dist,-1,sizeof dis);      //all dist are infinity 
  memset(vis,false,sizeof vis);   //all vis are false
  
  dist[1]=0;
  
  multiset< pair<int,int>> s;     // multiset will do the same job as min priority queue.
  
  s.insert({0,1});        //insert the source node with distance =0.
  
  while(!s.empty())
  {
    pair<int,int> p= *s.begin();
    s.erase(s.begin());   //pop the vertex with min distance;
    
    int x= p.s;
    int w=p.f;
    
    if(vis[x]) continue;      //to check whether the index has been visited or not. 
    vis[x]= true;
    
    for(int i=0;i <v[x].size();i++){
      int e= v[x][i].f;
      int w1= v[x[[i].s;
      if(dis[x]+ w1 < dist[e]){               //check if the next distance could be minimized.
        dist[e] = dist[x] + w1;
        s.insert({dist[e],e});          //insert the new dist with updated distance
      
      }
    
    
    }
  
  }
 } 
  
