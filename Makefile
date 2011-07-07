# This Makefile will build the Win16 test application.

HEADERS = resource.h callbacks.h
OBJS =	winmain.obj callbacks.obj
RES = resource.res

CC = cl16.exe
CFLAGS = /nologo /c /D WINVER=0x0300 /Gsw /Gf /G2 /Os /W2 /Zp
LINK = link16.exe
RC = rc16.exe
EXE = Win16App.exe
DEF = Win16App.def

all: Win16App.exe

Win16App.exe: $(OBJS) $(RES) $(DEF)
	$(LINK) /nologo /align:16 $(OBJS),$(EXE),,libw.lib slibcew.lib,$(DEF)
	$(RC) /nologo -30 $(RES) $(EXE)

clean:
	del $(OBJS) $(RES) $(EXE)

%.obj: %.c $(HEADERS)
	$(CC) $(CFLAGS) $<

resource.res: resource.rc App.ico resource.h
	$(RC) /nologo /r resource.rc