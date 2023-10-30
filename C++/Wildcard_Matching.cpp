
#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring of S1 contains only '*'
bool isAllStars(string &S1, int i) {
    // S1 is taken in 1-based indexing
    for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
            return false;
    }
    return true;
}

// Function to perform wildcard pattern matching between S1 and S2
bool wildcardMatching(string &S1, string &S2) {
    int n = S1.size();
    int m = S2.size();

    // Create two arrays to store previous and current rows of matching results
    vector<bool> prev(m + 1, false);
    vector<bool> cur(m + 1, false);

    prev[0] = true; // Initialize the first element of the previous row to true

    for (int i = 1; i <= n; i++) {
        cur[0] = isAllStars(S1, i); // Initialize the first element of the current row
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                cur[j] = prev[j - 1]; // Characters match or S1 has '?'
            } else {
                if (S1[i - 1] == '*') {
                    cur[j] = prev[j] || cur[j - 1]; // '*' represents empty or a character
                } else {
                    cur[j] = false; // Characters don't match and S1[i-1] is not '*'
                }
            }
        }
        prev = cur; // Update the previous row with the current row
    }

    // The value at prev[m] contains whether S1 matches S2
    return prev[m];
}

int main() {
    string S1 = "ab*cd";
    string S2 = "abdefcd";

    // Call the wildcardMatching function and print the result
    if (wildcardMatching(S1, S2))
        cout << "String S1 and S2 do match";
    else
        cout << "String S1 and S2 do not match";

    return 0;
}
