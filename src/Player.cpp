#include "Player.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>

Player::Player(Vector2f p_pos, SDL_Texture* p_tex, int p_health,Vector2f p_vel)
        : Entity(p_pos, p_tex), health(p_health),velocity(p_vel) {}

void Player::playerMove(const Uint8 *keystate, int SCREEN_HEIGHT){
	const float acceleration = 1;

	 if ( keystate[SDL_SCANCODE_A] )
	{

		getVel().x-=acceleration;
	}
	if ( keystate[SDL_SCANCODE_D] )
	{
		getVel().x+=acceleration;
	}
	
	if(hypot(getVel().x,getVel().y) > 1){
		getVel().x = getVel().x*0.5;
		getVel().y= getVel().y*0.5;
	}
	if (keystate[SDL_SCANCODE_SPACE] && (this->getPos().y == SCREEN_HEIGHT-32)){
			getVel().y-=32 ;
		}

	return;
};

void Player::playerUpdate(int SCREEN_WIDTH, int SCREEN_HEIGHT){

if (this->getPos().y < SCREEN_HEIGHT-32){
	getVel().y += 0.098;
	this->getPos().x+=getVel().x;
}
else if ((this->getPos().x > 0) && this->getPos().x < SCREEN_WIDTH-10)
{
	this->getPos().x+=getVel().x;
}
else if((this->getPos().x <= 0) ){
	this->getPos() = Vector2f(1, this->getPos().y);
	getVel() = Vector2f(0,0);
}
else if((this->getPos().x >= SCREEN_WIDTH-10) ){
	this->getPos() = Vector2f( SCREEN_WIDTH-11,this->getPos().y);
	getVel() = Vector2f(0,0);
}

if (this->getPos().y  > 0 &&  (this->getPos().y <= SCREEN_HEIGHT-32) )
{
	this->getPos().y+= getVel().y;

}
else if((this->getPos().y <= 0) ){
	this->getPos() = Vector2f(this->getPos().x, 1);
	getVel() = Vector2f(0,0);
}
else if((this->getPos().y >= SCREEN_HEIGHT-32) ){
	this->getPos() = Vector2f( this->getPos().x,SCREEN_HEIGHT-32);
	getVel() = Vector2f(0,0);
}
	getVel().x = getVel().x *0.95;
	std::cout << "screen y :" <<SCREEN_HEIGHT<<std::endl;
	std::cout << "y :" <<this->getPos().y<<std::endl;
	std::cout << "x :" <<this->getPos().x<<std::endl;
	return;
};