#ifndef EX_13_34
#define EX_13_34

#include <string>
#include <set>

using namespace std;

class Folder
{
public:
    remove(Message &);
    add(Message &);
};

class Message
{

public:
    Message(const string &s = "") : contents(s){};

    Message(Message &m);
    ~Message();
    Message &operator=(const Message &);
    void save(Folder &);
    void remove(Folder &);

private:
    string contents;
    set<Folder *> folders;
    void removeFromFolders(Message &m);
    void addToFolders(const Message &m);
}
#endif