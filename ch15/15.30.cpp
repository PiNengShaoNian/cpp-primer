#include <string>
#include <set>
#include <memory>

using namespace std;

class Quote
{

public:
    Quote(string no, double price) : bookNo(no), price(price){};

    virtual double net_price(size_t n) const
    {
        return n * price;
    }

    string sn()
    {
        return bookNo;
    }

    virtual Quote *clone() const &
    {
        return new Quote(*this);
    }

    virtual Quote *clone() const &&
    {
        return new Quote(std::move(*this));
    }

protected:
    double price;

private:
    string bookNo;
};

class BulkQuote : public Quote
{
public:
    BulkQuote(string no, double price, double discount, size_t minQuantity) : Quote(no, price), discount(discount), minQuantity(minQuantity){};

    virtual BulkQuote *clone() const & override
    {
        return new BulkQuote(*this);
    }

    virtual BulkQuote *clone() const && override
    {
        return new BulkQuote(std::move(*this));
    }

    double net_price(size_t n) const override
    {
        if (n >= minQuantity)
            return n * price * (1 - discount);

        return n * price;
    }

private:
    double discount;
    size_t minQuantity;
};

class Basket
{
public:
    void addItem(Quote &quote)
    {
        items.insert(shared_ptr<Quote>(quote.clone()));
    }

    void addItem(Quote &&quote)
    {
        items.insert(shared_ptr<Quote>(std::move(quote).clone()));
    }

private:
    static bool compare(const shared_ptr<Quote> &q1, const shared_ptr<Quote> &q2)
    {
        return q1->sn() < q2->sn();
    }
    multiset<shared_ptr<Quote>, decltype(compare) *> items{compare};
};

int main()
{
    Basket bs;

    bs.addItem(Quote("sdfsd", 3));
    bs.addItem(Quote("sdfsd", 3));
    bs.addItem(Quote("sdfsd", 3));
    bs.addItem(Quote("sdfsd", 3));
    bs.addItem(Quote("sdfsd", 3));
    bs.addItem(Quote("sdfsd", 3));
}