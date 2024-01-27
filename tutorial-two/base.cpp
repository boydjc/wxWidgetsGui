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

    /* challenge code */
    MainFrame *secondWin = new MainFrame(_("Window Two"),
                                wxDefaultPosition, wxSize(300, 200));
    secondWin->Show(true);
    /* end challenge code */

    MainWin->Show(true); // Show the window
    SetTopWindow(MainWin); // set MainWin as the main window
    return true;
}

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) :
    wxFrame((wxFrame *) NULL, -1, title, pos, size) {
    // normally we would initialize objects such as buttons and textboxes here
}