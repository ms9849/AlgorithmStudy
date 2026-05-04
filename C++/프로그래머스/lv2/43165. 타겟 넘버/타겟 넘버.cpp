#include <string>
#include <vector>

using namespace std;

int iNode[21] = {};
int iVisited[21] = {};
int iMax = {};
int iTarget = {};
int iResult = {};
void Recursion(int iCurNum, int iCurNode)
{
    if (iCurNode == iMax)
    {
        if (iCurNum == iTarget)
            iResult++;
        
        return;
    }

    Recursion(iCurNum + iNode[iCurNode], iCurNode + 1);
    Recursion(iCurNum - iNode[iCurNode], iCurNode + 1);
}

int solution(vector<int> numbers, int target) {

    iMax = numbers.size();
    iTarget = target;

    for (int i = 0; i < iMax; ++i)
    {
        iNode[i] = numbers[i];
    }

    Recursion(0, 0);

    return iResult;
}
