/* well.hpp --- 
 * 
 * Filename: well.hpp
 * Description: 
 * Author: Bryce
 * Maintainer: Adeel Bhutta
 * Created: Tue Sep  6 11:08:59 2016
 * Last-Updated: 01-10-2021
 *           By: Adeel Bhutta
 *     Update #: 0
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* Copyright (c) 2016 IUB.  
 * 
 * All rights reserved. 
 * 
 * Additional copyrights may follow 
 */

/* Code: */

#include <vector>
#include <string>

#ifndef DEFINE_WELL
#define DEFINE_WELL

struct singleScore {
    std::string name;
    int score;
};


typedef struct well {
  int upper_left_x;
  int upper_left_y;
  int width;
  int height;
  char draw_char;
  char color[3];
} well_t;

well_t *init_well(int, int, int, int);
void draw_well(well_t *);

well_t *changeWellSize(int upper_left_x, int upper_left_y, int width, int height, well_t *);

void draw_leaderboard(well_t *, std::vector<singleScore> scores);
void undraw_leaderboard(well_t *, std::vector<singleScore> scores);
void undraw_well(well_t *);
int prune_well(well_t *);
void lower_well(well_t *, int col);
bool compareScores(const singleScore &a, const singleScore &b);
#endif

/* well.hpp ends here */
