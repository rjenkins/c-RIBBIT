
# RIBBIT

```

                           '.  ckO,
                         .xKOXXkkNko                            ';
                        0xoclodOkkKKKd;.      .       .        .... .
                        do'.  ':lxK0KkXWxkOOkOddl';;.  .  .      .,        ..;.
                         .:.     ,dxXOWKcxdKcxkkkdokOKll.. ..  .  ;   .  ..   '
             .    .       .c      'dx0OKddXKOdx0KXxcOxkNKo   '.   :. . .'
            . .. ;,      . c,      ::xdNkkdlxxkOdkkK000WXX0l'.'. .d.' ...''..
         ....... ,  ....  .;x'     .cxONkKXNO0K0KXKNKKXWWWNWNk:;.,d;,l','.'  . ...
        ...'',::c'.........c0Oc..  .'oOX0NOXkKx0XNXOxKWWWXXK0dl',l0dkc;;.... ... ..
       .....;cx.';.....,::;:xNN0l,..'';OXNKkdxNWKkkxXKOKKOXWKO0dokN0l;'.. .  .
      .....';oklccdodl:clllolONXKKl,,;;oNKO0kxNX0OKNXNXN0XKdxKKOdXWOx:,..
     .';:,'..':,.,,,,'......:XXNXxk::;.dNKX0ONXKxxOOkO0OOOKX0kkKXXkoc.
     ..,;::,,:;......''.':,;:,;dx';ld0xkOXKKkoclkkx0XX0OOxOkkXK0d:;,'..
             .    ...':clc::;,'',;lOKO000kxkOOxcllkdooOKxkKOkdc,,..
                   .,:;:ocooccllc::cc:;,',,'.....oo,.oc,'..
                            .......   ...'..    c'....
```
C RIBBIT library.

## Quick start

To build and install libribbit libraries

```
  ./configure
   make
   make install
```

Both static and dynamic libraries will be built and installed by default

```
rjenkins@rjenkins-VirtualBox:~/c-RIBBIT$ ls -lart /usr/local/lib/ | grep ribbit
-rwxr-xr-x  1 root root  437837 Mar 12 15:36 libribbit.so.0.0.0
lrwxrwxrwx  1 root root      18 Mar 12 15:36 libribbit.so.0 -> libribbit.so.0.0.0
lrwxrwxrwx  1 root root      18 Mar 12 15:36 libribbit.so -> libribbit.so.0.0.0
-rwxr-xr-x  1 root root    1001 Mar 12 15:36 libribbit.la
-rw-r--r--  1 root root  753180 Mar 12 15:36 libribbit.a
```

See ribbit.h for API 

```
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
``` 

See croak executable (src/croak_exec.c) for examples of how to use the library

```c
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
```

```
rjenkins@rjenkins-VirtualBox:~/c-RIBBIT$ croak
DUE TO UNEXPECTEDLY HIGH DEMAND OVER CHRISTMAS, FROG IS IN SHORT SUPPLY. YOU MAY HAVE TO HOLD OUT FOR FROG UNTIL THE END OF THE NIGHT.
```

## Dependencies

libcurl

```sudo apt-get install libcurl4-gnutls-dev```

If you want to run test make sure libcheck is installed

```sudo apt-get install check```

If you wish to rebuild from asn1 install asn1c

```
   sudo apt-get install asn1c
   cd src; asn1c ribbit.asn1
   cd ..; ./configure; make ; make install
```  
