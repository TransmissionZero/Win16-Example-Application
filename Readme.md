# Win16 Example Application

## Table of Contents

- [Introduction](#introduction)
- [Terms of Use](#terms-of-use)
- [Known Problems](#known-problems)
- [Changelog](#changelog)

## Introduction

This application is an example 16 bit Windows application written in C. It
accompanies the
[Building Win16 GUI Applications in C](http://www.transmissionzero.co.uk/computing/win16-apps-in-c/)
article on [Transmission Zero](http://www.transmissionzero.co.uk/).

To build the application with Microsoft's Visual C++ compilers, open a command
prompt, change to the directory containing the Makefile, and run "nmake". Note
that you will need the 16 bit C compiler, linker, and resource compiler--this
won't work with 32 bit compilers! Also note that the Makefile may require some
small modifications if you use a make utility other than "nmake".

To build the application with the Microsoft Visual C++ GUI, open the
"Win16App.mak" file and build the application. You will need a version of Visual
C++ which supports building Win16 apps, for example Visual C++ 1.52 (available
from [MSDN](https://msdn.microsoft.com/subscriptions/downloads) if you have a
subscription).

To build the application in Open Watcom, open the project up in the IDE, and
choose the "Make" option from the "Targets" menu.

## Terms of Use

Refer to "License.txt" for terms of use.

## Known Problems

There is also a Windows 1 version of this application. If you try to launch this
application while the Windows 1 version is already running, you get a second
instance of the Windows 1 application instead! I can't find any reason why this
would happen, but I've tested the application on Windows 3.0 to Windows 8.1, and
it behaves the same across all of them.

The Open Watcom build of the application doesn't work correctly under Windows
3.0 when running in real mode. The application will start but the menu is
missing and the about dialog won't display. I've found Open Watcom to be a bit
hit and miss, where certain seemingly harmless changes of compiler option result
in an application which crashes, so it may be possible to fix this by changing
the compiler options.

If you have any other problems or questions, please ensure you have read this
readme file and the
[Building Win16 GUI Applications in C](http://www.transmissionzero.co.uk/computing/win16-apps-in-c/)
article. If you are still having trouble, you can
[get in contact](http://www.transmissionzero.co.uk/contact/).

## Changelog

4. 2014-11-09: Version 1.3
  - Added a Makefile project for use with the Visual C++ GUI.
  - Refactored some of the code to split the source code files by functionality.

3. 2013-09-07: Version 1.2
  - Removed superfluous LOWORD() macros which had been applied to WPARAMs.

2. 2013-08-26: Version 1.1
  - Added a VERSIONINFO resource to the executable, so that version information
    can be viewed in File Manager or Windows Explorer.
  - Open Watcom build now runs in Windows 3.0 (but not in real mode).
  - Ensured all source files are no more than 8.3 characters long.

1. 2011-07-06: Version 1.0
  - First release.

Transmission Zero
2016-08-27
