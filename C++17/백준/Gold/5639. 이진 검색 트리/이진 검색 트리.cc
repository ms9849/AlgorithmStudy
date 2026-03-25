#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef struct TreeNode {
	int iData = {};
	TreeNode* pRight = {};
	TreeNode* pLeft = {};
	TreeNode* pParent = {};

	TreeNode(int iNum) { iData = iNum; }
} TNode;

void PostVisit(TNode* pNode)
{
	if(nullptr != pNode->pRight)
		PostVisit(pNode->pRight);
	if(nullptr != pNode->pLeft)
		PostVisit(pNode->pLeft);
	cout << pNode->iData << "\n";

	delete pNode;

	return;
}

int main(void* pArg)
{
	TNode* pRoot = {};
	TNode* pCurNode = {};

	int iNum = {};
	int iCurDepth = 0;
	int iCount = 0;

	while (cin >> iNum)
	{
		if (pRoot == nullptr)
		{
			pRoot = new TNode(iNum);
			iCount++;
		}
		else
		{
			pCurNode = pRoot;

			while (1)
			{
				//오른쪽 비어있고 데이터 더 작으면,
				if (pCurNode->pRight == nullptr &&
					iNum < pCurNode->iData)
				{
					pCurNode->pRight = new TNode(iNum);
					break;
				}
				//왼쪽 비어있고 데이터 더 크면,
				else if (pCurNode->pLeft == nullptr &&
					iNum > pCurNode->iData)
				{
					pCurNode->pLeft = new TNode(iNum);
					break;
				}
				else if (pCurNode->pRight != nullptr &&
					iNum < pCurNode->iData)
				{
					pCurNode = pCurNode->pRight;
				}
				else if (pCurNode->pLeft != nullptr &&
					iNum > pCurNode->iData)
				{
					pCurNode = pCurNode->pLeft;
				}
				
			}
		}

	}

	PostVisit(pRoot); 

	return 0;
}