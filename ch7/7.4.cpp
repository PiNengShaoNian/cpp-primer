#include <string>
#include <iostream>

using namespace std;

struct Person
{
    string name;
    string phone;
    string address;

    friend Person add(Person &p1, Person &p2);

private:
    char age;

public:
    Person() = default;

    Person(string &name, string &phone, string &address, char age) : name(name), phone(phone), address(address), age(age) {}

    Person(istream &in)
    {
        read(in, *this);
    }

    // string name()
    // {
    //     return name;
    // }

    istream &read(istream &in, Person &p)
    {
        in >> p.name >> p.phone >> p.address >> p.age;

        return in;
    }

    string phone1()
    {
        return phone;
    }

    // string address()
    // {
    //     return address;
    // }

    // char age()
    // {
    //     return age;
    // }

    void print(ostream &out)
    {
        out << "name: " << name << "address: " << address;
    }
};

Person add(Person &p1, Person &p2)
{
    Person res = p1;

    res.age += p2.age;

    return res;
}
int main()
{

    Person *p = new Person(cin);

    p->print(cout);

    return 0;
}
