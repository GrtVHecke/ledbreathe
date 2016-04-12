// This #include statement was automatically added by the Particle IDE.
#include "ledbreathe.h"

/**********************************************************************************************************************
 * Copyright © 2016 by Geert Van Hecke
 *
 * Example of how to user control breathe behaviour for the RGB led on Particle devices.
 *
 *
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
***********************************************************************************************************************/


/**
 * @file   ledbreathe_example.ino
 * @author Geert Van Hecke
 * @date   12 April 2016
 * @brief  Example led breathe user control
 *
 * Example of how to user control breathe behaviour for the RGB led on Particle devices.
 */


#include "ledbreathe.h"


#define SEC_CHANGE_COLOR 20                         /// The number of seconds that need to pass before changing color


LedBreathe _led( 100, 10, 128, true, 0, 255, 255 ); /// Let the RGB led breathe with the color Cyan as start color and a maximum brightness of 50%
int        _counter = 0;                            /// The second counter


//----------------------------------------------------------------------------------------------------------------------
/**
 * Set up the Particle device
 *
 * @return void
 */
void setup( void )
{
    //
}


//----------------------------------------------------------------------------------------------------------------------
/**
 * Particle device main application loop
 *
 * @return void
 */
void loop( void )
{
    // Wait 1 second
    delay( 1000 );
    _counter++;

    // Let the led "breathe"
    switch( _counter )
    {
        // Breathe Cyan
        case 0:
            _led.setColor( 0, 255, 255 );
            break;

        // Breathe orange
        case SEC_CHANGE_COLOR:
            _led.setColor( 255, 165, 0 );
            break;

        // Breathe green
        case 2 * SEC_CHANGE_COLOR:
            _led.setColor( 0, 255, 0 );
            break;

        // Change back to the original color
        case ( 3 * SEC_CHANGE_COLOR ) - 1:
            _counter = -1;
            break;
    }
}
