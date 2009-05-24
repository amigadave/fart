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

#ifndef _FART_TIMER_H
#define _FART_TIMER_H

#include "SDL.h"

namespace Fart
{
  class Timer
  {
    Uint32 start_ticks;
    Uint32 paused_ticks;

    bool paused;
    bool started;

    public:

    Timer();
    ~Timer();

    void start();
    void stop();
    void pause();
    void unpause();

    Uint32 get_ticks();

    bool is_paused();
    bool is_started();
  };
}

#endif /* _FART_TIMER_H */
