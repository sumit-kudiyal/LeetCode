#include<bits/stdc++.h>
using namespace std;

string solve(string s){
    int n=s.size();
    unordered_map<char,int> mp;
    for(auto c:s){
        mp[c]++;
    }
    string res;
    for(auto x:mp){
        res=x.first;
        res=x.second;
    }

    return res;


}


int main()
{
    string s="aabcccaaa";
    cout<<solve(s)<<endl;
    return 0;
}
