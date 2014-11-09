#include <windows.h>  
#include "mainwnd.h"
#include "resource.h"
#include "globals.h"

/* Global instance handle */
HINSTANCE g_hInstance = NULL;

/* Our application entry point */
int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{      
  HWND hWnd;
  HACCEL hAccelerators;
  MSG msg;

  /* Assign global HINSTANCE */
  g_hInstance = hInstance;

  /* Register our main window class */   
  if (! hPrevInstance)
  {
    if (! RegisterMainWindowClass())
    {
      MessageBox(NULL, "Error registering main window class.", "Error", MB_ICONHAND | MB_OK);
      return 0;
    }    
  }

  /* Create our main window */
  if (! (hWnd = CreateMainWindow()))
  {
    MessageBox(NULL, "Error creating main window.", "Error", MB_ICONHAND | MB_OK);
    return 0;
  } 
    
  /* Load accelerators */
  hAccelerators = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR));

  /* Show main window and force a paint */
  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);

  /* Main message loop */
  while(GetMessage(&msg, NULL, 0, 0) > 0)
  {
    if (! TranslateAccelerator(msg.hwnd, hAccelerators, &msg))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
  }

  return (int) msg.wParam;
}
