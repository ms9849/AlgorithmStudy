#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> Result = {};

	vector<int> FirstAnswer = { 1,2,3,4,5 };
	vector<int> SecondAnswer = { 2,1,2,3,2,4,2,5 };
	vector<int> ThridAnswer = { 3,3,1,1,2,2,4,4,5,5 };

	int iFirstCount{}, iSecondCount{}, iThirdCount{};

	int iCount = 0;
	for (auto& iter : answers)
	{
		if (answers[iCount] == FirstAnswer[iCount % FirstAnswer.size()])
			iFirstCount++;

		if (answers[iCount] == SecondAnswer[iCount % SecondAnswer.size()])
			iSecondCount++;

		if (answers[iCount] == ThridAnswer[iCount % ThridAnswer.size()])
			iThirdCount++;

		iCount++;
	}

	int iMax = -1;
	iMax = max(max(iFirstCount, iSecondCount), iThirdCount);

	if (iFirstCount == iMax)
		Result.push_back(1);

	if (iSecondCount == iMax)
		Result.push_back(2);

	if (iThirdCount == iMax)
		Result.push_back(3);

	return Result;
}