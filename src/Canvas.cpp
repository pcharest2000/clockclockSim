#include "Canvas.h"

Canvas::Canvas() {
  //   // Initialize SDL.
  SDL_Init(SDL_INIT_VIDEO);

  //   // create the window and renderer
  //   // note that the renderer is accelerated
  win = SDL_CreateWindow("Image Loading", 100, 100, 800, 600, 0);
  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  //   // Create and run the thread
  //   // thread = SDL_CreateThread(my_thread, NULL,NULL);
  //   // load our image
}
void Canvas::draw() {

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  // event handling
  SDL_Event e;
  if (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      cout << "Exit message" << endl;
      SDL_QuitSubSystem(SDL_INIT_VIDEO);
      return;
    }
  }
}
int Canvas::getWidth() { return 800; }
int Canvas::getHeight() { return 600; }

void Canvas::drawLine(int x, int y, int x2, int y2) {
  SDL_RenderDrawLine(renderer, x, y, x2, y2);
}
void Canvas::clear() {

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer); }

void Canvas::swapBuffers() { SDL_RenderPresent(renderer); }
