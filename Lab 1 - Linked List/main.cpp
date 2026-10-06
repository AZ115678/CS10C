/*
    Author: Adam Zavala
    Lab 1: Linked List
*/

#include <iostream>
#include <bits/stdc++.h>
#include "playlist.h"
using namespace std;

void PrintMenu(string);
void OutputPlaylist(PlaylistNode *, string);
void OutputByArtist(PlaylistNode *);
void OutputByLength(PlaylistNode *);
void AddSong(PlaylistNode *&);
void RemoveSong(PlaylistNode *&);
void ChangePosition(PlaylistNode *&);

int main()
{
    string playlistTitle;
    cout << "Enter playlist's title: " << endl;
    getline(cin, playlistTitle);
    PrintMenu(playlistTitle);

    return 0;
}

void PrintMenu(string playlistName)
{
    PlaylistNode *p;
    PlaylistNode *head = nullptr;
    PlaylistNode *curr = nullptr;
    PlaylistNode *last = nullptr;
    char input = 'z';

    while (input != 'q')
    {
        cout << playlistName << " PLAYLIST MENU\n"
             << "a - Add song\n"
             << "d - Remove song\n"
             << "c - Change position of song\n"
             << "s - Output songs by specific artist\n"
             << "t - Output total time of playlist (in seconds)\n"
             << "o - Output full playlist\n"
             << "q - Quit\n"
             << "Choose an option: ";

        cin >> input;
        switch (input)
        {
        case 'a':
            AddSong(head);
            break;
        case 'd':
            RemoveSong(head);
            break;
        case 'c':
            ChangePosition(head);
            break;
        case 's':
            OutputByArtist(head);
            break;
        case 't':
            OutputByLength(head);
            break;
        case 'o':
            if (head == nullptr)
            {
                cout << "Playlist is empty" << endl;
            }
            else
            {
                OutputPlaylist(head, playlistName);
            }
            break;
        case 'q':
            break;
        default:
            break;
        }
    }
    // delete p;
}

void OutputPlaylist(PlaylistNode *head, string playlistName)
{
    PlaylistNode *current = head;

    cout << playlistName << " - OUTPUT FULL PLAYLIST" << endl;

    for (int i = 1; current != nullptr; i++)
    {
        cout << i << "." << endl;
        current->PrintPlaylistNode();
        current = current->GetNext();
        cout << endl;
    }
}

void OutputByArtist(PlaylistNode *head)
{
    PlaylistNode *current = head;
    string name;

    cout << "OUTPUT SONGS BY SPECIFIC ARTISTS" << endl;
    cout << "Enter artist's name:" << endl;
    cin.ignore();
    getline(cin, name);

    for (int i = 1; current != nullptr; i++)
    {

        if (current->GetArtistName() == name)
        {
            cout << i << "." << endl;
            current->PrintPlaylistNode();
        }

        current = current->GetNext();
        cout << endl;
    }
}

void OutputByLength(PlaylistNode *head)
{
    PlaylistNode *current = head;
    int sum = 0;
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    while (current != nullptr)
    {
        sum += current->GetSongLength();
        current = current->GetNext();
    }
    cout << "Total time: " << sum << " seconds" << endl;
}

void AddSong(PlaylistNode *&head)
{
    PlaylistNode *newSong = nullptr;
    string id;
    string name;
    string artist;
    int length;
    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin.ignore();
    getline(cin, id);
    cout << "Enter song's name:" << endl;
    getline(cin, name);
    cout << "Enter artist's name:" << endl;
    getline(cin, artist);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> length;
    cin.ignore();
    newSong = new PlaylistNode(id, name, artist, length);
    if (head == nullptr)
    {
        head = newSong;
    }
    else
    {
        PlaylistNode *current = head;
        while (current->GetNext() != nullptr)
        {
            current = current->GetNext();
        }
        current->InsertAfter(newSong);
    }
}

void RemoveSong(PlaylistNode *&head)
{
    string id;

    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin.ignore();
    getline(cin, id);

    PlaylistNode *current = head;
    PlaylistNode *last = nullptr;
    while (current != nullptr)
    {
        if (current->GetID() == id)
        {
            if (current == head)
            {
                head = current->GetNext();
            }
            else
            {
                last->SetNext(current->GetNext());
            }
            cout << current->GetSongName() << " removed" << endl;
        }
        last = current;
        current = current->GetNext();
    }
}

void ChangePosition(PlaylistNode *&head)
{

    int pos1, pos2, nodes;
    PlaylistNode *current = head;
    PlaylistNode *swapNode = head;
    PlaylistNode *last = head;

    cout << "CHANGE POSITION OF SONG" << endl;
    cout << "Enter song's current position:" << endl;
    cin >> pos1;

    for (int i = 1; (current->GetNext() != nullptr && i < pos1); i++)
    {

        if (current->GetNext() != nullptr)
        {
            last = current;
            current = current->GetNext();
        }
    }

    if (current == head)
    {
        head = current->GetNext();
    }
    else
    {
        last->SetNext(current->GetNext());
    }

    cout << "Enter new position for song:" << endl;
    cin >> pos2;

    if (pos2 <= 1)
    {
        head = current;
        current->SetNext(swapNode);
    }
    else
    {
        last = head;
        for (int i = 1; (swapNode != nullptr && i < pos2); i++)
        {

            last = swapNode;
            swapNode = swapNode->GetNext();
        }

        if (current != swapNode)
        {
            PlaylistNode *temp = nullptr;
            if (swapNode == head)
            {
                head = current;
                current->SetNext(swapNode);
            }
            else if (swapNode == nullptr) // check if moving to tail
            {
                last->InsertAfter(current);
                // current->SetNext(swapNode);
            }
            else
            {
                last->InsertAfter(current);
                // current->SetNext(swapNode);
            }
            cout << current->GetSongName() << " moved to position " << pos2 << endl;
        }
    }
}