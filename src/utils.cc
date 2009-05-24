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

#include "utils.h"
#include "SDL.h"

namespace Fart
{
  /* Load images for sprites and convert to display format.
   * Set colour key to black. */
  SDL_Surface* load_image(const char * const filename)
  {
    SDL_Surface *temp = SDL_LoadBMP(filename);
    if(temp)
    {
      SDL_SetColorKey(temp, SDL_SRCCOLORKEY, SDL_MapRGB(temp->format, 0, 0, 0));
      SDL_Surface *destination = SDL_DisplayFormat(temp);
      if(destination)
      {
        SDL_FreeSurface(temp);
        return destination;
      }
      else
      {
        return static_cast<SDL_Surface*>(0);
      }
    }
    else
    {
      return static_cast<SDL_Surface*>(0);
    }
  }
}
