# Microsoft Visual C++ generated build script - Do not modify

PROJ = WIN16APP
DEBUG = 0
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = /d_DEBUG 
R_RCDEFINES = /dNDEBUG 
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = UNKNOWN
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC = ABOUTDLG.C  
FIRSTCPP =             
RC = rc
CFLAGS_D_WEXE = /nologo /W3 /Gf /Zi /Od /D "WINVER"="0x0300" /D "_DEBUG" /FR /GA /GEs /GEm /Fd"WIN16APP.PDB"
CFLAGS_R_WEXE = /nologo /W3 /Gf /O1 /D "WINVER"="0x0300" /D "NDEBUG" /FR /GA /GEs /GEm
LFLAGS_D_WEXE = /NOLOGO /NOD /PACKC:61440 /ALIGN:16 /ONERROR:NOEXE /CO  
LFLAGS_R_WEXE = /NOLOGO /NOD /PACKC:61440 /ALIGN:16 /ONERROR:NOEXE  
LIBS_D_WEXE = oldnames libw slibcew commdlg.lib olecli.lib olesvr.lib shell.lib 
LIBS_R_WEXE = oldnames libw slibcew commdlg.lib olecli.lib olesvr.lib shell.lib 
RCFLAGS = /nologo 
RESFLAGS = /nologo /30 
RUNFLAGS = 
DEFFILE = WIN16APP.DEF
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WEXE)
LFLAGS = $(LFLAGS_D_WEXE)
LIBS = $(LIBS_D_WEXE)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_WEXE)
LFLAGS = $(LFLAGS_R_WEXE)
LIBS = $(LIBS_R_WEXE)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = ABOUTDLG.SBR \
		MAINWND.SBR \
		WINMAIN.SBR


ABOUTDLG_DEP = aboutdlg.h \
	globals.h \
	resource.h


MAINWND_DEP = aboutdlg.h \
	globals.h \
	mainwnd.h \
	resource.h


RESOURCE_RCDEP = resource.h \
	app.ico


WINMAIN_DEP = globals.h \
	mainwnd.h \
	resource.h


all:	$(PROJ).EXE $(PROJ).BSC

ABOUTDLG.OBJ:	ABOUTDLG.C $(ABOUTDLG_DEP)
	$(CC) $(CFLAGS) $(CCREATEPCHFLAG) /c ABOUTDLG.C

MAINWND.OBJ:	MAINWND.C $(MAINWND_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c MAINWND.C

RESOURCE.RES:	RESOURCE.RC $(RESOURCE_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r RESOURCE.RC

WINMAIN.OBJ:	WINMAIN.C $(WINMAIN_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c WINMAIN.C


$(PROJ).EXE::	RESOURCE.RES

$(PROJ).EXE::	ABOUTDLG.OBJ MAINWND.OBJ WINMAIN.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
ABOUTDLG.OBJ +
MAINWND.OBJ +
WINMAIN.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) RESOURCE.RES $@
	@copy $(PROJ).CRF MSVC.BND

$(PROJ).EXE::	RESOURCE.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) RESOURCE.RES $@

run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
