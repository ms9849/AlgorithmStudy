#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


bool solution(vector<string> phone_book) {
	bool answer = true;
	map<string, bool> mapCache = {};

	sort(phone_book.begin(), phone_book.end(), [](string lhs, string rhs)->bool {
		return lhs.length() < rhs.length();
	});


	for (auto& iter : phone_book)
		mapCache[iter] = true;


	for (auto& str : phone_book)
	{
		string strTemp = {};
		for (int i = 0; i < str.length(); ++i)
		{
			strTemp += str[i];

			if (mapCache[strTemp] == true && strTemp != str)
				return false;
		}
	}

	return true;
}
