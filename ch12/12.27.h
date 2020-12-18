#ifndef EX12_27
#define EX12_27

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <memory>

using namespace std;

class TextQuery;

class QueryResult
{

public:
	QueryResult(TextQuery& tq);

	string& queryResult(string& s, string& word);

private:
	shared_ptr<map<string, unsigned>> counts;
	shared_ptr<map<string, set<int>>> occurLines;
	shared_ptr<vector<string>> lines;
};

class TextQuery
{
public:
	friend class QueryResult;
	TextQuery(ifstream& in);

	string query(string& text);

private:
	shared_ptr<map<string, unsigned>> counts;
	shared_ptr<map<string, set<int>>> occurLines;
	shared_ptr<vector<string>> lines;
};

#endif