/******************************************************************************
* Copyright (c) 2018(-2022) STMicroelectronics.
* All rights reserved.
*
* This file is part of the TouchGFX 4.19.0 distribution.
*
* This software is licensed under terms that can be found in the LICENSE file in
* the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
*******************************************************************************/

#include <platform/driver/lcd/LCD8bpp_BGRA2222.hpp>
#include <touchgfx/widgets/canvas/PainterBGRA2222.hpp>

namespace touchgfx
{
void PainterBGRA2222::render(uint8_t* ptr, int x, int xAdjust, int /*y*/, unsigned count, const uint8_t* covers)
{
    uint8_t* p = ptr + (x + xAdjust);
    const uint8_t* const p_lineend = p + count;
    if (widgetAlpha == 0xFF)
    {
        const uint8_t color8 = LCD8bpp_BGRA2222::getNativeColor(painterColor);
        do
        {
            const uint8_t alpha = *covers++;
            if (alpha == 0xFF)
            {
                *p = color8;
            }
            else
            {
                *p = mixColors(painterRed, painterGreen, painterBlue, *p, alpha);
            }
            p++;
        } while (p < p_lineend);
    }
    else
    {
        do
        {
            const uint8_t alpha = LCD::div255((*covers++) * widgetAlpha);
            *p = mixColors(painterRed, painterGreen, painterBlue, *p, alpha);
            p++;
        } while (p < p_lineend);
    }
}

bool PainterBGRA2222::renderNext(uint8_t& red, uint8_t& green, uint8_t& blue, uint8_t& alpha)
{
    red = painterRed;
    green = painterGreen;
    blue = painterBlue;
    alpha = 0xFF;
    return true;
}
} // namespace touchgfx
