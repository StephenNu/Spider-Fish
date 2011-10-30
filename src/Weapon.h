#ifndef WEAPON_H
#define WEAPON_H

#include "GameObject.h"
#include "Ship.h"
#include "ShipHalo.h"
class Ship;

class Weapon : public GameObject
{
  public:
	  // Added ShipHalo* as a parameter. Only for player ship. Stephen
    Weapon( Game* owner, Ship* body, ShipHalo* halo );
	Weapon( Game* owner, Ship* body);
    virtual ~Weapon();
    virtual void handleEvent( SDL_Event* event ) = 0;
    virtual void update( int msTimeStep ) = 0;
    virtual void draw( SDL_Surface* screen ) = 0;
    virtual void fire() = 0;
  protected:
    Ship* _body;
    int _lastShot;
    int _firingSpeed;
    bool _triggerPulled;
	// Added the _halo variable.
	ShipHalo* _halo;
  private:
};

#endif // WEAPON_H
