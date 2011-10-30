#include "Weapon.h"
// Added ShipHalo* as a parameter Should only be used for a player's ship weapon. Stephen
Weapon::Weapon( Game* owner, Ship* body, ShipHalo* halo ):
  GameObject( owner ),
  _body( body ),
  _lastShot( 0 ),
  _firingSpeed( 0 ),
  _triggerPulled( false ),
  _halo( halo )
{
  //ctor
}
Weapon::Weapon(Game* owner, Ship* body):
  GameObject( owner ),
  _body( body ),
  _lastShot( 0 ),
  _firingSpeed( 0 ),
  _triggerPulled( false )
{
	// empty
}

Weapon::~Weapon()
{
  //dtor
}
