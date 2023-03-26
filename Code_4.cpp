#include <iostream>
#include <random>
#include <cmath>
#include <vector>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

bool TrialDivision(int n)
{
    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    vector <int> v;
    v.resize(1000,0);
    int num;
    bool flag;
    mt19937 rnd(clock());
    for (int i = 0; i < 1000; i++)
    {
        flag = true;
        while(flag)
        {
            num = rnd();
            if (TrialDivision(num))
            {
                flag = false;
            }
        }
        v.at(i) = num;
        cout << v.at(i) << endl;
    }
    int tmp;
    for (int i = 0; i < 998; i++)
    {
        for (int j = i + 1; j < 1000; j++)
            if(v.at(i) > v.at(j))
            {
                tmp = v.at(i);
                v.at(i)= v.at(j);
                v.at(j) = tmp;
            }
    }
    cout << "min number = " << v.front() << endl;
    cout << "max number = " << v.back() << endl;
    return 0;
}