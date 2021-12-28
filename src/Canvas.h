#ifndef Canvas_H
#define Canvas_H

#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
using namespace std;

class Canvas{
 public:
  Canvas();
  void draw();
        int getWidth();
        int getHeight();
        void drawLine(int x,int y,int x2,int y22 );
        void clear();
        void swapBuffers();
 private:
     SDL_Window *win = NULL;
     SDL_Renderer *renderer = NULL;
};



#endif //DrawClok_H
