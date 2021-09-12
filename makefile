platform = Win16
CC = wcc
CFLAGS = -zW
res1_flags = -bt=windows -30

!include Win16App.mif
!include master.mif

linkit : .PROCEDURE
    @%append $(LNK) system windows

bindit : .PROCEDURE
    wrc $(RCINCS) Resource.rc Win16App.exe
