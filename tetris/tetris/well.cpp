/* well.cpp --- 
 * 
 * Filename: well.cpp
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

/* Copyright (c) 2016 IUB 
 * 
 * All rights reserved. 
 * 
 * Additional copyrights may follow 
 */

/* Code: */

#include <cstdlib>
#include <ncurses.h>
#include <map>
#include <string>
#include "well.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>

well_t *init_well(int upper_left_x, int upper_left_y, int width, int height) {
  well_t *w;
  w = (well_t*) malloc(sizeof(well_t));
  w->upper_left_x = upper_left_x;
  w->upper_left_y = upper_left_y;
  w->width = width;
  w->height = height;
  w->draw_char = '#';
  w->color[0] = 0;
  w->color[1] = 0;
  w->color[2] = 0;
  return (w);
}

void draw_well(well_t *w) {
  int row_counter, column_counter;
  // Draw left side of well
  for (column_counter=w->upper_left_y;column_counter<=(w->upper_left_y + w->height);column_counter++) {
    mvprintw(column_counter,w->upper_left_x,"%c",w->draw_char);
  }

  // Draw right side of well
  for (column_counter=w->upper_left_y;column_counter<=(w->upper_left_y + w->height);column_counter++) {
    mvprintw(column_counter,(w->upper_left_x + w->width),"%c",w->draw_char);
  }
  
  // Draw Bottom of well 
  for (row_counter=w->upper_left_x;row_counter<=(w->upper_left_x + w->width);row_counter++) {
    mvprintw(w->upper_left_y + w->height,row_counter,"%c",w->draw_char);
  }

  mvprintw(w->upper_left_y,w->upper_left_x+29,"NEXT:");
  mvprintw(w->upper_left_y,w->upper_left_x-13,"LIVES:");
  mvprintw(w->upper_left_y+2,w->upper_left_x-13,"TIME:");
  mvprintw(w->upper_left_y+4,w->upper_left_x-13,"SCORE:");
}

bool compareScores(const singleScore &a, const singleScore &b) {
    return a.score > b.score;
}

void draw_leaderboard(well_t *w, std::vector<singleScore> scores) {
  std::sort(scores.begin(), scores.end(), compareScores);
  mvprintw(w->upper_left_y+7,w->upper_left_x-30, "HIGHSCORES:");
  std::ostringstream ss;
  for(int i = 0; i < scores.size(); i++) {
    ss.str("");
    ss.clear();
    ss << scores[i].score;
    mvprintw(w->upper_left_y+9+i,w->upper_left_x-30, ss.str().c_str());
    mvprintw(w->upper_left_y+9+i,w->upper_left_x-27, scores[i].name.c_str());
  };
}

void undraw_leaderboard(well_t *w, std::vector<singleScore> scores) {
  mvprintw(w->upper_left_y+7,w->upper_left_x-30, "HIGHSCORES:");
  for(int i = 0; i < scores.size(); i++) {
    mvprintw(w->upper_left_y+9+i,w->upper_left_x-27, "                                                      ");
  };
}

well_t *changeWellSize(int upper_left_x, int upper_left_y, int width, int height, well_t *w) {

  w->upper_left_x = upper_left_x;
  w->upper_left_y = upper_left_y;
  if(width < 10)
     w->width = 10;
  else
     w->width = width;

  w->height = height;
  
  return (w);
}

int prune_well(well_t* w) {
  int row_counter, column_counter;
  bool full_row;
  int score = 0;
  for (column_counter=w->upper_left_y;column_counter<=(w->upper_left_y + w->height - 1);column_counter++) {
    full_row = true;
    for (row_counter=w->upper_left_x+1;row_counter<=(w->upper_left_x + w->width - 1);row_counter++) {
      if(mvinch(column_counter,row_counter) == ' ') {
        full_row = false;
      };
    }
    if(full_row) {
      for (row_counter=w->upper_left_x+1;row_counter<=(w->upper_left_x + w->width - 1);row_counter++) {
        mvprintw(column_counter,row_counter," ");
      }
      lower_well(w, column_counter);
      score++;
      column_counter--;
    }
    
  }
  return score;
}

void lower_well(well_t* w, int col) {
  int row_counter, column_counter;

  for (column_counter=col;column_counter>=w->upper_left_y + 1;column_counter--) {
    for (row_counter=w->upper_left_x+1;row_counter<=(w->upper_left_x + w->width - 1);row_counter++) {
      move(column_counter - 1,row_counter);
      chtype output = inch();
      move(column_counter,row_counter);
      addch(output);
    }
  }
}

void undraw_well(well_t *w) {
  int row_counter, column_counter;

  // Undraw well 
  for (row_counter=w->upper_left_x;row_counter<=(w->upper_left_x + w->width);row_counter++) {
    for (column_counter=w->upper_left_y;column_counter<=(w->upper_left_y + w->height);column_counter++) {
      mvprintw(column_counter,row_counter," ",w->draw_char);
    }
  }
}
/* well.cpp ends here */
