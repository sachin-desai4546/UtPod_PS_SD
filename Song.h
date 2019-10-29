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
        void setTitle(string _title);
        void setArtist(string _artist);
        void setSize(int _size);
        static string getTitle(const Song &s);
        static string getArtist(const Song &s);
        static int getSize(const Song &s);
        static int compareArtist(const Song &s, const Song &s1);
        static int compareTitle(const Song &s, const Song &s1);
        static int compareSize(const Song &s, const Song &s1);
    ~Song();
};



#endif