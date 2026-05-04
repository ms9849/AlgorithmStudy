#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
	map<string, int> str1Dict = {};
	map<string, int> str2Dict = {};

	for (int i = 0; i < str1.size() - 1; ++i)
	{
		if (!((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z')))
			continue;
		if (!((str1[i + 1] >= 'a' && str1[i + 1] <= 'z') || (str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')))
			continue;

		string strTemp = "";

		if (str1[i] >= 'A' && str1[i] <= 'Z')
			strTemp += str1[i] + 32;
		else
			strTemp += str1[i];

		if (str1[i + 1] >= 'A' && str1[i + 1] <= 'Z')
			strTemp += str1[i + 1] + 32;
		else
			strTemp += str1[i + 1];

		str1Dict[strTemp]++;
	}

	for (int i = 0; i < str2.size() - 1; ++i)
	{
		if (!((str2[i] >= 'a' && str2[i] <= 'z') || (str2[i] >= 'A' && str2[i] <= 'Z')))
			continue;
		if (!((str2[i + 1] >= 'a' && str2[i + 1] <= 'z') || (str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')))
			continue;

		string strTemp = "";

		if (str2[i] >= 'A' && str2[i] <= 'Z')
			strTemp += str2[i] + 32;
		else
			strTemp += str2[i];
		if (str2[i + 1] >= 'A' && str2[i + 1] <= 'Z')
			strTemp += str2[i + 1] + 32;
		else
			strTemp += str2[i + 1];

		str2Dict[strTemp]++;
	}

	//합집합은 둘 중 크기가 큰 것.
	//교집합은 둘 중 크기가 작은 것.

	int iInterSect{}, iUnion{};

	for (char i = 'a'; i <= 'z'; ++i)
	{
		string strTemp = "";
		strTemp += i;

		for (char j = 'a'; j <= 'z'; ++j)
		{
			string strKey = strTemp + j;

			iUnion += max(str1Dict[strKey], str2Dict[strKey]);
			iInterSect += min(str1Dict[strKey], str2Dict[strKey]);
		}

	}
	if (iUnion == 0)
		return 65536;
	else
		return (int)((iInterSect / (float)(iUnion)) * 65536);
}
