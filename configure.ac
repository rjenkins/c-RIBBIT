AC_INIT([c-RIBBIT], 0.0.1)
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_PROG_LIBTOOL
AC_CONFIG_FILES([
  Makefile
  src/Makefile
  tests/Makefile])
AC_OUTPUT

PKG_CHECK_MODULES(libcurl, libcurl >= 7.0)
PKG_CHECK_MODULES([CHECK],[check >= 0.8.2],[have_check="yes"],
  AC_MSG_WARN(['Check' unit testing framework not found. It would be impossible to run unit tests!"])
  [have_check="no"])
