/**************************************************************************
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
#include "ribbit.h"

#include "curl/curl.h"
#include "Croak.h"
#include "ber_decoder.h"

struct FROG_t {
  Croak_t *cache;
};

/* SECRET STUFF */
static void free_cache(FROG *frog) 
{
  asn_DEF_Croak.free_struct(&asn_DEF_Croak, frog->cache, 0);
}

/* MORE SECRET STUFF */
static size_t processCroak(void *contents, size_t size, size_t nmemb, void *ptr)
{
  size_t realsize = size * nmemb;
  Croak_t *croak = ((FROG *)ptr)->cache;
  asn_dec_rval_t rval;

  ber_decode(0, &asn_DEF_Croak, (void **)&croak, contents, realsize);
  
  if(croak->list.count > 0) {
    ((FROG *)ptr)->cache = croak;
  }

  return realsize;
}

/**
 * LOADING FROG... 
 */
FROG *frog_init()
{
  FROG *frog = malloc(sizeof(struct FROG_t));
  return frog;
}

/**
 * GOODNIGHT SWEET PRINCE 
 */
void frog_close(FROG *frog)
{
  free_cache(frog);
  free(frog);
}

/**
 *  GET RANDOM TIP FOR FRIEND 
 */
FrogTip_t * get_tip(FROG *frog) 
{
  int random_tip = rand() % (frog->cache->list.count + 1);
  return (FrogTip_t *) frog->cache->list.array[random_tip];
}

/**
 * FROG TESTING ONLY
 */  
void load_croak(FROG *frog, FILE *fp)
{
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *string = malloc(fsize + 1);
  int rec = fread(string, fsize, 1, fp);

  processCroak(string, 1, fsize, frog);
}

/**
 * MAKE FROG GREAT AGAIN 
 */
void croak(FROG *frog) 
{
  assert(frog);

  if(frog->cache != NULL) {
    free_cache(frog);
    frog->cache = 0;
  }

  CURL *curl_handle;
  CURLcode res;
 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* init the curl session */ 
  curl_handle = curl_easy_init();
  assert(curl_handle);

  struct curl_slist *headers = NULL;

  /* der-stream please */
  headers = curl_slist_append(headers, "Accept: application/der-stream");
 
  /* specify URL to get */ 
  curl_easy_setopt(curl_handle, CURLOPT_URL, "http://frog.tips/api/1/tips/");
 
  /* send data to processCroak */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, processCroak);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)frog); 

  /* use our headers */
  curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);

  res = curl_easy_perform(curl_handle);
}
