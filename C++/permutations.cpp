// question https://cses.fi/problemset/task/1070/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<long int>o;
    vector<long int>e;
    
 
    long int i,n;
    cin>>n;
    if(n==3||n==2)
    {
        cout<<"NO SOLUTION";
        exit(0);
    }
   for(i=1;i<=n;i++)
   {
       if(i%2==0)
       
       e.push_back(i);
       else
       o.push_back(i);
   }
   if(n%2==0)
   {
       for(i=0;i<n/2;i++)
       {
           cout<<e[i]<<" ";
       }
       for(i=0;i<n/2;i++)
       {
           cout<<o[i]<<" ";
       }
       
       
   }
   else
   {
   for(i=0;i<n/2;i++)
   {
       cout<<e[i]<<" ";
       
   }
   for(i=0;i<n/2+1;i++)
   {
       cout<<o[i]<<" ";
   }
   }
   return 0;
}
