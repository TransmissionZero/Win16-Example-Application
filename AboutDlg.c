#include "aboutdlg.h"
#include "resource.h"
#include "globals.h"

/* Dialog procedure for our "about" dialog */
BOOL CALLBACK AboutDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
    case WM_COMMAND:
    {        
      WORD id = wParam;
    
      switch (id)
      {
        case IDOK:
        case IDCANCEL:
        {
          EndDialog(hwndDlg, id);
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

/* Show our "about" dialog */
void ShowAboutDialog(HWND owner)
{                  
  /* Create dialog callback thunk */
  FARPROC aboutProc = MakeProcInstance(&AboutDialogProc, g_hInstance);       
  
  DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_ABOUTDIALOG), owner, aboutProc);  
  
  /* Free dialog callback thunk */
  FreeProcInstance(aboutProc);  
}
