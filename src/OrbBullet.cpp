#include "OrbBullet.h"
#include "Bullet.h"
#include "SpiderFish.h"
#include "Game.h"

// Constructor that passes the ships halo to the bullet. SHOULD only be used for player's ship. Stephen
OrbBullet::OrbBullet(Game* owner, int x, int y, ShipHalo* halo):
  Bullet(owner,owner->imageManager.createImage(img_resource("bullet.png")),x,y,0,-250, halo)
{
	  // ONLY FOR PLAYER'S SHIP
}
  OrbBullet::OrbBullet(Game* owner, int x, int y):
  Bullet(owner,owner->imageManager.createImage(img_resource("bullet.png")),x,y,0,-250)
{
	  //ctor
}

OrbBullet::~OrbBullet()
{
  //dtor
}
