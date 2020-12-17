#include <string>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
    string &front() const
    {
        check(0, "Empty StrBlob");
        return data->at(0);
    }

    string &back()
    {
        check(0, "Empty StrBlob");
        return data->back();
    }

    size_type size() const
    {
        return data->size();
    }

    void pop_back()
    {
        check(0, "Empty StrBlob");

        return data->pop_back();
    }

private:
    shared_ptr<vector<string>> data;
    void check(size_type index, string const &msg) const
    {
        if (index >= data->size())
        {
            throw out_of_range(msg);
        }
    }
};

int main()
{
    StrBlob s1({"1", "2", "3"});

    StrBlob s2 = s1;

    s1.pop_back();

    cout << s2.size() << endl;
}