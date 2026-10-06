#include "playlist.h"
#include <iostream>
using namespace std;

PlaylistNode::PlaylistNode()
{
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string ID, string song, string artist, int length)
{
    uniqueID = ID;
    songName = song;
    artistName = artist;
    songLength = length;
    nextNodePtr = nullptr;
}

void PlaylistNode::InsertAfter(PlaylistNode *nodeLoc)
{
    PlaylistNode *tempNode = nullptr;
    tempNode = this->nextNodePtr;
    this->nextNodePtr = nodeLoc;
    nodeLoc->nextNodePtr = tempNode;
}

void PlaylistNode::SetNext(PlaylistNode *node)
{
    this->nextNodePtr = node;
}

string PlaylistNode::GetID()
{
    return uniqueID;
}

string PlaylistNode::GetSongName()
{
    return songName;
}

string PlaylistNode::GetArtistName()
{
    return artistName;
}

int PlaylistNode::GetSongLength()
{
    return songLength;
}

PlaylistNode *PlaylistNode::GetNext()
{
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode()
{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length(in seconds): " << songLength << endl;
}