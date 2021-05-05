#include <iostream>
#include <vector>

using namespace std;
void tried(int n, int k, vector<vector<int>> &res, vector<int> &arr)
{
    if (arr.size() == k)
    {
        res.push_back(arr);
        return;
    }
    int start = 0;
    if (!arr.empty())
        start = arr[arr.size() - 1];
    for (int val = start + 1; val <= n; val++)
    {
        arr.push_back(val);
        tried(n, k, res, arr);
        arr.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    res.resize(0);
    vector<int> arr;
    arr.resize(0);
    tried(n, k, res, arr);
    return res;
}
void printData(const vector<vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        cout << '[';
        for (int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j] << ',';
        }
        cout << ']';
    }
}
int main()
{
    vector<vector<int>> res = combine(4, 2);
    printData(res);
    return 0;
}