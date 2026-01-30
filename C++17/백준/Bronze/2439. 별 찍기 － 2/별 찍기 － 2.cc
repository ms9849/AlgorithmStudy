#include <iostream>

using namespace std;

int main(void* pArg)
{
	int iCount;
	cin >> iCount;

	for (int i = 0; i < iCount; ++i)
	{
		for (int j = i; j < iCount - 1; ++j)
		{
			cout << " ";
		}

		for (int k = 0; k < i + 1; ++k)
		{
			cout << "*";
		}

		cout << endl;
	}


	return 0;
}