#include <string>
#include <vector>

using namespace std;

int iGraph[51][51] = {};
int iVisited[51] = {};
int ianswer = 999;

void DFS(int iCurNode, int iTargetNode, int iDepth, int iMaxIdx)
{
	if (iCurNode == iTargetNode)
	{
		if (iDepth < ianswer)
		{
			ianswer = iDepth;
		}

		return;
	}

	for (int i = 0; i < iMaxIdx; ++i)
	{
		if (i != iCurNode && iVisited[i] == 0 &&
			iGraph[iCurNode][i] == 1)
		{
			iVisited[i] = 1;

			DFS(i, iTargetNode, iDepth + 1, iMaxIdx);

			iVisited[i] = 0;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	int iTargetIdx = -1;
	int iCount = 0;
	int iLength = begin.size();

	//begin까지 포함하여 문자열 제작.
	vector<string> WORDS = {};
	WORDS.push_back(begin);

	for (auto& iter : words)
	{
		WORDS.push_back(iter);
	}
	
	//타겟, 도착점이 존재하는가?
	for (auto& iter : WORDS)
	{
		if (iter == target)
			iTargetIdx = iCount;

		iCount++;
	}

	if (iTargetIdx == -1)
		return 0;

	//그래프 만들어줘야지
	int iIdx = 0;
	for (auto& strStart : WORDS)
	{
		int iVisitIdx = 0;
		
		for (auto& strVisit : WORDS)
		{
			int iDiffCount = 0;

			for (int i = 0; i < iLength; ++i)
			{
				if (strVisit[i] != strStart[i])
					iDiffCount++;
			}

			if (iDiffCount == 1)
				iGraph[iIdx][iVisitIdx] = 1;

			iVisitIdx++;
		}

		iIdx++;
	}

	iVisited[0] = 1;
	DFS(0, iTargetIdx, 0, WORDS.size());

	return ianswer;
}