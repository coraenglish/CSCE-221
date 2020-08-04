#include "Jeans.h"
#include "Colors.h"
#include "Sizes.h"
#include <random>
#include <iostream>
#include <ostream>


Jeans::Jeans() {
    color = Jeans_colors(rand() % 4);
    size = Jeans_sizes(rand() % 4);
}

Jeans::Jeans(Jeans_colors c, Jeans_sizes h) : color(c), size(h) { }


Jeans_colors Jeans::get_color() const {
    return color;
}

Jeans_sizes Jeans::get_size() const {
    return size;
}

bool Jeans::operator==(const Jeans& j) {
    int c = static_cast<int>(j.get_color());
    int s = static_cast<int>(j.get_size());
    if (c == static_cast<int>(color) && s == static_cast<int>(size)) {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Jeans& j) {
    std::string colors[4] = {"white", "blue", "brown", "black"};
    std::string sizes[4] = {"small", "medium", "large", "xlarge"};

    int n = static_cast<int>(j.get_color());
    std::string j_color = colors[n];
    int m = static_cast<int>(j.get_size());
    std::string j_size = sizes[m];
    os << '(' << j_color << ", " << j_size << ')' << std::endl;
    return os;
}