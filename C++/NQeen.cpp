#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> top;
unordered_map<int, bool> le;
unordered_map<int, bool> bottom;

void placeQueen(int j, int &n, vector<vector<char>> &ans)
{
    // Base Case
    if (j >= n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << ans[i][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!(top[i - j]) && !(le[i]) && !(bottom[i + j]))
        {
            ans[i][j] = 'Q';
            top[i - j] = true;
            bottom[i + j] = true;
            le[i] = true;
            placeQueen(j + 1, n, ans);
            
            // BackTracking
            ans[i][j] = '-';
            top[i - j] = false;
            bottom[i + j] = false;
            le[i] = false;
        }
    }
}

int main()
{
    int n=4;

    vector<vector<char>> ans(n, vector<char>(n, '-'));
    placeQueen(0, n, ans);

    return 0;
}