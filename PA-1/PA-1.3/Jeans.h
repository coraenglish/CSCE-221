#ifndef JEANS_H
#define JEANS_H
#include "Sizes.h"
#include "Colors.h"
#include <ostream>

class Jeans {
private:
    Jeans_colors color;
    Jeans_sizes size;
public:
    Jeans();
    Jeans(Jeans_colors c, Jeans_sizes h);
    Jeans_colors get_color() const;
    Jeans_sizes get_size() const;
    bool operator==(const Jeans& j);
};

std::ostream& operator<<(std::ostream& o, const Jeans& j);

#endif