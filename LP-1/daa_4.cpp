#include <iostream>
#include <algorithm>
using namespace std;

const int N = 4;
const int INF = 1e9; // A large value to represent infinity

int distanceMatrix[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

void tspBranchAndBound(int level, int cost, int path[N], int bestPath[N], int& minCost) {
    if (level == N) {
        cost += distanceMatrix[path[level - 1]][0];
        if (cost < minCost) {
            minCost = cost;
            for (int i = 0; i < N; i++) {
                bestPath[i] = path[i];
            }
        }
        return;
    }

    for (int i = level; i < N; i++) {
        swap(path[level], path[i]);
        int bound = cost + distanceMatrix[path[level - 1]][path[level]];
        if (bound < minCost) {
            tspBranchAndBound(level + 1, bound, path, bestPath, minCost);
        }
        swap(path[level], path[i]);
    }
}

int main() {
    int path[N];
    for (int i = 0; i < N; i++) {
        path[i] = i;
    }

    int bestPath[N];
    int minCost = INF;

    tspBranchAndBound(1, 0, path, bestPath, minCost);

    cout << "Optimal TSP tour: ";
    for (int i = 0; i < N; i++) {
        cout << bestPath[i] << " -> ";
    }
    cout << bestPath[0] << endl;

    cout << "Optimal TSP tour cost: " << minCost << endl;

    return 0;
}