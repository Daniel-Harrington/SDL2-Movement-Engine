#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"


class Player : public Entity {
private:
    int health;
  	Vector2f velocity;
public:
    Player(Vector2f p_pos, SDL_Texture* p_tex,int p_health = 100,Vector2f p_vel = Vector2f(0,0));
    int& getHealth() { return health; }
    Vector2f& getVel() { return velocity; }
    void setHealth(int newHealth) { health = newHealth; }
    void playerMove(const Uint8 *keystate, int SCREEN_HEIGHT);
    void playerUpdate(int SCREEN_WIDTH, int SCREEN_HEIGHT);
};

#endif