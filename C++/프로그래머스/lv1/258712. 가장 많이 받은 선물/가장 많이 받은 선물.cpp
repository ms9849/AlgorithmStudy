#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    // friends를 파싱할 이유는 없고.
    // 선물을 준 사람, 선물을 받은 사람

    map<pair<string, string>, int> FriendsPair = {};
    map<string, int> NextMonthCount = {}; 
    map<string, int> GiftPower = {};

    for (int i = 0; i < friends.size(); ++i)
    {
        NextMonthCount.emplace(friends[i], 0);
        GiftPower.emplace(friends[i], 0);

        for (int j = 0; j < friends.size(); ++j)
        {
            if(i != j)
                FriendsPair.emplace(make_pair(friends[i], friends[j]), 0);
        }
    }

    for (int i = 0; i < gifts.size(); ++i)
    {
        for (int j = 0; j < gifts[i].size(); ++j)
        {
            if (gifts[i][j] == ' ')
            {
                string strFrom = gifts[i].substr(0, j);
                string strTo = gifts[i].substr(j + 1, gifts[i].size());

                FriendsPair[make_pair(strFrom, strTo)] += 1;

                GiftPower[strFrom] += 1;
                GiftPower[strTo] -= 1;
            }
        }
    }

    for (auto& iter : NextMonthCount)
    {
        for (auto& Pair : FriendsPair)
        {
            if (iter.first == Pair.first.first)
            {
                int iPresentFrom = FriendsPair[make_pair(iter.first, Pair.first.second)];
                int iPresentTo = FriendsPair[make_pair(Pair.first.second, iter.first)];

                if (iPresentFrom > iPresentTo)
                {
                    NextMonthCount[iter.first] += 1;
                }
                else if(iPresentFrom == iPresentTo &&
                    (GiftPower[iter.first] > GiftPower[Pair.first.second]))
                {
                    NextMonthCount[iter.first] += 1;
                }
            }
        }
    }

    int iMax = 0;
    for (auto& iter : NextMonthCount)
    {
        if (iter.second > iMax)
        {
            iMax = iter.second;
        }
    }

    return iMax;
}

/*
* 친구는 최대 50명.
* 2중 for문 돌려봐야 2500번이니까..
* 선물 지수 계산은 단순 반복문으로 가능할 것.
*/

int main(void* pArg)
{
    vector<string> friends = {"muzi", "ryan", "frodo", "neo"};
    vector<string> gifts = { "muzi frodo", "muzi frodo", "ryan muzi", 
        "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };

    solution(friends, gifts);

    return 0;
}