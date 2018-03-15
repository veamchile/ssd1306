/*
    MIT License

    Copyright (c) 2018, Alexey Dynda

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/
/**
 * @file nano_engine.h Small graphics engine, based on SSD1331 functions
 */


#ifndef _NANO_ENGINE_H_
#define _NANO_ENGINE_H_

#include "nano_canvas.h"
#include "nano_engine/tiler.h"
#include "nano_engine/core.h"

/**
 * NanoEngine8 is simple graphics engine, that implements double buffering work
 * for the systems with very low resources. That is, memory buffer for SSD1331 oled
 * display needs at least 96x64x1 bytes (6144 bytes), and this is inacceptable for
 * microcontrollers like atmega328p (it has only 2KiB of RAM). So, to workaround
 * issue with low resources, NanoEngine8 uses small tile buffer (NE_TILE_SIZE x NE_TILE_SIZE)
 * and updates only part of oled screen at once. It makes system slow, but it is
 * possible to run NanoEngine8 on simple controllers.
 * If tile size is 32x32, then 96x64 oled display is devided into 6 tiles:
 *    [0,0] [1,0] [2,0]
 *    [0,1] [1,1] [2,1]
 * In your application you can choose, if you want to refresh whole screen (refresh()), or you
 * need to refresh only part of oled display.
 */
class NanoEngine8: public NanoEngineCore<TILE_8x8_RGB8>
{
public:
    /**
     * Creates new Graphics Engine object.
     */
    NanoEngine8(): NanoEngineCore() {};
};

/**
 * NanoEngine1 is simple graphics engine, that implements double buffering work
 * for the systems with very low resources. That is, memory buffer for SSD1306 oled
 * display needs at least 128x64/8 bytes (1024 bytes), and this is inacceptable for
 * microcontrollers like attiny85 (it has only 512B of RAM). So, to workaround
 * issue with low resources, NanoEngine1 uses small tile buffer (NE_TILE_SIZE x NE_TILE_SIZE)
 * and updates only part of oled screen at once. It makes system slow, but it is
 * possible to run NanoEngine1 on simple controllers.
 * If tile size is 32x32, then 128x64 oled display is devided into 8 tiles:
 *    [0,0] [1,0] [2,0], [3,0]
 *    [0,1] [1,1] [2,1], [3,1]
 * In your application you can choose, if you want to refresh whole screen (refresh()), or you
 * need to refresh only part of oled display.
 */
class NanoEngine1: public NanoEngineCore<TILE_8x8_MONO>
{
public:
    /**
     * Creates new Graphics Engine object.
     */
    NanoEngine1(): NanoEngineCore() {};
};

#endif

