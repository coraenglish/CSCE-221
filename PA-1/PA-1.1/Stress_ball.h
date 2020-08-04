#ifndef STRESS_BALL_H
#define STRESS_BALL_H
#include "Stress_ball_sizes.h"
#include "Stress_ball_colors.h"
#include <ostream>

class Stress_ball {
private:
    Stress_ball_colors color;
    Stress_ball_sizes size;
public:
    Stress_ball();
    Stress_ball(Stress_ball_colors c, Stress_ball_sizes h);
    Stress_ball_colors get_color() const;
    Stress_ball_sizes get_size() const;
    bool operator==(const Stress_ball& sb);
};

std::ostream& operator<<(std::ostream& o, const Stress_ball& sb);

#endif