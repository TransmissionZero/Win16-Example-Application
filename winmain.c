#include <windows.h>
#include "resource.h"
#include "callback.h"

// Our application entry point.
int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  WNDCLASS wc;
  LPCSTR MainWndClass = "Win16 Test Application";
  HWND hWnd;
  HACCEL hAccelerators;
  HMENU hSysMenu;
  MSG msg;

  if (! hPrevInstance)
  {
    // Class for our main window.
    wc.style         = 0;
    wc.lpfnWndProc   = &MainWndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPICON));
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) (COLOR_BTNFACE + 1);
    wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MAINMENU);
    wc.lpszClassName = MainWndClass;

    // Register our window classes, or error.
    if (! RegisterClass(&wc))
    {
      MessageBox(NULL, "Error registering window class.", "Error", MB_ICONHAND | MB_OK);
      return 0;
    }
  }
  
  // Create instance of main window.
  hWnd = CreateWindowEx(0, MainWndClass, MainWndClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                        320, 200, NULL, NULL, hInstance, NULL);

  // Error if window creation failed.
  if (! hWnd)
  {
    MessageBox(NULL, "Error creating main window.", "Error", MB_ICONHAND | MB_OK);
    return 0;
  }

  // Load accelerators.
  hAccelerators = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR));

  // Add "about" to the system menu.
  hSysMenu = GetSystemMenu(hWnd, FALSE);
  InsertMenu(hSysMenu, 5, MF_BYPOSITION | MF_SEPARATOR, 0, NULL);
  InsertMenu(hSysMenu, 6, MF_BYPOSITION, ID_HELP_ABOUT, "About");

  // Show window and force a paint.
  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);

  // Main message loop.
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
