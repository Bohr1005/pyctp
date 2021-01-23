#ifndef UTILS_H
#define UTILS_H

#include <locale>
#include <string>
#include <codecvt>
#include "pybind11/pybind11.h"
#include <vector>

namespace py = pybind11;

template <size_t size>
using string_literal = char[size];


template <size_t size>
inline void getString(const py::dict &d, const char *key, string_literal<size> &value)
{
    if (d.contains(key))
    {
        py::object o = d[key];
        std::string s = o.cast<std::string>();
        const char *buf = s.c_str();
        strcpy(value, buf);
    }
};

inline void getInt(const py::dict &d, const char *key, int *value)
{
    if (d.contains(key))       
    {
        py::object o = d[key];        
        *value = o.cast<int>();
    }
};

inline void getDouble(const py::dict &d, const char *key, double *value)
{
    if (d.contains(key))
    {
        py::object o = d[key];
        *value = o.cast<double>();
    }
};

inline void getChar(const py::dict &d, const char *key, char *value)
{
    if (d.contains(key))
    {
        py::object o = d[key];
        *value = o.cast<char>();
    }
};

inline std::string toUtf(const std::string &gb2312)
{
#ifdef _MSC_VER
    const static locale loc("zh-CN");
#else
    const static std::locale loc("zh_CN.GB2312");
#endif

    std::vector<wchar_t> wstr(gb2312.size());
    wchar_t* wstrEnd = nullptr;
    const char* gbEnd = nullptr;
    mbstate_t state = {};
    int res = std::use_facet<std::codecvt<wchar_t, char, mbstate_t> >
        (loc).in(state,
            gb2312.data(), gb2312.data() + gb2312.size(), gbEnd,
            wstr.data(), wstr.data() + wstr.size(), wstrEnd);

    if (std::codecvt_base::ok == res)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> cutf8;
        return cutf8.to_bytes(std::wstring(wstr.data(), wstrEnd));
    }

    return std::string();
}

#endif