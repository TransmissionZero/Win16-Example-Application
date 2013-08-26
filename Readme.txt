Win16 Test Application

This application is an example 16 bit Windows application written in C. It
accompanies an article from my web site, located at
http://www.transmissionzero.co.uk/computing/win16-apps-in-c/.

To build the application with Microsoft’s Visual C++ compilers, simply open a
command prompt, change to the directory containing the Makefile, and run
“nmake”. Note that you will need the 16 bit C compiler, linker, and resource
compiler—it won’t work with 32 bit compilers! Also note that the Makefile may
require some small modifications if you use a make utility other than “nmake”.

To build the application in Open Watcom, simply open the project up in the IDE,
and choose the “Make” option from the “Targets” menu.


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


Problems?

If you have any problems or questions, please get in contact via
http://www.transmissionzero.co.uk/contact/. Please ensure that you read the
article at http://www.transmissionzero.co.uk/computing/win16-apps-in-c/ before
sending any questions.


Changelog

2013–08–26: Version 1.1

  • Added a VERSIONINFO resource to the executable, so that version information
    can be viewed in File Manager or Windows Explorer.
  • Open Watcom build now runs in Windows 3.0 (but not in real mode).
  • Ensured all source files are 8.3 characters long.

2011–07–06: Version 1.0

  • First release.

Martin Payne
2013–08–26
