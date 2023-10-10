#include<bits/stdc++.h>
using namespace std;


int subarraysXor(vector<int> &a, int k)
{
    int n=a.size();
    int xr=0,ans=0;
    map<int,int> m;
    m[0]++;
    for(int i=0;i<n;i++){
        xr^=a[i];
        int req=xr^k;
        if(m[req]>0)ans+=m[req];
        m[xr]++;

    }

    return ans;
    
}
int main(){
// Size of Array....
int n;
cin>>n;
vector<int> v;
for (int i = 0; i < n; i++)
{
   int x;
   cin>>x;
   v.push_back(x);
}
// The value K required......
int k;
cin>>k;
cout<<subarraysXor(v,k);


}