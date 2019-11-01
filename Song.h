#include <iostream>

//DOCUMENT HERE

#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

//Song class declaration
class Song {

    private:
        string title;
        string artist;
        int size;

    public:
        Song();
        Song(string artist, string title, int size);
        void setTitle(string title);
        void setArtist(string artist);
        void setSize(int size);
        static string getTitle(const Song &s);
        static string getArtist(const Song &s);
        static int getSize(const Song &s);
        bool operator >(const Song &s);
        bool operator <(const Song &s);
        bool operator ==(const Song &s);
        void songSwap(Song &s);
    ~Song();
};



#endif