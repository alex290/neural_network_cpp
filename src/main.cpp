#include "mainframe.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MainFrame *frame = new MainFrame();
    frame->Show(true);
    return true;
}