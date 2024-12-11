#pragma once

#include "global.hpp"
#include "setting.hpp"
#include "game_handler.hpp"
#include "menu_handler.hpp"

enum State {
  GAME,
  // PAUSE,
  MENU,
  GAMEOVER_SCREEN,
  EXIT
};

enum Mode{
  Day,
  Night
};

