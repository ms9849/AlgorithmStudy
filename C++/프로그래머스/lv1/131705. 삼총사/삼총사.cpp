#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    for(int i=0; i<number.size(); ++i)
    {
        for(int j=i+1; j<number.size(); ++j)
        {
            for(int k=j+1; k<number.size(); ++k)
            {
                int iSum = number[i] + number[j] + number[k];
                
                if(iSum == 0)
                    answer++;
            }
        }
    }
    
    return answer;
}