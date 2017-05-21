#include "mainwnd.h"
#include "aboutdlg.h"
#include "resource.h"
#include "globals.h"

/* Main window class and title */
static const char MainWndClass[] = "Win16 Example Application";

/* Window procedure for our main window */
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch (msg)
  {
    case WM_COMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        case ID_HELP_ABOUT:
        {
          ShowAboutDialog(hWnd);
          break;
        }

        case ID_FILE_EXIT:
        {
          DestroyWindow(hWnd);
          break;
        }

        default:
          return DefWindowProc(hWnd, msg, wParam, lParam);
      }

      break;
    }

    case WM_GETMINMAXINFO:
    {
      /* Prevent our window from being sized too small */
      MINMAXINFO FAR* minMax = (MINMAXINFO FAR*) lParam;
      minMax->ptMinTrackSize.x = 220;
      minMax->ptMinTrackSize.y = 110;

      break;
    }

    /* Item from system menu has been invoked */
    case WM_SYSCOMMAND:
    {
      WORD id = wParam;

      switch (id)
      {
        case ID_HELP_ABOUT:
        {
          ShowAboutDialog(hWnd);
          break;
        }

        default:
          return DefWindowProc(hWnd, msg, wParam, lParam);
      }

      break;
    }

    case WM_DESTROY:
    {
      PostQuitMessage(0);
      break;
    }

    default:
      return DefWindowProc(hWnd, msg, wParam, lParam);
  }

  return 0;
}

/* Register a class for our main window */
BOOL RegisterMainWindowClass(void)
{
  WNDCLASS wc = {0};

  wc.lpfnWndProc   = &MainWndProc;
  wc.hInstance     = g_hInstance;
  wc.hIcon         = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_APPICON));
  wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH) (COLOR_BTNFACE + 1);
  wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MAINMENU);
  wc.lpszClassName = MainWndClass;

  return (RegisterClass(&wc)) ? TRUE : FALSE;
}

/* Create an instance of our main window */
HWND CreateMainWindow(void)
{
  HWND hWnd;
  HMENU hSysMenu;

  hWnd = CreateWindowEx(0, MainWndClass, MainWndClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                        320, 200, NULL, NULL, g_hInstance, NULL);

  if (hWnd)
  {
    /* Add "about" to the system menu */
    hSysMenu = GetSystemMenu(hWnd, FALSE);
    InsertMenu(hSysMenu, 5, MF_BYPOSITION | MF_SEPARATOR, 0, NULL);
    InsertMenu(hSysMenu, 6, MF_BYPOSITION, (UINT) ID_HELP_ABOUT, "About");
  }

  return hWnd;
}
