/**************************************************************************$
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

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "ribbit.h"

int main() {

  void *handle;
  void (*croak)(FROG *);
  FROG *(*frog_init)(void);
  FrogTip_t *(*get_tip)(FROG *);
  void (*frog_close)(FROG *);

  handle = dlopen("libribbit.so.0", RTLD_LAZY);

  /* RUH ROH */
  if(!handle) {
    fputs(dlerror(), stderr);
    exit(1);
  }

  frog_init = dlsym(handle, "frog_init");
  frog_close = dlsym(handle, "frog_close");
  croak = dlsym(handle, "croak");
  get_tip = dlsym(handle, "get_tip");

  FROG *frog = (*frog_init)();

  /* BEGIN SEQUENCE */
  (*croak)(frog);

  /* JUST THE TIP */
  FrogTip_t *t = (*get_tip)(frog);
  printf("%s\n", t->tip.buf);

  return 0;

}
