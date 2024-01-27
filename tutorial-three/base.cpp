#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif
#include "base.h"

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

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    // Tell the OS to run MainFrame::OnExit when the button is pressed
    EVT_BUTTON(BUTTON_Hello, MainFrame::OnExit)
END_EVENT_TABLE()   

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) :
    wxFrame((wxFrame *) NULL, -1, title, pos, size) {
        // shows a button on this window with the text "Hello World"
        HelloWorld = new wxButton(this, BUTTON_Hello, _T("Hello World"),
                                    wxDefaultPosition, wxDefaultSize, 0);
}

void MainFrame::OnExit(wxCommandEvent& event) {
    // Tells the OS to quit running this process
    Close(true);
}