#ifndef BLOB_H
#define BLOB_H

#include <memory>
#include <string>
#include <vector>

template <typename T>
class Blob {
   public:
    Blob() : data(std::make_shared<std::vector<T>>()){};
    Blob(std::initializer_list<T> li)
        : data(std::make_shared<std::vector<T>>(li)){};

    T& operator[](size_t i) {
        check(i, "out of range");
        return (*data)[i];
    }

    void push_back(T& v) { data->push_back(v); }

    T& back() {
        check(0);
        return data->back();
    }

   private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_t i, const std::string& msg) {
        if (i >= data->size()) {
            throw std::out_of_range(msg);
        }
    };
};

#endif