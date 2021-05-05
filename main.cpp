#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
const int sizeBoard = 9;
const int UNASSIGNED = '.';
void readData(vector<vector<char>> &grid)
{
    ifstream ifs("./data.txt");
    if (ifs.is_open())
    {
        grid.resize(sizeBoard);
        for (int i = 0; i < sizeBoard; i++)
        {
            grid[i].resize(sizeBoard);
            for (int j = 0; j < sizeBoard; j++)
            {
                ifs >> grid[i][j];
            }
        }
        ifs.close();
    }
}
void printData(const vector<vector<char>> &grid)
{
    ofstream ofs("res.txt");
    if (ofs.is_open())
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                ofs << grid[i][j] << '\t';
                if (j == 2 || j == 5)
                    ofs << '|' << '\t';
            }
            if (i == 2 || i == 5)
            {
                ofs << '\n';
                for (int j = 0; j < grid.size(); j++)
                    ofs << "----";
            }
            ofs << '\n';
        }

        ofs.close();
    }
}
bool findNextUnassigned(const vector<vector<char>> &grid, int &i, int &j);
bool isSafe(const vector<vector<char>> &grid, const int &i, const int &j, const int k);
bool usedRow(const vector<vector<char>> &grid, const int &row, const int val)
{
    for (int j = 0; j < sizeBoard; j++)
        if (grid[row][j] == val)
            return true;
    return false;
}
bool usedCol(const vector<vector<char>> &grid, const int &col, const int val)
{
    for (int i = 0; i < sizeBoard; i++)
        if (grid[i][col] == val)
            return true;
    return false;
}
bool usedBox(const vector<vector<char>> &grid, const int &row, const int &col, const int val)
{
    int rowBox = (row / 3) * 3;
    int colBox = (col / 3) * 3;
    for (int i = rowBox; i < rowBox + 3; i++)
        for (int j = colBox; j < colBox + 3; j++)
            if (grid[i][j] == val)
                return true;
    return false;
}
bool solverSudoku(vector<vector<char>> &grid)
{
    int i = 0,
        j = 0;
    if (findNextUnassigned(grid, i, j))
    {
        int k;
        for (k = 1; k <= 9; k++)
        {
            if (isSafe(grid, i, j, k))
            {
                grid[i][j] = k + '0';
                solverSudoku(grid);
                grid[i][j] = UNASSIGNED;
            }
        }
    }
    else
    {
        printData(grid);
        return true;
    }
    return false;
}

bool findNextUnassigned(const std::vector<std::vector<char>> &grid, int &i, int &j)
{
    for (i = 0; i < sizeBoard; i++)
        for (j = 0; j < sizeBoard; j++)
            if (grid[i][j] == UNASSIGNED)
                return true;
    return false;
}

bool isSafe(const std::vector<std::vector<char>> &grid, const int &i, const int &j, const int k)
{
    return !usedRow(grid, i, k + '0') && !usedCol(grid, j, k + '0') && !usedBox(grid, i, j, k + '0');
}
int main()
{
    vector<vector<char>> grid;
    readData(grid);
    if (solverSudoku(grid))
    {
        cout << "No solution";
        printData(grid);
    };
    // printData(grid);
    return 0;
}