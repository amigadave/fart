/* Fart is copyright David King, 2009
 *
 * This file is part of Fart
 *
 * Fart is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Fart is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Fart. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _FART_PLAYER_H
#define _FART_PLAYER_H

#include "velocity.h"
#include <SDL.h>

namespace Fart
{
  /* Constant at the moment, can change once there is a UI. */
  const int mass = 20000;
  const double fuel_efficiency = 3000000.0;

  /* Will move into "level" class and be set based on planet gravity. */
  const double MOON_GRAVITY = 1.622;

  class Player
  {
    SDL_Surface *surface;

    /* SI units used for mass and length, angles in radians. */
    double x, y;
    double angle;
    Velocity velocity;
    double fuel_mass;

    public:

    Player();
    ~Player();

    void thrust(Uint32 ticks);
    void fall(Uint32 ticks);
  };
}

#endif /* _FART_PLAYER_H */
