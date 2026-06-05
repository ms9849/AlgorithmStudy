#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> vecClothes) {
    int iAnswer = 1;
    unordered_map<string, int> mapClothes = {};

    for(auto& Cloth : vecClothes)
    {
        //yellow_hat, headgear라면 headgear++.
        mapClothes[Cloth[1]]++;
    }
    
    for(auto& iter : mapClothes)
    {
        iAnswer *= (iter.second + 1);
    }
    iAnswer--;
    
    return iAnswer;
}