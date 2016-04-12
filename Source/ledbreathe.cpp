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
#include "ledbreathe.h"


 //----------------------------------------------------------------------------------------------------------------------
 /**
  * Constructor
  *
  * @param [in] interval      The interval (ms) for changing the brightness of the RGB led in the "breathe" behaviour
  * @param [in] fadeAmount    The amout to fade/increase the brightness of the RGB led in the "breathe" behaviour
  * @param [in] maxBrightness The maximum brightness of the RGB led in the "breathe" behaviour
  * @param [in] autoStart     If TRUE, the fade behaviour starts immediately
  * @param [in] initR         The initial Red part of the color for the auto start
  * @param [in] initG         The initial Green part of the color for the auto start
  * @param [in] initB         The initial Blue part of the color for the auto start
  */
LedBreathe::LedBreathe( unsigned int interval, int fadeAmount, byte maxBrightness, bool autoStart, byte initR, byte initG, byte initB )
{
    _tmr           = new Timer (interval, &LedBreathe::breathe, *this );
    _fadeAmount    = fadeAmount;
    _maxBrightness = maxBrightness;

    if ( autoStart )
    {
        controlRGB( true, initR, initB, initG );
        start();
    }
}


//----------------------------------------------------------------------------------------------------------------------
/**
 * The timer method for simulating the "breathe" behaviour of the RGB led
 *
 * @return void
 */
void LedBreathe::breathe( void )
{
    _brightness = _brightness + ( _direction * _fadeAmount );

    // Reverse the direction of the fading at the ends of the fade
    if ( _brightness <= BRIGHT_MIN || _brightness >= _maxBrightness )
    {
        _direction = -_direction;

        if ( _brightness <= BRIGHT_MIN )
        {
            _brightness = BRIGHT_MIN;
        }

        if ( _brightness >= _maxBrightness )
        {
            _brightness = _maxBrightness;
        }
    }

    RGB.brightness( _brightness );
}


//----------------------------------------------------------------------------------------------------------------------
/**
 * Starts simulating the "breathe" behaviour of the RGB led
 *
 * @return void
 */
void LedBreathe::start( void )
{
    _direction  = DIR_FADE;
    _brightness = BRIGHT_MAX;

    controlRGB( true, _colorR, _colorG, _colorB );
    _tmr->start();
}


//----------------------------------------------------------------------------------------------------------------------
/**
 * Stops simulating the "breathe" behaviour of the RGB led
 *
 * @return void
 */
void LedBreathe::stop( void )
{
    _tmr->stop();
}


//----------------------------------------------------------------------------------------------------------------------
/**
 * Sets the color of the RGB led
 *
 * @param [in] colorR The Red part of the color for the RGB led on the Particle device
 * @param [in] colorG The Green part of the color for the RGB led on the Particle device
 * @param [in] colorB The Blue part of the color for the RGB led on the Particle device
 *
 * @return void
 */
void LedBreathe::setColor( byte colorR, byte colorG, byte colorB )
{
    if ( RGB.controlled() )
    {
        stop();

        _colorR     = colorR;
        _colorG     = colorG;
        _colorB     = colorB;
        _direction  = DIR_FADE;
        _brightness = BRIGHT_MAX;

        RGB.brightness( _brightness );
        RGB.color( colorR, colorG, colorB );

        start();
    }
}


//----------------------------------------------------------------------------------------------------------------------
/**
 * Sets the color of the RGB led
 *
 * @param [in] control If TRUE the user takes control of the RGB led of the Particle device
 * @param [in] colorR  The Red part of the color for the RGB led on the Particle device (if in user control)
 * @param [in] colorG  The Green part of the color for the RGB led on the Particle device (if in user control)
 * @param [in] colorB  The Blue part of the color for the RGB led on the Particle device (if in user control)
 *
 * @return void
 */
void LedBreathe::controlRGB( bool control, byte colorR, byte colorG, byte colorB )
{
    if ( RGB.controlled() != control )
    {
        RGB.control( control );

        if ( control == true )
        {
            setColor( colorR, colorG, colorB );
        }
    }
}
