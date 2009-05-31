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

#include "timer.h"
#include <SDL.h>

namespace Fart
{
  /* Simple timer class. */
  Timer::Timer() :
    start_ticks(0),
    paused_ticks(0),
    paused(false),
    started(false)
  {
  }

  Timer::~Timer()
  {
  }

  void Timer::start()
  {
    started = true;
    paused = false;
    start_ticks = SDL_GetTicks();
  }

  void Timer::stop()
  {
    started = false;
    paused = false;
  }

  void Timer::pause()
  {
    if(started && !paused)
    {
      paused = true;
      paused_ticks = SDL_GetTicks() - start_ticks;
    }
  }

  void Timer::unpause()
  {
    if(paused)
    {
      paused = false;
      start_ticks = SDL_GetTicks() - paused_ticks;
      paused_ticks = 0;
    }
  }

  Uint32 Timer::get_ticks()
  {
    if(started)
    {
      if(paused)
      {
        return paused_ticks;
      }
      else
      {
        return SDL_GetTicks() - start_ticks;
      }
    }
    else
    {
      return 0;
    }
  }
}
