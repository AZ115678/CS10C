#include <iostream>
#include "playlist.h"
using namespace std;

void PrintMenu(string);
void OutPut();

int main(){
    string playlistTitle;
    cout << "Enter playlist's title: " << endl;
    cin >> playlistTitle;
    PrintMenu(playlistTitle);

    return 0;
}

void PrintMenu(string playlistName){
    
    PlaylistNode p;
    char input = 'z';

    while(input != 'q'){
    cout << playlistName << " PLAYLIST MENU\n" << "a - Add song\n" << "d - Remove song\n" << "c - Change position of song\n"
    << "s - Output songs by specific artist\n" << "t - Output total time of playlist (in seconds)\n" << "o - Output full playlist\n"
    << "q - Quit\n" << "Choose an option: ";

    cin >> input;
    switch(input){
        case 'a':
            cout << "a selected" << endl;
            break;
        case 'd':
            cout << "a selected" << endl;
            break;
        case 'c':
            cout << "a selected" << endl;
            break;
        case 's':
            cout << "a selected" << endl;
            break;
        case 't':
            cout << "a selected" << endl;
            break;
        case 'o':
            p.PrintPlaylistNode();
            break;
        case 'q':
            break;
        default:
            break;
    }
}
    //delete p;

}