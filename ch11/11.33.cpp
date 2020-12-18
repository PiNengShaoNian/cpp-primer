#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

string wordTransform(string &phrase)
{
    istringstream in(phrase);
    map<string, string> trans_map = {
        {"k", "okay?"},
        {"y", "why"},
        {"r", "are"},
        {"u", "you"},
        {"pic", "picture"},
        {"thk", "thanks!"},
        {"18r", "later"}};
    vector<string> words;
    string word;
    string result;
    while (in >> word)
    {
        if (trans_map.count(word))
        {
            words.push_back(trans_map[word]);
        }
        else
        {
            words.push_back(word);
        }
    }

    for (auto &word : words)
    {
        result += word + " ";
    }

    return result;
}

int main()
{
    string str = "k thk 18r";
    cout << wordTransform(str) << endl;

    return 0;
}