#ifndef __BASE_H
// Make sure to only declare these classes once
#define __BASE_H

// MainApp is the class for our application
class MainApp: public wxApp {
    public:
        // MainApp just acts as a container for the window, or frame in MainFrame
        virtual bool OnInit();
};

// MainFrame is the class for out window
class MainFrame: public wxFrame {
    // It contains the window and all objects in it
    public:
        MainFrame(const wxString &title, const wxPoint &pos,
            const wxSize &size);
            wxTextCtrl *MainEditBox;
            wxMenuBar *MainMenu;
            void Quit(wxCommandEvent& event);
            void NewFile(wxCommandEvent& event);
            void OpenFile(wxCommandEvent& event);
            void SaveFile(wxCommandEvent& event);
            void SaveFileAs(wxCommandEvent& event);
            void CloseFile(wxCommandEvent& event);

            DECLARE_EVENT_TABLE()
};

enum {
    TEXT_Main = wxID_HIGHEST + 1,
    MENU_New,
    MENU_Open,
    MENU_Close,
    MENU_Save,
    MENU_SaveAs,
    MENU_Quit
};

DECLARE_APP(MainApp)

#endif
