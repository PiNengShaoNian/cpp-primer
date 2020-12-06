int main()
{
    const int v1 = 10;
    int v2 = v1;

    int *p1 = &v2;
    const int *p2 = &v1;

    p2 = p1;

    int null = 0, *p = &null;
}