Bit Inspector is a graphical Qt front-end for libbitconvert.  Bit Inspector
converts 1s and 0s from magnetic stripes into more meaningful information, such
as names and card numbers.

To build and run Bit Inspector on Ubuntu 9.04, execute the following commands:

$ sudo apt-get install build-essential libpcre3-dev libqt4-dev git-core
$ git clone git://github.com/ossguy/libbitconvert.git
$ git clone git://github.com/ossguy/bitinspector.git
$ cd libbitconvert
$ make
$ cd ../bitinspector
$ ./autogen.sh
$ make
$ ./bitinspector

Build instructions for other Unix-like operating systems should be similar.  If
you encounter any problems building libbitconvert or Bit Inspector, please let
Denver Gingerich know at denver@ossguy.com.

Windows and Mac OS X build instructions will be added soon.

--
  Copyright (C) 2009  Denver Gingerich <denver@ossguy.com>

  Copying and distribution of this file, with or without modification,
  are permitted in any medium without royalty provided the copyright
  notice and this notice are preserved.
