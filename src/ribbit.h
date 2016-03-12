/***************************************************************************
 *      WELCOME, FRIEND
 *          _     _
 *         /@\---/@\
 *       ,'         `.
 *      |             |
 *      <`-----------'>
 *     / `. `-----' ,' \
 *    /    `-------'    \
 *    :  |   _______   | :
 *    |  `.,'       `.,' |
 *   ,`.   \    o    /   '.
 *  /   `.  `.     ,'  ,'  \
 * ^^^^----^^^^-----^^^^---^^^^
 *
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2016 Ray Jenkins 
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 ***************************************************************************/

#ifndef __RIBBIT_H
#define __RIBBIT_H

#include "Croak.h"

typedef struct wise_amphibian {
  Croak_t *cache;
} FROG;


/* HOW TO CREATE YOUR FROG */
FROG * frog_init();

/* SAFELY DISPOSE OF FROG */
void frog_close(FROG *frog);

/* LOADING FROG IS SIMPLE */
void croak(FROG *frog);

/* WARNING - ONLY FOR FROG TESTING */
void load_croak(FROG *frog, FILE *fp);

/* STANDBY FOR IMPORTANT TIPS FROM FROG */
FrogTip_t * get_tip(FROG *frog);

#endif
