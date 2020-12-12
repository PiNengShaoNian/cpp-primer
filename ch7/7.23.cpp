#include <string>
#include <vector>

using namespace std;

class Screen
{
    friend class WindowManager;

    friend void WindowManager::clear(ScreenIndex);

public:
    typedef string::size_type pos;
    Screen() = default;

    Screen(pos width, pos height, char c) : width(width), height(height), contents(width * height, c) {}

    char get()
    {
        return contents[cursor];
    }

    char get(pos row, pos column)
    {
        return contents[row * width + column];
    }

    Screen &move(pos row, pos column)
    {
        cursor = row * width + column;
        return *this;
    }

    const Screen &display(ostream &out) const
    {
        out << contents;
        return *this;
    }

private:
    pos width;
    pos height;
    pos cursor;
    string contents;
};

class WindowManager
{
    using ScreenIndex = vector<Screen>::size_type;

public:
    void clear(ScreenIndex index)
    {
        Screen &s = screens[index];
        s.contents = string(s.width * s.height, ' ');
    }

private:
    vector<Screen> screens{Screen(10, 10, ' ')};
};