#ifndef BULLET_H
#define BULLET_H

#include <string>

#include "SDL.h"

#include "SpiderFish.h"
#include "Sprite.h"
#include "PhysicalEntity.h"
#include "ShipHalo.h"

class Bullet : public PhysicalEntity
{
  public:
	  // Added a new constructor that passes a ShipHalo reference this should only be called when it is a player ship. Stephen
    Bullet( Game* owner, SDL_Surface* image, int x, int y, int vx, int vy, ShipHalo* halo);
    Bullet( Game* owner, SDL_Surface* image, int x, int y, int vx, int vy);
    virtual ~Bullet();
    virtual void draw( SDL_Surface* );
    virtual void update( int msTimeStep );
    virtual void handleEvent(SDL_Event* event);
  protected:
	  // Added five variables one to pass the halo down to the bullet, and two booleans to check if a player shoot it and if they did is it inside the circle. Stephen
	  ShipHalo* _halo;
	  bool isPlayer;
	  bool isInside;
  private:
};

#endif // BULLET_H
