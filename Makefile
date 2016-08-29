# This Makefile will build the Win16 Example application

CC = cl
CFLAGS = /nologo /c /D NDEBUG /D WINVER=0x0300 /G3swf /Os /W3 /Zp /FPi87
LINK = link
RC = rc

OBJS = WinMain.obj MainWnd.obj AboutDlg.obj

# Rules
all: Win16App.exe

Win16App.exe:
	$(LINK) /nologo /align:16 $(OBJS),Win16App.exe,,libw.lib slibcew.lib,Win16App.def
	$(RC) /nologo /30 Resource.res Win16App.exe

clean:
	if exist *.obj         del *.obj
	if exist *.res         del *.res
	if exist *.map         del *.map
	if exist Win16App.exe  del Win16App.exe

%.obj:
	$(CC) $(CFLAGS) $<

Resource.res:
	$(RC) /nologo /r Resource.rc

# Dependencies
Win16App.exe: $(OBJS) Resource.res Win16App.def
AboutDlg.obj: AboutDlg.c AboutDlg.h Resource.h Globals.h
MainWnd.obj:  MainWnd.c MainWnd.h AboutDlg.h Resource.h Globals.h
WinMain.obj:  WinMain.c MainWnd.h Resource.h Globals.h
Resource.res: Resource.rc App.ico Resource.h
