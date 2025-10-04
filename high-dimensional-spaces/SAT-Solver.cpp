#include <iostream>
#include <vector>
using namespace std;

void SAT(vector<int> &x, int i)
{
    if (i == (int)x.size())
    {
        for (auto v : x)
            cout << v;
        cout << endl;
    }
    else
        for (int j = 0; j < 2; j++)
        {
            x[i] = j;
            SAT(x, i + 1);
        }
}

int main()
{
    vector<int> x(3);
    SAT(x, 0);
}