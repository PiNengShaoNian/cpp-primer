#include "12.27.h"

using namespace std;

QueryResult::QueryResult(TextQuery &tq) : counts(tq.counts), occurLines(tq.occurLines), lines(tq.lines){};

string &QueryResult::queryResult(string &s, string &word)
{
    s += word + " occurs ";
    int count = 0;
    auto ret = counts->find(word);
    if (ret != counts->end())
    {
        count = ret->second;
    }

    s += to_string(count) + " times\n";

    auto lineIndexes = occurLines->find(word);

    if (lineIndexes != occurLines->end())
    {
        for (auto &line : lineIndexes->second)
        {
            s += "line " + to_string(line) + ": " + lines->at(line) + "\n";
        }
    }

    return s;
}

TextQuery::TextQuery(ifstream &in) : lines(make_shared<vector<string>>()), counts(make_shared<map<string, unsigned>>()), occurLines(make_shared<map<string, set<int>>>())
{
    string line;
    unsigned lineIndex = 0;
    while (getline(in, line))
    {
        lines->push_back(line);
        istringstream ss(line);

        string word;

        while (ss >> word)
        {
            (*counts)[word]++;
            (*occurLines)[word].insert(lineIndex);
        }

        ++lineIndex;
    }
};

string TextQuery::query(string &text)
{
    QueryResult qr(*this);
    string result;
    return qr.queryResult(result, text);
}

int main()
{
    ifstream in("text.txt");

    TextQuery tq(in);

    string word = "aaa";
    cout << tq.query(word) << endl;

    in.close();
}