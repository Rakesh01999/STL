#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>v;
    for (int i = 1; i <= n; i++)
    {
        int x;cin>>x;
        v.push_back(x);
    }
    int x;cin>>x;
    v.erase(v.begin()+x-1);    
    int a,b;cin>>a>>b;
    v.erase(v.begin()+a-1, v.begin()+b-1);    
    cout<<v.size()<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0;
}