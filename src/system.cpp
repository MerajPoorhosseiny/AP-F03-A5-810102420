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

void System::run()
{
  while (window.isOpen() and state != EXIT)
  {
    update();
    render();
    handle_events();
  }
  exit(0);
}

void System::handle_events()
{
  Event event;
  while (window.pollEvent(event))
  {
    switch (event.type)
    {
    case (Event::Closed):
      window.close();
      state = EXIT;
      break;
    case (Event::MouseButtonPressed):
      handle_key_press(event);
      break;
    case (Event::MouseButtonReleased):
      break;
    default:
      break;
    }
  }
}

void System::update()
{
  Vector2i pos = Mouse::getPosition(window);
  switch (state)
  {
  case (GAME):
    game_handler->update();
    if (game_handler->check_gameover())
      state = GAMEOVER_SCREEN;
    break;
  case (MENU):
    menu_handler->update(pos);
    break;
  case (GAMEOVER_SCREEN):
    break;
  case (EXIT):
    break;
  }
}
