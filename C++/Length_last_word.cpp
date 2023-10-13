leetcode problem link -https://leetcode.com/problems/length-of-last-word/submissions/



#include<iostream>
#include<limits.h>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
         int length = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] != ' ') {
      length++;
    } else if (length > 0) {
      break;
    }
  }
  return length;
    }
};