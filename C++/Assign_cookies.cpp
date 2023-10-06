// solution class for https://leetcode.com/problems/assign-cookies/description/


#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int j=0;
       int c=0;
       int g1=g.size(),s1=s.size(),s2=s1-1;
       if(s.size()==0||g.size()==0)
       return 0;
        for(int i=0;i<g1;i++)
        {
            while(j<s1){
            j++;
                if(g[i]<=s[j-1])
                {
                    c++;break;
                }
            }
            if(j==s1)
            break;
           }
       return c;
    }
};