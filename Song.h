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
        void setTitle(string title);
        void setArtist(string artist);
        void setSize(int size);
        string getTitle() const {
            return title;
        }
        string getArtist() const {
            return artist;
        }
        int getSize() const {
            return size;
        }
    ~Song();
};



#endif