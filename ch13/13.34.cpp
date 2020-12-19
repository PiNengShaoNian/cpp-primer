#include "13.34.h"

Message::Message(Message &m) : contents(m.contents), folders(m.folders)
{
    addToFolders(m);
}

Message::~Message()
{
    removeFromFolders(*this);
}

Message &Message::operator=(const Message &m)
{
    removeFromFolders(*this);

    contents = m.contents;
    folders = m.folders;
    addToFolders(m);

    return *this;
}

void Message::save(Folder &f)
{
    f.add(*this);
    folders.insert(&f);
}

void Message::remove(Folder &f)
{
    f.remove(*this);
    folders.erase(&f);
}

void Message::addToFolders(const Message &m)
{
    for (auto f : m.folders)
    {
        f->add(*this);
    }
}

void Message::removeFromFolders(Message &m)
{
    for (auto f : m.folders)
    {
        f->remove(*this);
    }
}