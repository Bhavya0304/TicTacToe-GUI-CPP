#include "gamepage.h"
#include<wx/wx.h>
#include "id.h"
#include "mainframe.h"
#include<string>

GamePage::GamePage(MainFrame *parent,wxWindowID id):wxPanel(parent,id,wxDefaultPosition){
    this->parent = parent;
    currentPlayer = 'X';

    wxGridSizer* mainsizer = new wxGridSizer(3,3,0,0);
    // bar = parent->CreateStatusBar();
    // setStatusPlayer(bar);
    this->SetSizer(mainsizer);
    for (int i = 0; i < 9; i++)
    {
        int id = str_to_int("5" + std::to_string(i));
        grid_btns[i] = new wxButton(this,id,wxT("-"),wxDefaultPosition);
        grid_btns[i]->Bind(wxEVT_BUTTON,&GamePage::onMove,this);
        grid_btns[i]->Show();
        mainsizer->Add(grid_btns[i],0,wxEXPAND);
    }
    get_board_ready();
}

        
void GamePage::get_board_ready(){
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            game_board[i][j] = '-';
        }
    }
}

void GamePage::onMove(wxCommandEvent& event){
    wxButton* btn = (wxButton*) event.GetEventObject();
    if(strcmp(btn->GetLabel(),"X") == 0 || strcmp(btn->GetLabel(),"O") == 0){
        wxMessageBox("Invalid Move","Error");
        return;
    }
    // int answer = wxMessageBox("Quit program?", "Confirm", wxYES_NO | wxCANCEL, parent);
    btn_to_board(event.GetId()%10);
    btn->SetLabel(currentPlayer);
    isWon();
    isGameOver();
    currentPlayer = currentPlayer == 'X' ? 'O' : 'X'; 
    // setStatusPlayer(bar);
}

void GamePage::isWon(){
    //[0,0],[0,1],[0,2]
    //[1,0],[1,1],[1,2]
    //[2,0],[2,1],[2,2]
    //[0,0],[1,0],[2,0]
    //[0,1],[1,1],[2,1]
    //[0,2],[1,2],[2,2]
    //[0,0],[1,1],[2,2]
    //[0,2],[1,1],[2,0]
    int flag = 0;
    if(game_board[0][0] == currentPlayer && game_board[0][1] == currentPlayer && game_board[0][2] == currentPlayer){
        flag = 1;
    }
    else if(game_board[1][0] == currentPlayer && game_board[1][1] == currentPlayer && game_board[1][2] == currentPlayer){
        flag = 1;
    }
    else if(game_board[2][0] == currentPlayer && game_board[2][1] == currentPlayer && game_board[2][2] == currentPlayer){
        flag = 1;
    }
    else if(game_board[0][0] == currentPlayer && game_board[1][0] == currentPlayer && game_board[2][0] == currentPlayer){
        flag = 1;
    }
    else if(game_board[0][1] == currentPlayer && game_board[1][1] == currentPlayer && game_board[2][1] == currentPlayer){
        flag = 1;
    }
    else if(game_board[0][2] == currentPlayer && game_board[1][2] == currentPlayer && game_board[2][2] == currentPlayer){
        flag = 1;
    }
    else if(game_board[0][0] == currentPlayer && game_board[1][1] == currentPlayer && game_board[2][2] == currentPlayer){
        flag = 1;
    }
    else if(game_board[0][2] == currentPlayer && game_board[1][1] == currentPlayer && game_board[2][0] == currentPlayer){
        flag = 1;
    }

    if(flag == 1){
        std::string player = "";
        player += currentPlayer;
        int answer = wxMessageBox(player + " Won", "Winner! Play Again?", wxYES_NO, parent);
        if(answer == wxYES){
            this->parent->openStartPage();
        }
        else{
            exit(0);
        }
    }
}

void GamePage::isGameOver(){
    int flag = 1;

    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(game_board[i][j] == '-'){
                flag = 0;
                break;
            }
        }
    }


    if(flag == 1){
        int answer = wxMessageBox("Its a Tie!", "Game Over! Play Again?", wxYES_NO, parent);
        if(answer == wxYES){
            this->parent->openStartPage();
        }
        else{
            exit(0);
        }
    }
}


int GamePage::str_to_int(std::string strobj){
    return stoi(strobj);
}

void GamePage::btn_to_board(int i){
    int start = i < 3 ? 0 : -1;
    start = start != -1 ? start : (i < 6 ? 1 : 2);
    int end = i % 3;
    game_board[start][end] = currentPlayer;
}

void GamePage::printBoard(){
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            std::cout<<game_board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void GamePage::setStatusPlayer(wxStatusBar* bar){
    std::string player = "";
    player += currentPlayer;
    wxString barstate = "Player " +  player + " turn!";
    bar->SetStatusText(barstate);
}


