#include <iostream>
using namespace std;
class PlaylistNode{
    public:
        PlaylistNode();
        PlaylistNode(string, string, string, int);
        void InsertAfter();
        void SetNext();
        void GetID();
        void GetSongName();
        void GetArtistName();
        void GetSongLength();
        void GetNext();
        void PrintPlaylistNode();
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
};