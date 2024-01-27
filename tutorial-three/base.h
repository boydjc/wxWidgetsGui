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
            wxButton *HelloWorld;
            void OnExit(wxCommandEvent& event);

            DECLARE_EVENT_TABLE()
};

enum {
    // declates an id which will be used to call our button
    BUTTON_Hello = wxID_HIGHEST + 1 
};

DECLARE_APP(MainApp)

#endif
