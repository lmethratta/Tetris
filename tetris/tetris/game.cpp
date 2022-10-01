/* game.cpp --- 
 * 
 * Filename: game.cpp
 * Description: 
 * Author: Bryce
 * Maintainer: Adeel Bhutta
 * Created: Tue Sep  6 11:08:59 2016
 * Last-Updated: 01-10-2021
 *           By: Adeel Bhutta
 *     Update #: 20
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
#include <unistd.h> 
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include "game.hpp"
#include "well.hpp"
#include "tetris.hpp"
#include "tetromino.hpp"
#include "key.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "score.hpp"

void init_game(void) {
  int x,y;
}

void save(std::string name, int score) {
    std::vector<singleScore> scores = load();
    std::ofstream saveFile ("highscores.txt");
    singleScore s;
    s.name = name;
    s.score = score;
    scores.push_back(s);
    if(scores.size() > 5) {
      std::sort(scores.begin(), scores.end(), compareScores);
      scores.pop_back();
    }
    for(int i = 0; i < scores.size(); i++) {
      saveFile << '\n' << scores[i].name << '\n' << scores[i].score << '\n';
    };
    saveFile.close();
}

std::vector<singleScore> load() {
    std::string fName;
    std::vector<singleScore> scores;
    std::fstream saveFile ("highscores.txt");
    while ( getline(saveFile,fName) ) {
        std::string name;
        std::string score;
        getline(saveFile, name);
        getline(saveFile, score);

        int scoreInt;
        std::istringstream ( score ) >> scoreInt;
        singleScore s;
        s.name = name;
        s.score = scoreInt;
        scores.push_back(s);
    }
    saveFile.close();
    return scores;
}


int game() {
  std::cout << "Please enter your name\n";
  std::string name;
  std::cin >> name;
  static int state = INIT;
  tetromino_t *next = NULL;
  tetromino_t *current = NULL;
  int lives = 3;
  well_t *w;
  int x,y;
  int c;
  int score = 0;
  int arrow;
  struct timespec tim = {0,1000000};  // Each execution of while(1) is approximately 1mS
  struct timespec tim_ret;
  int move_counter = 0;
  int move_timeout = BASE_FALL_RATE;            
  std::ostringstream ss;
  std::clock_t start = std::clock();
  int time_buffer = 0;

  while(1) {
    switch(state) {
    case PAUSE:
      if ((arrow = read_escape(&c)) != NOCHAR) {
	      switch (arrow) {
          case REGCHAR:
            if (c == 'q') {
              state = EXIT;
            }
            if (c == 'p') {
              start = std::clock();
              state = MOVE_PIECE;
            }
	      }
      }
      break;
    case INIT:               // Initialize the game, only run one time 
      initscr();
      nodelay(stdscr,TRUE);  // Do not wait for characters using getch.  
      noecho();              // Do not echo input characters 
      getmaxyx(stdscr,y,x);  // Get the screen dimensions 
      w = init_well(((x/2)-(WELL_WIDTH/2)),1,WELL_WIDTH,WELL_HEIGHT);
      undraw_well(w);
      //Show Leaderboard
      draw_leaderboard(w, load());

      draw_well(w);
      srand(time(NULL));     // Seed the random number generator with the time. Used in create tet. 
      mvprintw(w->upper_left_y,w->upper_left_x-7, "3");
      mvprintw(w->upper_left_y+4,w->upper_left_x-7, "0");
      state = ADD_PIECE;
      break;
    case ADD_PIECE:          // Add a new piece to the game
      score = compute_score(score, prune_well(w));
      ss.str("");
      ss.clear();
      ss << score;
      mvprintw(w->upper_left_y+4,w->upper_left_x-7,ss.str().c_str());
      if (next) {
        undisplay_next_tetromino(next, w);
	      current = next;
	      next = create_tetromino ((w->upper_left_x+(w->width/2)), w->upper_left_y);
      }
      else {
	      current = create_tetromino ((w->upper_left_x+(w->width/2)), w->upper_left_y);
	      next = create_tetromino ((w->upper_left_x+(w->width/2)), w->upper_left_y);
      }
      if(check_collision(current) == COLLIDE) {
        undraw_well(w);
        lives--;
        char lives_str[2];
        lives_str[0] = (char)(lives + '0');
        lives_str[1] = '\0';
        mvprintw(w->upper_left_y,w->upper_left_x-7, lives_str);
        if (lives == 0) {
          undraw_leaderboard(w, load());
          save(name, score);
          draw_leaderboard(w, load());
          state = GAME_OVER;
        } else {
          state = ADD_PIECE;
          draw_well(w);
        }
        break;
      }
      display_tetromino(current);
      display_next_tetromino(next, w);
      move_timeout = FALL_SPEEDS[rand()%5]; 
      state = MOVE_PIECE;
      break;
    case MOVE_PIECE:         // Move the current piece 
      if ((arrow = read_escape(&c)) != NOCHAR) {
	      switch (arrow) {
	        case UP:
            undisplay_tetromino(current);
            rotate_cw(current);
            display_tetromino(current);
	          break;
          case DOWN:
            undisplay_tetromino(current);
            rotate_ccw(current);
            display_tetromino(current);
            break;
          case LEFT:
            undisplay_tetromino(current);
            move_tet(current, (*current).upper_left_x - 1, (*current).upper_left_y);
            display_tetromino(current);
            break;
          case RIGHT:
            undisplay_tetromino(current);
            move_tet(current, (*current).upper_left_x + 1, (*current).upper_left_y);
            display_tetromino(current);
            break;
          case REGCHAR:
            if (c == 'q') {
              state = EXIT;
            }
            if (c == 'p') {
              time_buffer = ((std::clock() - start) / 60000) + time_buffer;
              state = PAUSE;
            }
            if (c == ' ') {
              move_timeout = DROP_RATE; 
            }
	      }
      } 
      if (move_counter++ >= move_timeout) {
        ss.str("");
        ss.clear();
        ss << ((std::clock() - start) / 60000) + time_buffer;
        mvprintw(w->upper_left_y+2,w->upper_left_x-8, ss.str().c_str());
        undisplay_tetromino(current);
        if(move_tet(current, (*current).upper_left_x, (*current).upper_left_y + 1) == MOVE_FAILED) {
          state = ADD_PIECE;
        }
        display_tetromino(current);
	      move_counter = 0;
      }
      break;
    case EXIT:
      endwin();
      return(0);
      break;
    case GAME_OVER:
      ss.str("");
      ss.clear();
      ss << score;
      mvprintw(w->upper_left_y+10,w->upper_left_x+3,"GAME OVER, SCORE: ");
      mvprintw(w->upper_left_y+10,w->upper_left_x+21,ss.str().c_str());
      if ((arrow = read_escape(&c)) != NOCHAR) {
	      switch (arrow) {
          case REGCHAR:
            if (c == 'q') {
              state = EXIT;
            }
	      }
      }
    }
    refresh();
    nanosleep(&tim,&tim_ret);
  }
}

/* game.cpp ends here */
