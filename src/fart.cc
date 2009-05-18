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

#include <iostream>
#include "SDL.h"
#include "fart.h"

namespace Fart
{
  Fart::Fart()
  {
    /* Set video mode. */
    SDL_Surface *screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(!screen)
    {
      std::cerr << "Unable to set video mode: " << SDL_GetError() << std::endl;
      return;
    }
    else
    {
      std::clog << "Video mode set." << std::endl;
    }

    /* SDL event loop. */
    SDL_Event events = { 0, };
    while(SDL_PollEvent(&events))
    {
      switch(events.type)
      {
        case SDL_QUIT:
          std::clog << "Quit event received." << std::endl;
          SDL_Quit();
          return;
          break;
        case SDL_KEYDOWN:
          switch(events.key.keysym.sym)
          {
            case SDLK_ESCAPE:
              {
              std::clog << "Escape pressed." << std::endl;
              SDL_Event quit_event = { 0, };
              quit_event.type = SDL_QUIT;
              SDL_PushEvent(&quit_event);
              break;
              }
            default:
              std::cerr << "Unhandled key pressed." << std::endl;
              break;
          }
          break;
        default:
          std::cerr << "Unhandled event received." << std::endl;
          break;
      }
    }
  }

  Fart::~Fart()
  {
  }
}

