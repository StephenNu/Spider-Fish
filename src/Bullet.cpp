#include <string>
#include <cmath>

#include "SDL.h"

#include "Bullet.h"
#include "SpiderFish.h"
#include "Game.h"
#include "EnemyShip.h"
// Added a constructor that references ShipHalo should only be used for a player ship. Stephen.
Bullet::Bullet( Game* owner, SDL_Surface* image, int x, int y, int vx, int vy, ShipHalo* halo):
  PhysicalEntity( owner,image,0,0,x,y )
{
  setVeloX(vx);
  setVeloY(vy);
  // Added the halo and two booleans to check if first its a player, and two if its inside the ShipHalo. Stephen
  _halo = halo;
  isPlayer = true;
  isInside = true;
}

  
Bullet::Bullet( Game* owner, SDL_Surface* image, int x, int y, int vx, int vy):
  PhysicalEntity( owner,image,0,0,x,y )
{
  setVeloX(vx);
  setVeloY(vy);
  // Sets isPlayer to false should not be called for player ship. Stephen
  isPlayer = false;
}

Bullet::~Bullet()
{
}

void Bullet::draw( SDL_Surface* screen )
{
  PhysicalEntity::draw(screen);
}

void Bullet::handleEvent( SDL_Event* event )
{

}

void Bullet::update( int msTimeStep )
{
  PhysicalEntity::update(msTimeStep);
  // First checks if its a player then if its inside the circle then gets the top Y coord of the halo and checks it against the Y coord of the bullet. Stephen
   if (isPlayer && isInside && ((this->getX()-_halo->getX())*(this->getX()-_halo->getX()) + (this->getY()-_halo->getY())*(this->getY()-_halo->getY())) > _halo->getRad()*_halo->getRad())
  {
  // Adds an enemy at that location. Stephen
  _owner->addGameObject( new EnemyShip( _owner, this->getX(), this->getY() ) );
  // Sets is inside the circle to false so it won't reenter the if condition. Stephen
  // Deletes the object in the next update cicle. Stephen.
  this->_alive = false;
  }
}
