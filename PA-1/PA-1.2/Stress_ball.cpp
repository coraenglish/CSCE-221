#include "Stress_ball.h"
#include "Stress_ball_colors.h"
#include "Stress_ball_sizes.h"
#include <random>
#include <iostream>
#include <ostream>


Stress_ball::Stress_ball() {
    color = Stress_ball_colors(rand() % 4);
    size = Stress_ball_sizes(rand() % 3);
}

Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes h) : color(c), size(h) { }


Stress_ball_colors Stress_ball::get_color() const {
    return color;
}

Stress_ball_sizes Stress_ball::get_size() const {
    return size;
}

bool Stress_ball::operator==(const Stress_ball& sb) {
    int c = static_cast<int>(sb.get_color());
    int s = static_cast<int>(sb.get_size());
    if (c == static_cast<int>(color) && s == static_cast<int>(size)) {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Stress_ball& sb) {
    std::string colors[4] = {"red", "blue", "yellow", "green"};
    std::string sizes[3] = {"small", "medium", "large"};

    int n = static_cast<int>(sb.get_color());
    std::string sb_color = colors[n];
    int m = static_cast<int>(sb.get_size());
    std::string sb_size = sizes[m];
    os << '(' << sb_color << ", " << sb_size << ')' << std::endl;
    return os;
}