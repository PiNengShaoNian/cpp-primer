int main()
{
    int a = 0, b = 0;

    decltype(a) c = 1;
    decltype((b)) d = b;

    return 0;
}