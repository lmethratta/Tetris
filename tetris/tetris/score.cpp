#include "score.hpp"
#include <cmath>

int compute_score(int previous_score, int lines_cleared) {
    return previous_score + pow(lines_cleared, 2);
}