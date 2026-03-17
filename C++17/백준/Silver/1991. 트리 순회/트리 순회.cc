#include <iostream>
#include <vector>

using namespace std;

pair<char, char> vecTree[27] = {};
int iVisited[27] = {};

void Forward_Search(int iCurrentNode)
{
	char cLeft, cRight;

	cLeft = vecTree[iCurrentNode].first;
	cRight = vecTree[iCurrentNode].second;
	

	cout << char('A' + iCurrentNode);

	if (cLeft != '.')
		Forward_Search(cLeft - 'A');
	if(cRight != '.')
		Forward_Search(cRight - 'A');
}

void Middle_Search(int iCurrentNode)
{
	char cLeft, cRight;

	cLeft = vecTree[iCurrentNode].first;
	cRight = vecTree[iCurrentNode].second;

	if (cLeft != '.')
		Middle_Search(cLeft - 'A');
	
	cout << char('A' + iCurrentNode);

	if (cRight != '.')
		Middle_Search(cRight - 'A');
}

void Backward_Search(int iCurrentNode)
{
	char cLeft, cRight;

	cLeft = vecTree[iCurrentNode].first;
	cRight = vecTree[iCurrentNode].second;

	if (cLeft != '.')
		Backward_Search(cLeft - 'A');
	if (cRight != '.')
		Backward_Search(cRight - 'A');
	cout << char('A' + iCurrentNode);
}

int main(void* pArg)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		char cStart, cLeft, cRight;

		cin >> cStart >> cLeft >> cRight;

		vecTree[cStart - 'A'] = make_pair(cLeft, cRight);
	}

	Forward_Search(0);
	cout << "\n";
	Middle_Search(0);
	cout << "\n";
	Backward_Search(0);

	return 0;
}