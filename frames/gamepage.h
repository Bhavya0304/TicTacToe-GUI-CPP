#pragma once
#include<wx/wx.h>
#include "id.h"
#include "mainframe.h"
#include<string>

namespace app{


class GamePage: public wxPanel{
    public:
        MainFrame *parent;
        wxStatusBar* bar;
        char game_board[3][3];
        char currentPlayer;
        wxButton* grid_btns[9]; 
        GamePage(MainFrame *parent,wxWindowID id);
        void onMove(wxCommandEvent& event);
        void btn_to_board(int i);
        void isWon();
        void returnBack();
        void get_board_ready();
        int str_to_int(std::string strobj);
        void printBoard();
        void setStatusPlayer(wxStatusBar* bar);
        void isGameOver();
};
}