/*============================================================================
* Code accompanying the Article:
* "Object-Oriented Programming in C"
* https://github.com/QuantumLeaps/OOP-in-C
*
* Copyright (C) 2006-2023 Quantum Leaps, <state-machine.com>.
*
* SPDX-License-Identifier: MIT
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
============================================================================*/
#include "circle.h"  /* Circle class interface */
#include <stdio.h> /* for printf() */

/* NOTE: the "me" pointer has the type of the superclass to fit the vtable */
static uint32_t Circle_area_(Shape const * const me);
static void Circle_draw_(Shape const * const me);

/* constructor */
void Circle_ctor(Circle * const me, int16_t x, int16_t y,
                 uint16_t rad)
{
    static struct ShapeVtbl const vtbl = { /* vtbl of the Circle class */
        &Circle_area_,
        &Circle_draw_
    };
    Shape_ctor(&me->super, x, y); /* call the superclass' ctor */
    me->super.vptr = &vtbl; /* override the vptr */
    me->rad = rad;
}

/* Circle's class implementations of its virtual functions... */
static uint32_t Circle_area_(Shape const * const me) {
    Circle const * const me_ = (Circle const *)me; /* explicit downcast */
    /* pi is approximated as 3 */
    return 3U * (uint32_t)me_->rad * (uint32_t)me_->rad;
}

static void Circle_draw_(Shape const * const me) {
    Circle const * const me_ = (Circle const *)me; /* explicit downcast */
    printf("Circle_draw_(x=%d,y=%d,rad=%d)\n",
           Shape_getX(me), Shape_getY(me), me_->rad);
}

