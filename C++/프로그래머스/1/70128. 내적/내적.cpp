#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int iSize  = a.size();
    int iAnswer = 0;
    
    for(int i=0; i<iSize; ++i)
    {
        iAnswer += a[i] * b[i];
    }
    
    return iAnswer;
}