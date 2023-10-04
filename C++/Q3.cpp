#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int nu, nd;
    
    cin >> nu >> nd;
    
    cout << "Enter Elements of nums: ";
    vector<int> nums(nu);
    for (int i = 0; i < nu; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter Elements of nums divide: ";
    vector<int> numsDivide(nd);
    for (int i = 0; i < nd; i++) {
        cin >> numsDivide[i];
    }
    
    sort(nums.begin(), nums.end());
    sort(numsDivide.begin(), numsDivide.end());
    
    int m = 0;
    for (int i = 0; i < nu; i++) {
        int l = 0;
        for (int j = 0; j < nd; j++) {
            if (numsDivide[j] % nums[i] == 0) {
                l++;
            } else {
                break;
            }
        }
        if (l == nd) {
            break;
        } else {
            m++;
        }
    }
    
    if (m == nu) {
        cout << -1;
    } else {
        cout << m;
    }
    
    return 0;
}
