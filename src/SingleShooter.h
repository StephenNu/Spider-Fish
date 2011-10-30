#ifndef SHIPBULLET_H
#define SHIPBULLET_H

// SDL
#include "SDL.h"

// Engine
#include "Weapon.h"
#include "Game.h"
#include "SpiderFish.h"
#include "Ship.h"
#include "Sprite.h"
#include "ShipHalo.h"
class SingleShooter : public Weapon
{
  public:
	  // Added ShipHalo* as a parameter Only for player ships. Stephen
    SingleShooter( Game*owner, Ship* body, ShipHalo* halo );
    SingleShooter( Game*owner, Ship* body);
    virtual ~SingleShooter();
    virtual void handleEvent( SDL_Event* event );
    virtual void update( int msTimeStep );
    virtual void draw( SDL_Surface* screen );
    virtual void fire();
  protected:
	  // Added a bool to check if its a player weapon and needs the halo. Stephen
	  bool isPlayer;
  private:
};

#endif // SHIPBULLET_H
