#include<iostream>
using namespace std;

int cost[20][20];

class graph {
    int i, j, v, w, k;
public:
    graph() {
        for (i = 1; i <= 20; i++)
            for (j = 1; j <= 20; j++)
                cost[i][j] = 0;
    }
    void create();
    void display();
    void prims();
};

void graph::create() {
    cout << "Enter total Number of nodes: ";
    cin >> v;

    for (i = 1; i <= v; i++) {
        for (j = i + 1; j <= v; j++) {
            cout << "Provide cost of edge between " << i << " and " << j << ": ";
            cin >> w;
            cost[i][j] = cost[j][i] = w;
        }
    }
}

void graph::display() {
    cout << "\n Adjacency Matrix is:";
    for (i = 1; i <= v; i++) {
        cout << endl;
        for (j = 1; j <= v; j++)
            cout << "\t" << cost[i][j];
    }
}

void graph::prims() {
    int pos = 1, mincost = 0, min = 9999, row = 0, col = 0;
    int visit[20], path[20];

    for (i = 1; i <= v; i++) {
        visit[i] = 0;
        path[i] = 0;
    }

    visit[1] = 1;
    path[pos++] = 1;

    cout << endl<<"Initially Minimum Cost is " << mincost;
    for (k = 1; k <= v - 1; k++) {
        min = 9999;
        for (i = 1; i <= v; i++) {
            for (j = 1; j <= v; j++) {
                if (visit[i] == 1 && visit[j] == 0 && cost[i][j] != 0 && min > cost[i][j]) {
                    min = cost[i][j];
                    row = i;
                    col = j;
                }
            }
        }

        mincost += min;
        visit[col] = 1;
        path[pos++] = col;
        cost[row][col] = cost[col][row] = 0;
    }

    cout << "\nTotal Minimum Cost = " << mincost << endl;
    cout << "Shortest Path = ";
    for (i = 1; i <= v; i++)
        cout << path[i] << " ";
}

int main() {
    graph g;
    cout << "Create Minimum Spanning tree" << endl;
    g.create();
    g.display();
    g.prims();
    return 0;
}
