//question-https://leetcode.com/problems/circular-sentence/description/
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    bool isCircularSentence(string sentence) {
    int l =sentence.length();
    vector<int>j;
    int c=0;
    for(int i=0;i<l;i++)
    {
        if(sentence[i]==' ')
        j.push_back(i);
    }
    for(int i=0;i<j.size();i++)
    {
        if(sentence[j[i]-1]!=sentence[j[i]+1])
        {
        c=1;
        break;}
    }
    if(sentence[0]!=sentence[sentence.length()-1])
    c=1;
    if(c==1)
    return false;
    else return true;
    }
};
