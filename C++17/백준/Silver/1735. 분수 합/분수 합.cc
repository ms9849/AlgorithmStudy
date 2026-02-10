#include <iostream>

using namespace std;

int main(void* pArg)
{
	int iSourSon{}, iSourParent{};
	int iDestSon{}, iDestParent{};
	int iMaxDiv{1};

	cin >> iSourSon >> iSourParent;
	cin >> iDestSon >> iDestParent;

	// 두 수의 최소 공배수 구하기
	// -> axb / 최대공약수
	// 공식으로 구해낼 수 있다.

	int iCount = { 2 };
	while (iCount <= (iSourParent > iDestParent ? iDestParent : iSourParent))
	{
		if (iSourParent % iCount == 0 && iDestParent % iCount == 0)
			iMaxDiv = iCount;

		iCount++;
	}

	int iResultSon = iSourSon * iDestParent / iMaxDiv + iDestSon * iSourParent / iMaxDiv;
	int iResultParent = (iSourParent * iDestParent / iMaxDiv);

	
	iCount = { 2 };
	iMaxDiv = { 1 }; 
	while (iCount <= (iResultSon > iResultParent ? iResultParent : iResultSon))
	{
		if (iResultSon % iCount == 0 && iResultParent % iCount == 0)
			iMaxDiv = iCount;

		iCount++;
	}

	cout << iResultSon / iMaxDiv << " " << iResultParent / iMaxDiv;



	return 0;
}