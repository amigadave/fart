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

#include "player.h"
#include "utils.h" /* For gamewide constants. */
#include <iostream>

namespace Fart
{
  Player::Player() :
    x(0.0),
    y(0.0),
    fuel_mass(100.0)
  {
    surface = load_image(PLAYER);
  }

  Player::~Player()
  {
    SDL_FreeSurface(surface);
  }

  void Player::thrust(Uint32 ticks)
  {
    if(fuel_mass > 0)
    {
      /* Use ten kilograms of fuel per second. */
      double used_fuel = static_cast<double>(ticks) / (TICKS_PER_SECOND / 10);
      if((fuel_mass -= used_fuel) > 0)
      {
        /* Direction in a single dimension, so don't set_direction(). */
        velocity.set_speed(velocity.get_speed() + (used_fuel * fuel_efficiency / (mass + fuel_mass)) * (static_cast<double>(ticks) / 1000));
      }
      else
      {
        fuel_mass = 0;
      }
    }
  }

  void Player::fall(Uint32 ticks)
  {
    velocity.set_speed(velocity.get_speed() - MOON_GRAVITY * (static_cast<double>(ticks) / TICKS_PER_SECOND));
    /* Debugging. */
    std::clog << "Fuel: " << fuel_mass << ", Velocity: " << velocity.get_speed() << std::endl;
  }
}
