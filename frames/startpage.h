#pragma once

#include<wx/wx.h>
#include "id.h"
#include "mainframe.h"

namespace app{


class StartPage: public wxPanel{
    public:
        StartPage(MainFrame *parent,wxWindowID id);
        MainFrame *parent;
        void onExit(wxCommandEvent& event);
        void onStart(wxCommandEvent& event);
};
}