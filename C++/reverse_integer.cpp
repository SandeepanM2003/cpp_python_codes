//leetcode problem url  -  https://leetcode.com/problems/reverse-integer/description/


#include<iostream>
#include<limits.h>
using namespace std;



class Solution {
public:
    int reverse(int x) {
         int rev = 0;
  while (x != 0) {
    int digit = x % 10;
    if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
      return 0;
    }
    if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) {
      return 0;
    }
    rev = rev * 10 + digit;
    x /= 10;
  }
  return rev;
        
    }
};