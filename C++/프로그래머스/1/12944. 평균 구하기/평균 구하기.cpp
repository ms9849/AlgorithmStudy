#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int iSize = arr.size();
    
    for(int i=0; i<iSize; ++i)
    {
        answer += arr[i];
    }
    
    return answer / iSize;
}