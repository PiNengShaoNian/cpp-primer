#ifndef SCREEN
#define SCREEN

#include <iostream>
#include <string>

template <int W, int H>
class Screen;

template <int W, int H>
std::istream& operator>>(std::istream&, Screen<W, H>& s);

template <int W, int H>
std::ostream& operator<<(std::ostream&, Screen<W, H>& s);

template <int W, int H>
class Screen {
    friend std::istream& operator>><W, H>(std::istream&, Screen<W, H>&);
    friend std::ostream& operator<<<W, H>(std::ostream&, Screen<W, H>&);

   public:
    Screen() : contents(W * H, ' '){};
    Screen(char c) : contents(W * H, c){};

   private:
    std::string contents;
};

template <int W, int H>
std::istream& operator>>(std::istream& in, Screen<W, H>& s) {
    std::string str;
    in >> str;
    s.contents = str.substr(W * H);

    return in;
}

template <int W, int H>
std::ostream& operator<<(std::ostream& os, Screen<W, H>& s) {
    os << s.contents;
    return os;
}

#endif