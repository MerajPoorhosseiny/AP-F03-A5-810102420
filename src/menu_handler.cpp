#include "menu_handler.hpp"

Menu_Handler::Menu_Handler (){
    IntRect srect;
    srect.top = 0;
    srect.left = 0;
    srect.width = 340;
    srect.height = 105;
    if (!StartKeyTexture.loadFromFile(PICS_PATH + "s_StartKey.png")) {
        debug("failed to load image");
    }
    StartKeySprite.setTexture(StartKeyTexture);
    StartKeySprite.setTextureRect(srect);
    StartKeySprite.setScale(1, 1);
    StartKeySprite.setPosition(655 ,160);
    IntRect erect;
    erect.top = 0;
    erect.left = 0;
    erect.width = 340;
    erect.height = 105;
    if (!ExitKeyTexture.loadFromFile(PICS_PATH + "s_ExitKey.png")) {
        debug("failed to load image");
    }
    ExitKeySprite.setTexture(ExitKeyTexture);
    ExitKeySprite.setTextureRect(erect);
    StartKeySprite.setScale(1, 1);
    ExitKeySprite.setPosition(655 ,330);
    IntRect mrect;
    mrect.top = 0;
    mrect.left = 0;
    mrect.width = 1400;
    mrect.height = 400;
    if (!ModeKeyTexture.loadFromFile(PICS_PATH + "s_ModeKey.png")) {
        debug("failed to load image");
    }
    ModeKeySprite.setTexture(ModeKeyTexture);
    ModeKeySprite.setTextureRect(mrect);
    ModeKeySprite.setScale(1, 1);
    ModeKeySprite.setPosition(0 ,0);
}
