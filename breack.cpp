#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> generateParenthesis(int n)
{
    if (n <= 0)
        return {};
    if (n == 1)
        return {"()"};
    vector<string> resPre = generateParenthesis(n - 1);
    vector<string> res(0);

    for (int i = 0; i < resPre.size(); i++)
    {
        string tempt = "(" + resPre[i] + ")";
        res.push_back(tempt);
        tempt = "()" + resPre[i];
        res.push_back(tempt);
        tempt = resPre[i] + "()";
        bool isExsit = false;
        for (int j = 0; j < res.size(); j++)
            if (res[j] == tempt)
            {
                isExsit = true;
                break;
            }
        if (!isExsit)
            res.push_back(tempt);
    }
    return res;
}
int main()
{
    vector<string> res = generateParenthesis(3);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << '\n';
    }
    return 0;
}