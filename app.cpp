
#include<wx/wx.h>
#include "app.h"
#include "frames/mainframe.h"

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit(){
    MainFrame* mf = new MainFrame(wxT("TicTacToe"));
    mf->Show(true);
    return true;
}