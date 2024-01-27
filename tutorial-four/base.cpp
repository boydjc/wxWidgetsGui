#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif
#include "base.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(MENU_New, MainFrame::NewFile)
    EVT_MENU(MENU_Open, MainFrame::OpenFile)
    EVT_MENU(MENU_Close, MainFrame::CloseFile)
    EVT_MENU(MENU_Save, MainFrame::SaveFile)
    EVT_MENU(MENU_SaveAs, MainFrame::SaveFileAs)
    EVT_MENU(MENU_Quit, MainFrame::Quit)
END_EVENT_TABLE() 

IMPLEMENT_APP(MainApp) // A Macro that tells wxWidgets
// to create an instance of our application

bool MainApp::OnInit() {
    // Create an instance of our frame, or window
    MainFrame *MainWin = new MainFrame(_("Hello World!"),
                                wxDefaultPosition, wxSize(300, 200));

    MainWin->Show(true); // Show the window
    SetTopWindow(MainWin); // set MainWin as the main window
    return true;
}  

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) :
    wxFrame((wxFrame *) NULL, -1, title, pos, size) {

        CreateStatusBar(2);

        MainEditBox = new wxTextCtrl(this, TEXT_Main, _T(""), 
                                    wxDefaultPosition, wxDefaultSize, 
                                    wxTE_MULTILINE | wxTE_RICH, 
                                    wxDefaultValidator, wxTextCtrlNameStr);

        MainMenu = new wxMenuBar();
        wxMenu *FileMenu = new wxMenu();
        FileMenu->Append(MENU_New, "&New", "Create a new file");
        FileMenu->Append(MENU_Open, "&Open", "Open an existing file");
        FileMenu->Append(MENU_Close, "&Close", "Close the current document");
        FileMenu->Append(MENU_Save, "&Save", "Save the current document");
        FileMenu->Append(MENU_SaveAs, "Save &As", "Save the current document under a new file name");
        FileMenu->Append(MENU_Quit, "&Quit", "Quit the editor");
        /* Adds a menu item with the label "Quit", id of MENU_QUIT, and set the
        status bar caption to "Quit the editor" when the mouse hovers over it.
        We can also use FileMenu->AppendSeparator() to add a menu separator */

        MainMenu->Append(FileMenu, "&File");
        SetMenuBar(MainMenu);

        Maximize();
}

void MainFrame::NewFile(wxCommandEvent& WXUNUSED(event)) {

}

void MainFrame::OpenFile(wxCommandEvent& WXUNUSED(event)) {
    MainEditBox->LoadFile("base.h");
}

void MainFrame::CloseFile(wxCommandEvent& WXUNUSED(event)) {
    MainEditBox->Clear();
}

void MainFrame::SaveFile(wxCommandEvent& WXUNUSED(event)) {
    MainEditBox->SaveFile("base.h");
}

void MainFrame::SaveFileAs(wxCommandEvent& WXUNUSED(event)) {

}

void MainFrame::Quit(wxCommandEvent& WXUNUSED(event)) {
    Close(true);
}


