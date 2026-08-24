#include <string>
#include <vector>

using namespace std;
/*
1. 한 글자만 다르다면 방문 가능한 노드로 취급하고.
2. 노드는 최대 50개. DFS로만 방문이 가능한데, 어차피 한글자 다른 부분만 방문 가능하니까.. 2^50은 안될 것 같은데? BFS로 가게되면 중간단계 visited 체크가 불가능해서 무한루프 가능성이 아주 큼.
*/


int iVisited[51] = {};

void DFS(const string& CurNode, const string& target, const vector<string>& words, int iLength, int iDepth, int& answer)
{
    if(CurNode == target && (answer == -1 || answer > iDepth))
    {
        answer = iDepth;
        //도착했다면 여기서 더 탐색할 이유가 없음
        return;
    }
    
    for(int j=0; j< words.size(); ++j)
    {
        int iDiffCount = 0;
        for(int i=0; i<iLength; ++i)
        {
            if(CurNode[i] != words[j][i])
                iDiffCount++;
        }
        //방문할 수 있는 노드라면
        if(iDiffCount == 1 && iVisited[j] != 1) 
        {
            iVisited[j] = 1;
            DFS(words[j], target, words, iLength, iDepth + 1, answer);
            //순회했다가 재방문하는거 고려.
            iVisited[j] = 0;
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = -1;
    
    DFS(begin, target, words, target.length(), 0, answer);
    
    
    if(answer == -1)
        return 0;
    
    return answer;
}