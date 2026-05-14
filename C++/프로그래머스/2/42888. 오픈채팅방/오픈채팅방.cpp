#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

map<string, string> mapUserNames = {};

vector<string> Change_NickName(vector<string>& Records)
{
	vector<string> ChangedRecords = {};
	enum class PARSE_TYPE { ACTION, UID, NICKNAME };

	for (auto& iter : Records)
	{
		PARSE_TYPE eCurrentType = PARSE_TYPE::ACTION;
		string strAction = {};
		string strUID = {};
		string strNickName = {};

		for (int i = 0; i < iter.length(); ++i)
		{
			//Parse Type 변경
			if (iter[i] == ' ')
			{
				switch (eCurrentType)
				{
				case PARSE_TYPE::ACTION:
					eCurrentType = PARSE_TYPE::UID;
					break;
				case PARSE_TYPE::UID:
					eCurrentType = PARSE_TYPE::NICKNAME;
					break;
				default:
					break;
				}

				continue;
			}

			//Parse Logic
			switch (eCurrentType)
			{
			case PARSE_TYPE::ACTION:
				strAction += iter[i];
				break;

			case PARSE_TYPE::UID:
				strUID += iter[i];
				break;

			case PARSE_TYPE::NICKNAME:
				strNickName += iter[i];
				break;
			default:
				break;
			}
		}

		if (mapUserNames[strUID] != strNickName)
			strNickName = mapUserNames[strUID];

		if (strAction == "Enter")
		{
			ChangedRecords.push_back(strNickName + "님이 들어왔습니다.");
		}
		else if (strAction == "Leave")
		{
			ChangedRecords.push_back(strNickName + "님이 나갔습니다.");
		}
	}

	return ChangedRecords;
}

void Parse_Data(vector<string>& Records)
{
	enum class PARSE_TYPE { ACTION, UID, NICKNAME };

	for (auto& iter : Records)
	{
		string strAction = {};
		string strUID = {};
		string strNickName = {};
		PARSE_TYPE eCurrentType = PARSE_TYPE::ACTION;

		for (int i = 0; i < iter.length(); ++i)
		{

			//Parse Type 변경
			if (iter[i] == ' ')
			{
				switch (eCurrentType)
				{
				case PARSE_TYPE::ACTION:
					eCurrentType = PARSE_TYPE::UID;
					break;
				case PARSE_TYPE::UID:
					eCurrentType = PARSE_TYPE::NICKNAME;
					break;
				default:
					break;
				}

				continue;
			}

			//Parse Logic
			switch (eCurrentType)
			{
			case PARSE_TYPE::ACTION:
				strAction += iter[i];
				break;

			case PARSE_TYPE::UID:
				strUID += iter[i];
				break;

			case PARSE_TYPE::NICKNAME:
				strNickName += iter[i];
				break;
			default:
				break;
			}
		}
		//파싱이 끝났다면, 데이터에 따라 적절하게 처리해야지..

		if (strAction == "Enter")
		{
			//만약 비어있다면, emplace로 채워주자.
			if (mapUserNames.find(strUID) == mapUserNames.end())
				mapUserNames.emplace(strUID, strNickName);
			//그렇지 않다면 변경해주자.
			else
				mapUserNames[strUID] = strNickName;
		}
		else if (strAction == "Change")
		{
			mapUserNames[strUID] = strNickName;
		}
	}
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	Parse_Data(record);

	answer = Change_NickName(record);

	return answer;
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });

	return 0;
}