//Question Link-https://leetcode.com/problems/palindrome-partitioning/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPal(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
            return false;
            start++;
            end--;
        }
        return true;
    }
    void help(string s,vector <string> temp,vector<vector<string>> &res,int index)
    {
        if(index==s.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPal(s,index,i))
            {
                temp.push_back(s.substr(index,i-index+1)); // why i-index+1?
                help(s,temp,res,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    { 
        vector <string> temp;
        vector<vector<string>> res;
        if(s.empty()) return res;
        help(s,temp,res,0);
        return res;
        
    }
};