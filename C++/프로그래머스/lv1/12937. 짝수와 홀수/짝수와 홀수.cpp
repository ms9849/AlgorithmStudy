#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    if(num == 0)
        return string("Even");
    
    if(num%2 == 1)
        return string("Odd");
    else if(num%2 == 0)
        return string("Even");
    else
        return string("Odd");
}