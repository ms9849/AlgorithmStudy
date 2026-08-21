#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int iLength = tangerine.size();
    
    unordered_map<int, int> map ={};
    vector<pair<int,int>> vecNums = {};
    
    for(int i=0; i<iLength; ++i)
    {
        //이렇게 추가하면.. 자동으로 추가되긴 하니까.
        map[tangerine[i]]++;
    }
    
    for(auto& iter : map)
    {
        //(크기, 그 크기가 몇번 나왔는지)
        vecNums.push_back(make_pair(iter.first, iter.second));   
    }
    
    //많이 나온 순대로 정렬.
    sort(vecNums.begin(), vecNums.end(), [](pair<int,int> lhs, pair<int,int> rhs)->bool {
       return lhs.second > rhs.second;
    });
    
    iLength = vecNums.size();
    
    for(int i=0; i<iLength; ++i)
    {
        k-= vecNums[i].second;
        answer++;
        
        if(k <= 0)
            break;
    }
    
    return answer;
}