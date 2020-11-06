/*****************************************************************************
* Code accompanying the Application Note:
* "Object-Oriented Programming in C"
* https://www.state-machine.com/doc/AN_OOP_in_C.pdf
*
* Copyright (C) 2005-2017 Quantum Leaps. All Rights Reserved.
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
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h" /* the base class interface */

typedef struct {
    Shape super; /* <== inherits Shape */

    /* attributes added by this subclass... */
    uint16_t rad;
} Circle;

/* constructor */
void Circle_ctor(Circle * const me, int16_t x, int16_t y,
                 uint16_t rad);

#endif /* CIRCLE_H */
