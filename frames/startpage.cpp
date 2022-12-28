#include "startpage.h"
#include "mainframe.h"
#include<wx/wx.h>
#include "id.h"

StartPage::StartPage(MainFrame *parent,wxWindowID id):wxPanel(parent,id,wxDefaultPosition)
{
    this->parent = parent;
    wxBoxSizer* mainsizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* secondarysizer = new wxBoxSizer(wxVERTICAL);
    mainsizer->Add(secondarysizer,1,wxALIGN_CENTER_VERTICAL);


    this->SetSizer(mainsizer);
    
    
    wxButton* startbtn = new wxButton(this,Id_Startbtn,"Start",wxDefaultPosition,wxSize(150,40));
    secondarysizer->Add(startbtn,0,wxALIGN_CENTER_HORIZONTAL | wxALL,5);
    startbtn->Bind(wxEVT_BUTTON,&StartPage::onStart,this);
    startbtn->Show();
    
    
    wxButton* exitbtn = new wxButton(this,Id_Exitbtn,"Exit",wxDefaultPosition,wxSize(150,40));
    secondarysizer->Add(exitbtn,0,wxALIGN_CENTER_HORIZONTAL | wxALL,5);
    exitbtn->Bind(wxEVT_BUTTON,&StartPage::onExit,this);
    exitbtn->Show();  
}

void StartPage::onExit(wxCommandEvent& event){
    exit(1);
}


void StartPage::onStart(wxCommandEvent& event){
    this->parent->openGamePage();
}