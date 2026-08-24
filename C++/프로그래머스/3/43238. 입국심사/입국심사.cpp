#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    unsigned long long iMin = 1, iMax = 1000000000 * 1000000000;
    unsigned long long iTime = -1;

    while (iMin <= iMax)
    {
        iTime = (iMin / 2) + (iMax / 2);
        unsigned long long iSum = 0;

        for (auto& iter : times)
        {
            iSum += iTime / iter;
        }

        if (iSum >= n)
        {
            answer = iTime;
            iMax = iTime - 1;
        }
        else
        {
            iMin = iTime + 1;
        }
    }

    return answer;
}