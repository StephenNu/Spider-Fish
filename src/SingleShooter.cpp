// c++
#include <cmath>

// SDL
#include "SDL.h"
#include "SDL_gfxPrimitives.h"

// Engine
#include "SpiderFish.h"
#include "Game.h"
#include "SingleShooter.h"
#include "OrbBullet.h"

// Constant
#include "ShipHalo.h"
// Added a parameter to pass the halo to the weapon. Stephen
SingleShooter::SingleShooter( Game* owner, Ship* body, ShipHalo* halo ) : 
Weapon( owner, body, halo )
{
  _firingSpeed = 200;
  isPlayer = true;
}

SingleShooter::SingleShooter( Game* owner, Ship* body) : 
Weapon( owner, body )
{
  _firingSpeed = 200;
  isPlayer = false;
}
SingleShooter::~SingleShooter()
{
}

void SingleShooter::handleEvent( SDL_Event* event )
{
  switch( event->type )
  {
    case SDL_KEYDOWN:
      switch( event->key.keysym.sym )
      {
        case SDLK_SPACE:
          _triggerPulled = true;
        default:
          break;
      }
      break;
    case SDL_KEYUP:
      switch( event->key.keysym.sym )
      {
        case SDLK_SPACE:
          _triggerPulled = false;
        default:
          break;
      }
    default:
      break;
  }
}

void SingleShooter::update( int msTimeStep )
{
  _lastShot += msTimeStep;
  if( _triggerPulled )
  {
    if( _firingSpeed < _lastShot )
    {
      fire();
	 // Decreases the rad by 6 from its current every time it fires. Stephen
	 _halo->setRad(( _halo->getRad()-6));

      _lastShot = _lastShot % _firingSpeed;
    }
  }
}

void SingleShooter::draw( SDL_Surface* screen )
{
}

void SingleShooter::fire()
{
  //_owner->addGameObject( new OrbBullet( _body->getX(), _body->getY() ) );
	// Added the halo reference to OrbBullet so it can be passed to bullet or not based on if its a player ship or not. Stephen.
	if (isPlayer)
	{
		_owner->addGameObject( new OrbBullet( _owner, _body->getX(), _body->getY(), _halo  ));
	}
	else
	{
		_owner->addGameObject( new OrbBullet( _owner, _body->getX(), _body->getY()));
	}
}
