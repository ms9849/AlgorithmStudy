#include <string>
#include <vector>
#include <map>
using namespace std;


int solution(vector<vector<string>> clothes) {
	int answer = 0;

	map<string, int> mapClothes = {};

	for (auto& Cloth : clothes)
	{
		mapClothes[Cloth[1]]++;
	}

	int iSum = 1;
	for (auto& iter : mapClothes)
	{
		iSum *= (iter.second + 1);
	}
	iSum -= 1;

	return iSum;
}