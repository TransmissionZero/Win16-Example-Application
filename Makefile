# This Makefile will build the Win16 test application.

HEADERS = Resource.h Callback.h
OBJS =	WinMain.obj Callback.obj
RES = Resource.res

CC = cl16.exe
CFLAGS = /nologo /c /D NDEBUG /D WINVER=0x0300 /G3swf /Os /W3 /Zp /FPi87
LINK = link16.exe
RC = rc16.exe
EXE = Win16App.exe
DEF = Win16App.def

all: Win16App.exe

Win16App.exe: $(OBJS) $(RES) $(DEF)
	$(LINK) /nologo /align:16 $(OBJS),$(EXE),,libw.lib slibcew.lib,$(DEF)
	$(RC) /nologo /30 $(RES) $(EXE)

clean:
	del $(OBJS) $(RES) $(EXE) Win16App.map

%.obj: %.c $(HEADERS)
	$(CC) $(CFLAGS) $<

Resource.res: Resource.rc App.ico Resource.h
	$(RC) /nologo /r resource.rc