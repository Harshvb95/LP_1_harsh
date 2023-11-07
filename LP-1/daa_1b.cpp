#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1]+ knapSack(W - wt[n - 1], wt, val, n - 1),
                    knapSack(W, wt, val, n - 1));
}
/*Include the current item in the knapsack, which results in an increase in the total value. This is calculated by adding the value of the current item (`val[n - 1]`) to the result of the recursive call with reduced capacity (`W - wt[n - 1]`) and the next item (`n - 1`).
   - Exclude the current item from the knapsack, which does not change the value. This is calculated by making a recursive call with the same capacity (`W`) and the next item (`n - 1`).

*/
int main()
{
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n);
    return 0;
}


/*#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

int main() {
    int W, n;

    cout << "Enter the knapsack capacity (W): ";
    cin >> W;

    cout << "Enter the number of items (n): ";
    cin >> n;

    int profit[n], weight[n];

    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Maximum value in the knapsack: " << knapSack(W, weight, profit, n) << endl;

    return 0;
}
*/