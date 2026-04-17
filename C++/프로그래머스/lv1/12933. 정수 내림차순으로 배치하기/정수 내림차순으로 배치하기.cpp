#include <string>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;

    vector<int> vecNums = {};

    while (n != 0)
    {
        vecNums.push_back(n % 10);
        n /= 10;
    }

    sort(vecNums.begin(), vecNums.end());

    string strNum = {};

    for (int i = vecNums.size() - 1; i >= 0; i--)
    {
        strNum += '0' + vecNums[i];
    }

    answer = stoll(strNum);

    return answer;
}

int main(void* pArg)
{
    solution(12345);

    return 0;
}