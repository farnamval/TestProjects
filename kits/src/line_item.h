#ifndef LINE_ITEM_H
#define LINE_ITEM_H

#include <string>
#include <vector>

struct LineItem
{
    int pos;
    std::string productName;
    int quantity;
    std::vector<std::string> categories;
};

bool operator<(const LineItem& a, const LineItem& b)
{
    return a.categories < b.categories;
}

bool operator>(const LineItem& a, const LineItem& b)
{
    return a.categories > b.categories;
}

bool operator<=(const LineItem& a, const LineItem& b)
{
    return a.categories <= b.categories;
}

bool operator>=(const LineItem& a, const LineItem& b)
{
    return a.categories >= b.categories;
}

#endif // LINE_ITEM_H
