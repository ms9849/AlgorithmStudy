#include <iostream>

using namespace std;

bool Check_Pel(string strInput)
{
	int iLow = 0;
	int iHigh = strInput.size() - 1;

	while (iLow <= iHigh)
	{
		//1번까지는 문자열을 당겨도됨.
		if (strInput[iLow] != strInput[iHigh])
		{
			return false;
		}

		iLow++;
		iHigh--;
	}

	return true;
}

int main(void* pArg)
{
	int iN;
	cin >> iN;

	while (iN > 0)
	{
		string strInput;
		cin >> strInput;

		int iLow = 0;
		int iHigh = strInput.size() - 1;

		bool isJustString = { false };
		bool isFakePalin = { false };
		bool isTruePalin = { false }; 

		while(iLow <= iHigh)
		{
			//1번까지는 문자열을 당겨도됨.
			if (strInput[iLow] != strInput[iHigh])
			{
				bool ResultA{ true }, ResultB{ true };
				string tempA = strInput.substr(0, iLow) + strInput.substr(iLow + 1);
				string tempB = strInput.substr(0, iHigh) + strInput.substr(iHigh + 1);

				ResultA = Check_Pel(tempA);
				ResultB = Check_Pel(tempB);

				if (false == ResultA && false == ResultB)
				{
					isJustString = true;
					break;
				}
				else
				{
					isFakePalin = true;
					break;
				}

			}

			iLow++;
			iHigh--;
		}

		if (true == isJustString)
			cout << 2 << "\n";

		else if (true == isFakePalin)
			cout << 1 << "\n";

		else
			cout << 0 << "\n";

		iN--;
	}
}