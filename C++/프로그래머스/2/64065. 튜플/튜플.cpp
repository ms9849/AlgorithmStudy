#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
단순 시뮬레이션 문제.어렵진 않아보인다.
오히려 문자열 파싱이 더 문제..
*/

vector<int> solution(string s) {
    vector<int> answer;
    int iLength = s.length();
    map<int, int> isAlreadyExist = {};
    vector<vector<int>> vecNums = {};

    //첫 글자와 마지막 글자는 반드시 { } 임이 보장된다.
    for (int i = 1; i < iLength - 2; ++i)
    {
        if (s[i] == '{')
        {
            int j = i;
            vector<int> vecTemp = {};
            string strTemp = "";
            //j - i가 홀수라면, 
            while (s[j] != '}')
            {
                if (s[j] >= '0' && s[j] <= '9')
                    strTemp += s[j];
                else if (s[j] == ',')
                {
                    vecTemp.push_back(stoi(strTemp));
                    strTemp = "";
                }
                j++;
            }

            vecTemp.push_back(stoi(strTemp));

            vecNums.push_back(vecTemp);
        }
    }

    sort(vecNums.begin(), vecNums.end(), [](vector<int> lhs, vector<int> rhs)->bool {
        return lhs.size() < rhs.size();
        });

    for (int i = 0; i < vecNums.size(); ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (isAlreadyExist.find(vecNums[i][j]) == isAlreadyExist.end())
            {
                isAlreadyExist[vecNums[i][j]]++;
                answer.push_back(vecNums[i][j]);
            }
        }
    }

    return answer;
}