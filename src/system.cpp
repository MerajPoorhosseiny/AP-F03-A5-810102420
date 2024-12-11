#include "system.hpp"

System::System(int width, int height)
{
  window.create(VideoMode(width, height), "PVZ", Style::Default);
  window.setFramerateLimit(FRAME_RATE);
  state = MENU;
  mode = Day;
  set_background_texture();
  set_gameover_texture();
  set_menu_texture();
  if (!music.openFromFile(AUDIO_PATH + "bg.ogg"))
  {
    debug("failed to load music");
  }
  music.setLoop(true);
  music.play();
  menu_handler = new Menu_Handler();
}

System::~System()
{
  delete game_handler;
}
