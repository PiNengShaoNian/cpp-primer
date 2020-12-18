#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> &lengthGreateThan(vector<string> &words, vector<string> &result, int sz)
{
    for_each(words.begin(), words.end(), [sz, &result, &words](const string &s) {
        if (s.size() >= sz)
        {
            result.push_back(s);
        }
    });
    return result;
}