#ifndef QUERY_H
#define QUERY_H

#include <iostream>

#include "text-query.h"

class Query;

class Query_base {
    friend class Query;

   protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

   private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

class WordQuery : public Query_base {
    friend class Query;

    WordQuery(const std::string &s) : query_word(s) {
        std::cout << "WordQuery::WordQuery(" + s + ")\n";
    };

    QueryResult eval(const TextQuery &t) const override;

    std::string rep() const override {
        std::cout << "WordQuery::rep()\n";
        return query_word;
    }

    std::string query_word;
};

class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query);
    friend Query operator&(const Query &, const Query &);

   public:
    Query(const std::string &s) : q(new WordQuery(s)){};

    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const {
        std::cout << "Query::rep() \n";
        return q->rep();
    }

   private:
    Query(std::shared_ptr<Query_base> query) : q(query) {}
    std::shared_ptr<Query_base> q;
};

#endif