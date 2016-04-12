/**********************************************************************************************************************
 * Copyright © 2016 by Geert Van Hecke
 *
 * User control breathe behaviour for the RGB led on Particle devices.
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
 * @file   ledbreathe.h
 * @author Geert Van Hecke
 * @date   12 April 2016
 * @brief  Led breathe user control
 *
 * User control breathe behaviour for the RGB led on Particle devices.
 */
#ifndef _LEDBREATHE_H
#define _LEDBREATHE_H


#include <application.h>


#define BRIGHT_MIN   0  /// Minimum brightness
#define BRIGHT_MAX 255  /// Maximum brightness

#define DIR_INCR     1  /// Increase the brightness
#define DIR_FADE    -1  /// Fade the brightness


class LedBreathe
{
    private:
        int    _direction     = DIR_FADE;    /// 1 = make brighter / -1 = fade
        int    _fadeAmount    =  10;         /// The amout to fade/increase the brightness of the RGB led
        int    _brightness    = BRIGHT_MAX;  /// The current brightness of the RGB led
        int    _maxBrightness = BRIGHT_MAX;  //  The maximum brightness used in the "breathe" behaviour
        byte   _colorR        =   0;         /// The last used red part of the RGB led
        byte   _colorG        =   0;         /// The last used green part of the RGB led
        byte   _colorB        =   0;         /// The last used blue part of the RGB led
        Timer *_tmr;                         /// The timer responsible for simulating the "breathe" behaviour

        void breathe( void );

    public:
        LedBreathe( unsigned int interval, int fadeAmount, byte maxBrightness, bool autoStart, byte initR, byte initG, byte initB );

        void start( void );
        void stop( void );
        void setColor( byte colorR, byte colorG, byte colorB );
        void setBrightness( byte brightness );
        void controlRGB( bool control, byte colorR, byte colorG, byte colorB );
};


#endif /* _LEDBREATHE_H */
