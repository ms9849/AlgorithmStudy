#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    vector<int> answer;
    map<string, int> mapIdx = {};
    int iIdSize = id_list.size();

    for (int i = 0; i < iIdSize; ++i)
        mapIdx[id_list[i]] = i;

    map<string, int> mapReportCount = {};
    map<string, set<string>> mapReportList = {};
    map<string, int> mapMailCount = {};

    for (auto& iter : report)
    {
        int iLength = iter.size();

        for (int i = 0; i < iLength; ++i)
        {
            if (iter[i] == ' ')
            {
                string reporter = iter.substr(0, i);
                string reported = iter.substr(i + 1, iter.size());

                if (mapReportList[reported].end() == mapReportList[reported].find(reporter))
                {
                    mapReportCount[reported]++;
                    mapReportList[reported].insert(reporter);
                }
            }
        }
    }

    for (auto& iter : mapReportCount)
    {
        //정지 먹었네?
        if (iter.second >= k)
        {
            for (auto& Reporter : mapReportList[iter.first])
            {
                mapMailCount[Reporter]++;
            }
        }
    }

    //미리 공간할당.
    answer.resize(iIdSize);

    for (auto& iter : mapMailCount)
    {
        answer[mapIdx[iter.first]] = iter.second;
    }

    return answer;
}

int main(void* pArg)
{
    vector<string> idList = {
        "muzi",
        "frodo",
        "apeach",
        "neo"
    };

    vector<string> report = {
        "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"
    };

    int k = 2;

    solution(idList, report, k);

    return 0;
}