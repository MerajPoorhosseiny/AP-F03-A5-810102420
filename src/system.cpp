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

void System::render()
{
  window.clear();
  switch (state)
  {
  case (GAME):
    window.draw(backgroundSprite);
    game_handler->render(window);
    break;
  case (MENU):
    window.draw(menuSprite);
    menu_handler->render(window);
    break;
  case (GAMEOVER_SCREEN):
    window.draw(gameoverSprite);
    break;
  case (EXIT):
    break;
  }
  window.display();
}

void System::handle_key_press(Event ev)
{
  if (ev.mouseButton.button == Mouse::Right)
    return;
  char pressedKey;
  if (ev.type == Event::KeyPressed)
  {
    Keyboard::Key key = ev.key.code;

    if (key >= Keyboard::A && key <= Keyboard::Z)
    {
      if (ev.key.shift || Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RShift))
        pressedKey = 'A' + (key - Keyboard::A);
      else
        pressedKey = 'a' + (key - Keyboard::A);
    }
    else if (key == Keyboard::Up)
    {
      pressedKey = '↑';
    }
    else if (key == Keyboard::Down)
    {
      pressedKey = '↓';
    }
    else if (key == Keyboard::Space)
    {
      pressedKey = ' ';
    }
    else if (key == Keyboard::Enter)
    {
      pressedKey = '\n';
    }
  }
  switch (state)
  {
  case (GAME):
    game_handler->handle_key_press(pressedKey);
    break;
  case (MENU):
    if (menu_handler->check_start())
    {
      game_handler = new Game_Handler();
      state = GAME;
    }
    if (menu_handler->check_exit())
      state = EXIT;
    if (menu_handler->check_mode())
    {
      if (mode == Day)
        mode = Night;
      else if (mode == Night)
        mode = Day;
      set_background_texture();
      set_menu_texture();
    }
    break;
  case (GAMEOVER_SCREEN):
    delete game_handler;
    state = MENU;
    break;
  case (EXIT):
    break;
  }
}

void System::set_background_texture()
{
  if (mode == Day)
    if (!backgroundTexture.loadFromFile(PICS_PATH + "g_DayBackground.png"))
      debug("failed to load image");
  if (mode == Night)
    if (!backgroundTexture.loadFromFile(PICS_PATH + "g_NightBackground.png"))
      debug("failed to load image");
  backgroundSprite.setTexture(backgroundTexture);
}

void System::set_menu_texture()
{
  if (mode == Day)
    if (!menuTexture.loadFromFile(PICS_PATH + "m_DayMenu.png"))
      debug("failed to load image");
  if (mode == Night)
    if (!menuTexture.loadFromFile(PICS_PATH + "m_NightMenu.png"))
      debug("failed to load image");
  menuSprite.setTexture(menuTexture);
}
