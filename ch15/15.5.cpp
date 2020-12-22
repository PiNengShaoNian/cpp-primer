#include <string>
#include <iostream>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(double price, string bookNo) : price(price), bookNo(bookNo){};

    string sn()
    {
        return bookNo;
    }

    virtual string debug()
    {
        return "Quote";
    }

    virtual double net_price(unsigned n) const
    {
        return n * price;
    };

protected:
    double price;

private:
    string bookNo;
};

class BulkQuote : public Quote
{
public:
    BulkQuote(string bookNo, double price, double discount, unsigned minQuantity) : Quote(price, bookNo), discount(discount), minQuantity(minQuantity){};

    double net_price(unsigned n) const override
    {
        if (n > minQuantity)
            return n * (1 - discount) * price;

        return n * price;
    }

    string debug() override
    {
        return "BulkQuote" + Quote::debug();
    }

private:
    double discount;
    unsigned minQuantity;
};

int main()
{
    BulkQuote b("sd", 1, 2, 3);

    cout << b.debug() << endl;
}