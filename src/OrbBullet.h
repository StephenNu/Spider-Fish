#ifndef ORBBULLET_H
#define ORBBULLET_H

#include "Bullet.h"
#include "ShipHalo.h"

class OrbBullet : public Bullet
{
  public:
	  // Added a constructor that passes a ShipHalo, this should only be used for a player ship. Stephen
	OrbBullet(Game* owner, int x, int y, ShipHalo* halo);
	OrbBullet(Game* owner, int x, int y);
    virtual ~OrbBullet();
  protected:
  private:
};

#endif // ORBBULLET_H
