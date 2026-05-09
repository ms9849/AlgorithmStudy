#include <string>
#include <vector>

using namespace std;

enum class CHAR_TYPE { SMALL, LARGE, BLANK };

string solution(string s, int n) {
    string answer = "";
    CHAR_TYPE eType = {};

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            eType = CHAR_TYPE::SMALL;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            eType = CHAR_TYPE::LARGE;
        else
            eType = CHAR_TYPE::BLANK;

        for (int j = 0; j < n; ++j)
        {
            if (eType == CHAR_TYPE::SMALL || eType == CHAR_TYPE::LARGE)
                s[i]++;

            switch (eType)
            {
            case CHAR_TYPE::SMALL:
                if (s[i] > 'z')
                    s[i] = 'a';
                break;
            case CHAR_TYPE::LARGE:
                if (s[i] > 'Z')
                    s[i] = 'A';
                break;
            default:
                break;
            }
        }
    }

    return s;
}