#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(void* pArg)
{
	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	cout << iA + iB - iC << "\n";
	cout << stoi(to_string(iA) + to_string(iB)) - iC << "\n";

	return 0;
}