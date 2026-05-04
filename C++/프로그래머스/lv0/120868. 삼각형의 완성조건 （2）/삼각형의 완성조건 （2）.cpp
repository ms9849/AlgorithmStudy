#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sides) {
	int answer = 0;

	sort(sides.begin(), sides.end());

	int iLongest = sides[0] + sides[1] - 1;

	while (iLongest > sides[1])
	{
		answer++;
		iLongest--;
	}

	iLongest = sides[1];

	int iTemp = sides[1] - sides[0] + 1; 
	while (iLongest >= iTemp)
	{
		iTemp++;
		answer++;
	}

	return answer;
}