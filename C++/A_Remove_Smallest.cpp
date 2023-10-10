// CodeForces Problem Link: https://codeforces.com/problemset/problem/1399/A


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int m=0;m<t;m++)
    {
        int n;
        cin>>n;
        vector<int> vec;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            vec.push_back(x);
        }
        sort(vec.begin(),vec.end());
        bool result=true;
        for(int i=1;i<n;i++)
        {
            if(vec[i]-vec[i-1] >1)
            {
                result=false;
                break;
            }
        }
        result==true?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
    return 0;
}