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

#include <config.h>
#include "fart.h"
#include "timer.h"
#include "SDL.h"
#include <iostream>

namespace Fart
{
  Fart::Fart() :
    quit(false)
  {
    /* Set video mode. */
    SDL_Surface *screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(!screen)
    {
      std::cerr << "Unable to set video mode: " << SDL_GetError() << std::endl;
      quit_game();
    }
    else
    {
      /* Second argument is for an icon. Use it when a logo exists. */
      SDL_WM_SetCaption(PACKAGE_STRING, 0);
      std::clog << "Video mode set." << std::endl;
    }

    /* Load images. */
    background = load_image(BACKGROUND);
    if(background)
    {
      std::clog << "Background image loaded." << std::endl;
    }
    else
    {
      std::cerr << "Error loading background image." << std::endl;
      quit_game();
    }
    player = load_image(PLAYER);
    if(player)
    {
      std::clog << "Player image loaded." << std::endl;
    }
    else
    {
      std::cerr << "Error loading player image." << std::endl;
      quit_game();
    }

    /* Blit background and player sprite to screen. */
    SDL_Rect screen_rect = { 0, };
    screen_rect.w = screen->w;
    screen_rect.h = screen->h;
    SDL_FillRect(screen, &screen_rect, SDL_MapRGB(screen->format, 0, 0, 50));
    blit_image(0, 0, background, screen);
    blit_image(0, 0, player, screen);
    SDL_Flip(screen);

    /* Main loop. */
    SDL_Event events = { 0, };
    Timer frame_timer;
    frame_timer.start();
    while(!quit)
    {
      /* SDL event loop. */
      if(SDL_PollEvent(&events))
      {
        switch(events.type)
        {
          case SDL_QUIT:
            std::clog << "Quit event received." << std::endl;
            quit = true;
            break;
          default:
            std::clog << "Unhandled SDL event received." << std::endl;
            break;
        }
      }

      /* Probe key state, rather than using key pressed/unpressed events. */
      Uint8 *keystate = SDL_GetKeyState(static_cast<int*>(0));
      if(keystate[SDLK_ESCAPE])
      {
        std::clog << "Escape pressed." << std::endl;
        quit = true;
      }
      if(keystate[SDLK_k])
      {
        std::clog << "Thrust key pressed." << std::endl;
      }

      /* Take time since previous time and run physics calculations. */
      Uint32 frame_delta = frame_timer.get_ticks();
      frame_timer.start();
      std::clog << "Ticks this frame: " << frame_delta << std::endl;

      /* Flip screen, and quit on failure. */
      if(SDL_Flip(screen) == -1)
      {
        std::cerr << "Error flipping screen." << std::endl;
        quit = true;
      }
    }

    /* Cleanup and exit. */
    quit_game();
  }

  Fart::~Fart()
  {
  }

  /* Load images for sprites and convert to display format.
   * Set colour key to black. */
  SDL_Surface* Fart::load_image(const char * const filename)
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

  /* Blit whole image att offset x, y. */
  void Fart::blit_image(int x, int y, SDL_Surface *source, SDL_Surface *destination)
  {
    SDL_Rect offset = { 0, };
    offset.x = x;
    offset.y = y;

    if(SDL_BlitSurface(source, static_cast<SDL_Rect*>(0), destination, &offset) == 0)
    {
      std::clog << "Image blitted successfully." << std::endl;
    }
    else
    {
      std::cerr << "Image blit failed: " << SDL_GetError() << std::endl;
    }
  }

  void Fart::quit_game()
  {
    SDL_FreeSurface(background);
    SDL_FreeSurface(player);
    SDL_Quit();
  }
}

