Win16 Example Application

This application is an example 16 bit Windows application written in C. It
accompanies an article from my web site, located at
http://www.transmissionzero.co.uk/computing/win16-apps-in-c/.

To build the application with Microsoft’s Visual C++ compilers, open a command
prompt, change to the directory containing the Makefile, and run “nmake”. Note
that you will need the 16 bit C compiler, linker, and resource compiler—it won’t
work with 32 bit compilers! Also note that the Makefile may require some small
modifications if you use a make utility other than “nmake”.

To build the application with the Microsoft Visual C++ GUI, open the
“Win16App.mak” file and build the application. You will need a version of Visual
C++ which supports building Win16 apps, for example Visual C++ 1.52 (available
from MSDN if you have a subscription).

To build the application in Open Watcom, open the project up in the IDE, and
choose the “Make” option from the “Targets” menu.


Disclaimer

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.


Terms of Use

There is no specific license attached to the use this application. You are free
to use it however you see fit, whether for commercial or non-commercial
purposes. The intention is that you use it as a starting point for building
Windows applications, so that you don’t have to write all of your applications
from scratch. You are encouraged to modify it to suit your needs as a Windows
application template, and how you license any applications built with it is
entirely up to you. Of course, you must still comply with the licensing
conditions of the tools you are using to build the application.


Known Problems

If you try to launch this application while the Windows 1 version of the
application is already running, you get a second instance of the Windows 1
application instead! I can’t find any reason why this would happen, but I’ve
tested the application on Windows 3.0 to Windows 8.1, and it behaves the same
across all of them.

The Open Watcom build of the application doesn’t work correctly under Windows
3.0 when running in real mode. The application will start but the menu is
missing and the about dialog won’t display. I’ve found Open Watcom to be a bit
hit and miss, where certain seemingly harmless changes of compiler option result
in an application which crashes, so it may be possible to fix this by changing
the compiler options.

If you have any other problems or questions, please get in contact via
http://www.transmissionzero.co.uk/contact/. Please ensure that you read the
article at http://www.transmissionzero.co.uk/computing/win16-apps-in-c/ before
sending any questions.


Changelog

2014-11-09: Version 1.3
  • Added a Makefile project for use with the Visual C++ GUI.
  • Refactored some of the code to split the source code files by functionality.

2013–09-07: Version 1.2

  • Removed superfluous LOWORD() macros which had been applied to WPARAMs.

2013–08–26: Version 1.1

  • Added a VERSIONINFO resource to the executable, so that version information
    can be viewed in File Manager or Windows Explorer.
  • Open Watcom build now runs in Windows 3.0 (but not in real mode).
  • Ensured all source files are no more than 8.3 characters long.

2011–07–06: Version 1.0

  • First release.

Transmission Zero
2014-11-09
