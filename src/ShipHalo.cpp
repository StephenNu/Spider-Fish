#include "ShipHalo.h"
#include "PhysicalEntity.h"
#include "Game.h"
#include "SpiderFish.h"

ShipHalo::ShipHalo( Game* owner, float rad , int x, int y ):
  PhysicalEntity( owner,
                  owner->imageManager.createImage( img_resource( "circle.png" ) ),
                  0, 0, x, y ),
  _rad( rad )
{
}

ShipHalo::~ShipHalo()
{
}

int ShipHalo::getRad() const
{
  return _rad;
}

void ShipHalo::setRad( int rad )
{
	// Changed it to an if condition to control max and min values. Stephen
	if (rad >= 200)
	{
	_rad = 200;
	}
	else if (rad <= 100)
	{
		_rad = 100;
	}
	else
	{
		_rad = rad;
	}
}

void ShipHalo::draw( SDL_Surface* surface)
{
  int cx = getX();
  int cy = getY();
  int error = -_rad;
  int x = _rad;
  int y = 0;
  while( x >= y )
  {
    _sprite.draw( surface, cx + x, cy + y );
    _sprite.draw( surface, cx + y, cy + x );
    if( x != 0 )
    {
      _sprite.draw( surface, cx - x, cy + y );
      _sprite.draw( surface, cx + y, cy - x );
    }
    if( y != 0 )
    {
      _sprite.draw( surface, cx + x, cy - y );
      _sprite.draw( surface, cx - y, cy + x );
    }
    if( x != 0 && y != 0 )
    {
      _sprite.draw( surface, cx - x, cy - y );
      _sprite.draw( surface, cx - y, cy - x );
    }
    error += y;
    ++y;
    error += y;
    if( error >= 0 )
    {
      --x;
      error -= x;
      error -= x;
    }
  }
}
void ShipHalo::handleEvent( SDL_Event* event )
{
}

void ShipHalo::update( int msTimeStep )
{
  _rad += msTimeStep / 100.0;
  // Added if statement to check if the circle has grown to small or to large. Stephen
  if (_rad >= 200)
	{
	_rad = 200;
	}
}
