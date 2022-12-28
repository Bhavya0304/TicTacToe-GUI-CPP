#pragma once

#include<wx/wx.h>

class MainFrame:public wxFrame{
    public:
        wxPanel* Startpanel;
        wxPanel* GamePanel;
        MainFrame(const wxString messege);
        void openGamePage();
        void openStartPage();
};