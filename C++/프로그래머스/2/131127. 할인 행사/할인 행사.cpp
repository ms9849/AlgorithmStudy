#include <string>
#include <vector>
#include <map>
using namespace std;

/*
정현이가 원하는 할인 품목 N(1~10)개가,
xyz에서 제공하는 할인 품목 연속 N일과 일치해야 함.

일일이 for문으로 체크? -> 가능은 하지않나? 근데 이건 문제의 의도가 아닌 것 같아 안될 것 같음.

1. 각 인덱스마다 map으로 저장해서 갯수 비교? -> 이거같은데.
unordered_map으로 사용하면 정렬 비용 없어서 10만번 그냥 쭉 굴려도 될 것 같음.

-> want의 목록을 map으로 만들어놓고,
-> xyz 마트의 할인 목록을 받아서 처리.
-> 일반 2중 for문이랑 비교했을 때, 문자열 비교 비용이 사라지고, map 복사 비용이 생김.

*/

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int iWantSize = want.size();
    int iSize = discount.size();
    map<string,int> wants = {};
    
    //map 만들기.
    for(int i=0; i<iWantSize; ++i)
    {
        wants.emplace(want[i], number[i]);   
    }
    
    //순회하며 비교
    /*
    0~13인덱스, 14개.
    */
    
    for(int i=0; i<= iSize - 10; ++i)
    {
        //복사.
        map<string,int> Copywants = wants;
        
        for(int j=i; j < i + 10; ++j)
        {
            //10일 체크하는거니까, 딱 들어맞긴 해야겠지?
            //그냥 뺴버려도 상관은 없어.
            Copywants[discount[j]]--;
        }

        //체크로직까진 맞아.
        bool isAnswer = true;
        for(auto& iter : Copywants)
        {
            if(iter.second != 0)
                isAnswer = false;
        }
        if(true == isAnswer)
            answer++;
    }
    
    return answer;
}