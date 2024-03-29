#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/eddychu/Desktop/ds_algo
  make -f /Users/eddychu/Desktop/ds_algo/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/eddychu/Desktop/ds_algo
  make -f /Users/eddychu/Desktop/ds_algo/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/eddychu/Desktop/ds_algo
  make -f /Users/eddychu/Desktop/ds_algo/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/eddychu/Desktop/ds_algo
  make -f /Users/eddychu/Desktop/ds_algo/CMakeScripts/ReRunCMake.make
fi

