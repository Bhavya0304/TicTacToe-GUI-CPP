
#include<wx/wx.h>
#include "mainframe.h"
#include "id.h"
#include "startpage.h"
#include "gamepage.h"

MainFrame::MainFrame(const wxString messege):wxFrame(NULL,wxID_ANY,messege,wxDefaultPosition,wxSize(350,400))
{
    StartPage* startpage = new StartPage(this,Id_Startpanel);
    startpage->Show();
    Center();
}

void MainFrame::openStartPage(){
    this->DestroyChildren();
    StartPage* startpage = new StartPage(this,Id_Startpanel);
    startpage->Show();
    this->Layout();
}

void MainFrame::openGamePage(){
    this->DestroyChildren();
    GamePage* gamepage = new GamePage(this,Id_Gamepanel);
    gamepage->Show();
    this->Layout();
}
