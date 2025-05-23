#pragma once

#include <FA2PP.h>
#include <map>
#include <vector>
#include <string>
#include <regex>
#include "../../Ext/CFinalSunDlg/Body.h"

// A static window class
class CCsfEditor
{
public:
    enum Controls {
        SelectedCSF = 1001, NewFile = 1002, Search = 1004, Add = 1005, Clone = 1006, Delete = 1007, CSFViewer = 1008, CSFEditor = 1009, Save = 1011, SetLabel = 1013, Reload = 1015, Apply = 1016
    };
    static void Create(CFinalSunDlg* pWnd);

    static HWND GetHandle()
    {
        return CCsfEditor::m_hwnd;
    }
    static bool OnEnterKeyDown(HWND& hWnd);

protected:
    static void Initialize(HWND& hWnd);
    static void Close(HWND& hWnd);
    static void Update(HWND& hWnd);
    static void InsertCSFContent(std::map<ppmfc::CString, ppmfc::CString> csfMap);
    static void FilterRows(std::map<ppmfc::CString, ppmfc::CString> csfMap, const char* searchText);
    static void OnEditchangeSearch();
    static void OnViewerSelectedChange(NMHDR* pNMHDR);
    static void OnClickApply();

    static BOOL CALLBACK DlgProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);


private:
    static HWND m_hwnd;
    static CFinalSunDlg* m_parent;

    static HWND hSelectedCSF;
    static HWND hNewFile;
    static HWND hSearch;
    static HWND hAdd;
    static HWND hClone;
    static HWND hDelete;
    static HWND hCSFViewer;
    static HWND hCSFEditor;
    static HWND hSave;
    static HWND hSetLabel;
    static HWND hReload;
    static HWND hApply;
public:
    static std::map<ppmfc::CString, ppmfc::CString>& CurrentCSFMap;
    static ppmfc::CString CurrentSelectedCSF;
    static ppmfc::CString CurrentSelectedCSFApply;
    static bool NeedUpdate;
    
};

