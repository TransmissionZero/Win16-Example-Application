# Win16 Example Application

## Table of Contents

- [Introduction](#introduction)
- [Building the Application](#building-the-application)
- [Terms of Use](#terms-of-use)
- [Known Problems](#known-problems)
- [Changelog](#changelog)

## Introduction

This application is an example 16 bit Windows application written in C. It
accompanies the
[Building Win16 GUI Applications in C](http://www.transmissionzero.co.uk/computing/win16-apps-in-c/)
article on [Transmission Zero](http://www.transmissionzero.co.uk/).

The application runs under Windows 3.0 to Windows ME, and all versions of
Windows NT which support Win16 apps (Windows NT 3.1 to at least the x86 version
of Windows 10). It does not run under Windows 1 or 2, but there is a
[Windows 1 Version](https://github.com/TransmissionZero/Windows-1-Example-Application)
which is compatible with Windows 1 and 2 (but not compatible with Windows 9x).

The application can be built using Visual C++ 1.5x. You can
[download Visual C++ 1.52](https://my.visualstudio.com/Downloads?pid=140) if you
have a Visual Studio Subscription. If you don't have a subscription, you can
download the
[Windows Server 2003 DDK](http://download.microsoft.com/download/9/0/f/90f019ac-8243-48d3-91cf-81fc4093ecfd/1830_usa_ddk.iso)
which contains the 16 bit command line tools (most of which are from Visual C++
1.52). The 16 bit binaries can be found in "bin\bin16" of the installed DDK,
include files in "inc\inc16", and lib files in "lib\lib16". A number of the
binaries come in two versions, one with and one without a "16" suffix, e.g.
"cl.exe" and "cl16.exe". Despite the different filenames, the file contents are
identical.

The application can also be built with [Open Watcom](http://openwatcom.org/),
which is free to download.

With a few small changes to the Makefile, the application will build with
Microsoft C / C++ 7.0 and the Windows 3.1 SDK. It won't build  with the Windows
3.0 SDK because the headers don't define some of the required types, and it does
not have the "ver.h" header which is required for the version information
resource.

## Building the Application

To build the application with the Microsoft Visual C++ 1.5x GUI, go to
"project", "open", then open "Win16App.mak". To choose a debug or release build,
go to "options" then "project". The project can be built using the "build" or
"rebuild" toolbar items, or via the "project" menu.

To build the application from the command line with Visual C++ 1.5x, launch a
command prompt, run the "MSVCVARS.BAT" file which can be found in the Visual C++
"bin" directory, and then navigate to the directory containing the Makefile. Run
"nmake /f Win16App.mak" to build. This also works with the Windows Server 2003
DDK, but instead of running "MSVCVARS.BAT", you will need to add the "bin16"
directory to your "%PATH%" environment variable, "inc16" to "%INCLUDE%", and
"lib16" to "%LIB%".

To build the application in [Open Watcom](http://openwatcom.org/), open the
project up in the IDE, and choose the "Make" option from the "Targets" menu. You
can switch between debug and release builds by going to "Targets", "Target
Options", and choosing "Use Development Switches" or "Use Release Switches".

## Terms of Use

Refer to "License.txt" for terms of use.

## Known Problems

The Open Watcom build of the application doesn't work correctly under Windows
3.0 when running in Real Mode. The application will start but the menu is
missing and the about dialog won't display. I've found Open Watcom to be a bit
hit and miss, where certain seemingly harmless changes of compiler option result
in an application which crashes, so it may be possible to fix this by changing
the compiler options. It runs fine under Windows 3.0 in Standard Mode and 386
Enhanced Mode.

The Open Watcom build of the application has optimisations switched off. With
optimisations enabled, the application crashes on startup.

If you have any other problems or questions, please ensure you have read this
readme file and the
[Building Win16 GUI Applications in C](http://www.transmissionzero.co.uk/computing/win16-apps-in-c/)
article. If you are still having trouble, you can
[get in contact](http://www.transmissionzero.co.uk/contact/).

## Changelog

5. 2017-05-21: Version 1.4
  - Removed unnecessary whitespace from source files.
  - Corrected min / max window size handling, which should have been using a far
    pointer for the MINMAXINFO struct.
  - Removed the original Makefile as it just duplicates the functionality of the
    Visual C++ Makefile.
  - Various updates to compiler and linker options to ensure consistency between
    Visual C++ and Open Watcom builds.

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
2017-05-21
