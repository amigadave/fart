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

#include "fart.h"
#include <SDL.h>
#include <iostream>

int main(int argc, char **argv)
{
  /* Initialise SDL. */
  if(SDL_Init(SDL_INIT_AUDIO  | SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
  {
    std::cerr << "Unable to initialise SDL: " << SDL_GetError() << std::endl;
    return 1;
  }
  else
  {
    std::clog << "SDL initialised." << std::endl;
  }

  Fart::Fart smelly;

  /* Cleanup. */
  SDL_Quit();
  return 0;
}
