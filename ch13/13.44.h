#ifndef EX13_44
#define EX13_44

#include <memory>
#include <string>

class String
{
public:
    String() : elements(nullptr), end(nullptr) {}
    String(const char *s);
    ~String();
    String(String &);
    String(String &&);

    String &operator=(String &&);
    String &operator=(String &);

    char *c_str() { return elements; };

    size_t size()
    {
        return end - elements;
    }

private:
    std::allocator<char> alloc;
    char *elements;
    char *end;

private:
    void range_initializer(const char *, const char *);
    void free();
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
};

#endif