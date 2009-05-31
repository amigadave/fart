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

#ifndef _FART_FART_H
#define _FART_FART_H

#include "player.h"
#include <SDL.h>

namespace Fart
{
  class Fart
  {
    SDL_Surface *screen;
    SDL_Surface *background;
    Player player;

    bool quit;

    void blit_image(int x, int y, SDL_Surface *source, SDL_Surface *destination);
    void quit_game();

    public:
      Fart();
      ~Fart();
  };
}

#endif /* _FART_FART_H */
