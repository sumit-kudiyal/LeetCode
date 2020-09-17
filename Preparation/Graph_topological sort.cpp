/*" https://leetcode.com/problems/course-schedule-ii/"

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .


*/
class Solution {
typedef vector<vector<int>> graph;
typedef vector<bool> vb;
typedef vector<int> vi;

void topsort(int i,vb& vis,vi& res,graph& G){
    vis[i]=true;
    for(auto it=G[i].begin();it!=G[i].end();it++)
        if(!vis[*it])
            topsort(*it,vis,res,G);

    res.push_back(i);
}

vector<int> topologicalsort(graph& G,int n){
    vector<int> res;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i])
            topsort(i,vis,res,G);
    }

    return res;

}

bool iscycle(int i,graph& G, vb& visited, vb& tovisit){
    visited[i]=true;
    tovisit[i]=true;
    for(auto it=G[i].begin();it!=G[i].end();it++){
        if(!visited[*it]&& iscycle(*it,G,visited,tovisit))
            return true;
        else if(tovisit[*it])
            return true;
    }
    tovisit[i]=false;
    return false;
}

bool cycle(int n,graph& G){
        vb visited(n,false);
        vb tovisit(n,false);
        for(int i=0;i<n;i++){
            if(iscycle(i,G,visited,tovisit))
                return true;
        }
        return false;
    }




public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        graph G(n);
        for(auto x:prerequisites)
            G[x[0]].push_back(x[1]);

        if(cycle(n,G)) return vector<int>(); //to check if any cycle is present, if then return empty vector.

        return topologicalsort(G,n);
    }
};
