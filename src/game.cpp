#include "game.h"
#include <iostream>
#include "SDL2/SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, float initialSpeed)
    : snake(grid_width, grid_height, initialSpeed),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      InitialSpeed(initialSpeed)
{
  PlaceObstacles();
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, _obstacles);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}
void Game::PlaceObstacles() {
  int NoOfObstacles=6;
  for(int i=0; i<NoOfObstacles; ++i) {
    Obstacle temp(random_w(engine), random_h(engine));
    while(!IsPointAvailable(temp.kCordinate)) {
      temp.SetPosition(random_w(engine), random_h(engine));
    }
    _obstacles.emplace_back(std::move(temp));
  }
}

bool Game::ObstaclesHit(int x, int y) {
  for(auto i: _obstacles) {
    if(i.ObstacleHit(x,y))
        return true;
  }
  return false;
}

bool Game::ObstaclesHit(SDL_Point p) {
  for(auto i: _obstacles) {
    if(i.ObstacleHit(p))
        return true; 
  }
  return false;
}

bool Game::IsPointAvailable(SDL_Point p) {
  if(ObstaclesHit(p))
      return false;
  if(snake.SnakeCell(p.x, p.y))
      return false;
  return true;
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    if(InitialSpeed==0.05f)
        score++;
    else if(InitialSpeed==0.1f)
        score=score+2;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }

  if(ObstaclesHit(new_x, new_y)) {
  snake.alive=false;
  std::cout<<"Hit an Obstacle"<<std::endl;
  return;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }