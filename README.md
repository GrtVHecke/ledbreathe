Copyright (c) 2016 Geert Van Hecke
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# ledbreathe
User control breathe behaviour for the RGB led on Particle devices.

# usage
LedBreathe _led( 100, 10, 128, true, 0, 255, 255 ); /// Let the RGB led breathe with the color Cyan as start color and a maximum brightness of 50%

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


/**
 * Starts simulating the "breathe" behaviour of the RGB led
 *
 * @return void
 */
void LedBreathe::start( void )


/**
 * Stops simulating the "breathe" behaviour of the RGB led
 *
 * @return void
 */
void LedBreathe::stop( void )


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


# example program
An example program is included, which changes color every 20 seconds (3 colors) and breathes to a maximum of 50% of the RGB led's brightness.
