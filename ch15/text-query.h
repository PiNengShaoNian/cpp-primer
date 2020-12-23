#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <fstream>
#include <map>
#include <memory>
#include <set>

#include "str-blob.h"

class QueryResult;

class TextQuery {
   public:
    typedef StrBlob::size_type line_no;

    TextQuery(std::ifstream &fin);

    QueryResult query(const std::string &) const;

   private:
    StrBlob file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wordMap;
};

class QueryResult {
    friend std::ostream &operator<<(std::ostream &, const QueryResult &);

   public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> sp_l, StrBlob f)
        : sought(s), sp_lines(sp_l), file(f){};

    const StrBlob &get_file() const { return file; };

    std::set<TextQuery::line_no>::iterator begin() { return sp_lines->begin(); }

    std::set<TextQuery::line_no>::iterator end() { return sp_lines->end(); }

   private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> sp_lines;
    StrBlob file;
};

std::ostream &print(std::ostream &, const QueryResult &);

#endif