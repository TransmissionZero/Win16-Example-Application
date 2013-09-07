#include "callback.h"
#include "resource.h"

// Window procedure for our main window.
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  static HINSTANCE hInstance;
  static FARPROC aboutProc;

  switch (msg)
  {
    case WM_COMMAND:
    {
      switch (wParam)
      {
        case ID_HELP_ABOUT:
        {
          DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUTDIALOG), hWnd, aboutProc);
          return 0;
        }

        case ID_FILE_EXIT:
        {
          DestroyWindow(hWnd);
          return 0;
        }
      }
      break;
    }

    case WM_GETMINMAXINFO:
    {
      MINMAXINFO *minMax = (MINMAXINFO*) lParam;
      minMax->ptMinTrackSize.x = 220;
      minMax->ptMinTrackSize.y = 110;

      return 0;
    }

    case WM_SYSCOMMAND:
    {
      switch (wParam)
      {
        case ID_HELP_ABOUT:
        {
          DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUTDIALOG), hWnd, aboutProc);
          return 0;
        }
      }
      break;
    }

    case WM_CREATE:
    {
      hInstance = ((LPCREATESTRUCT) lParam)->hInstance;

      // Make about dialog procedure thunk.
      aboutProc = MakeProcInstance(AboutDialogProc, hInstance);

      return 0;
    }

    case WM_DESTROY:
    {
      // Free about dialog procedure thunk.
      FreeProcInstance(aboutProc);

      PostQuitMessage(0);
      return 0;
    }
  }

  return DefWindowProc(hWnd, msg, wParam, lParam);
}


// Dialog procedure for our "about" dialog.
BOOL CALLBACK AboutDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
    case WM_COMMAND:
    {
      switch (wParam)
      {
        case IDOK:
        case IDCANCEL:
        {
          EndDialog(hwndDlg, wParam);
          return TRUE;
        }
      }
      break;
    }

    case WM_INITDIALOG:
      return TRUE;
  }

  return FALSE;
}
