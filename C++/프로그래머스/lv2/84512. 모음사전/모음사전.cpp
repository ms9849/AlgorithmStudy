#include <string>
#include <vector>
#include <map>

using namespace std;

int iCount = 1;
vector<char> Alphabets = { 'A', 'E', 'I', 'O', 'U' };
map<string ,int> Words = {};

void Recursion(string strSour, int iDepth)
{
	if (iDepth >= 6)
		return;

	for (int i = 0; i < Alphabets.size(); ++i)
	{
		string Temp = strSour + Alphabets[i];

		Words.emplace(Temp, iCount++);
		Recursion(Temp, iDepth + 1);
	}
	
}

int solution(string word) {

	Recursion("", 1);

	return Words[word];
}
