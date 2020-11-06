/*****************************************************************************
* Code accompanying the Application Note:
* "Object-Oriented Programming in C"
* https://www.state-machine.com/doc/AN_OOP_in_C.pdf
*
* Copyright (C) 2005-2018 Quantum Leaps. All Rights Reserved.
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
* along with this program. If not, see <https://www.gnu.org/licenses/>.
*
* Contact Information:
* https://www.state-machine.com
****************************************************************************/

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

