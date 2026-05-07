#include <iostream>
#include <vector>
using namespace std;

// 첫 원소를 고르고, 배열의 사이즈가 홀수일 때. 맨 마지막 원소는 제외.
// 첫 원소를 고르고, 배열의 사이즈가 짝수일 때.
// 첫 원소를 고르지 않고 배열의 사이즈가 홀수일 때. -> 상관 없음
// 첫 원소를 고르지 않고 배열의 사이즈가 짝수일 때.

// 어쨌든 2칸마다 하나씩 떼어내야 잘 되는건데..

//2차원 정보 -> 0일땐 첫 인덱스 안씀.
// 1일땐 첫 인덱스 씀.
int iDp[100001][2] = {};

int solution(vector<int> sticker)
{
	//첫 원소를 고르는 경우는 배열의 사이즈가 홀수냐, 짝수냐에 따라 계산됨.
	//홀과 짝의 합이 가능..
	//2칸 이상은 안떨어지겠..지 뭐.

	if (sticker.size() == 1)
		return sticker[0];

	int iAnswer = 0;
	int iDp[100001] = {};

	iDp[0] = sticker[0];
	iDp[1] = sticker[0];

	for (int i = 2; i < sticker.size()-1; ++i)
		iDp[i] = max(iDp[i - 1], iDp[i - 2] + sticker[i]);

	iAnswer = iDp[sticker.size() - 2];

	int iDpTwo[100001] = {};

	iDpTwo[0] = 0;
	iDpTwo[1] = sticker[1];

	for (int i = 2; i < sticker.size(); ++i)
		iDpTwo[i] = max(iDpTwo[i - 1], iDpTwo[i - 2] + sticker[i]);

	iAnswer = max(iAnswer, iDpTwo[sticker.size()-1]);

	return iAnswer;
}