#include "playlist.h"
#include <iostream>
using namespace std;

PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string ID, string song, string artist, int length){
    uniqueID = ID;
    songName = song;
    artistName = artist;
    songLength = length;
    nextNodePtr = 0;
}

void PlaylistNode::PrintPlaylistNode(){
    cout << "stuff works" << endl;
}