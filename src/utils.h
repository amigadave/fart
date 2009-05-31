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

#ifndef _FART_UTILS_H
#define _FART_UTILS_H

#include <SDL.h>

namespace Fart
{
  /* Constants that can be changed when there is a UI. */
  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGHT = 480;
  const int SCREEN_DEPTH = 32;
  const char * const BACKGROUND = "data/background.bmp";
  const char * const PLAYER = "data/rocket_off.bmp";
  const int TICKS_PER_SECOND = 1000;
  const int PIXELS_PER_METRE = 10;

  SDL_Surface *load_image(const char * const filename);
}

#endif /* _FART_UTILS_H */
