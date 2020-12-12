#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PersonInfo
{
public:
    string name;
    vector<string> phones;
};

int main()
{
    string filename;

    cout << "请输入文件名" << endl;

    cin >> filename;

    ifstream in(filename);

    if (!in)
    {
        cout << "打开文件失败";
        return 0;
    }

    vector<PersonInfo> peoples;
    string line;
    while (getline(cin, line))
    {
        istringstream ss(line);

        PersonInfo p;

        ss >> p.name;
        string phone;
        while (ss >> phone)
        {
            p.phones.push_back(phone);
        }

        peoples.push_back(p);
    }

    return 0;
}