#include <iostream>
#include "Song.h"
#include <string>

using namespace std;

Song::Song(){
    artist = "";
    title = "";
    size = 0;
}
string Song::getTitle(const Song &s) {
    return s.title;
}
string Song::getArtist(const Song &s) {
    return s.artist;
}
int Song::getSize(const Song &s) {
    return s.size;
}
void Song::setTitle(string _title){
    if (title != ""){
        title = _title;
    }
}
void Song::setArtist(string _artist){
    if (artist != ""){
        artist = _artist;
    }
}
void Song::setSize(int _size){
    if (_size > 0){
        size = _size;
    }
}
int Song::compareArtist(const Song &s, const Song &s1){
    if (s.artist > s1.artist){
        return(1);
    }
    if (s.artist == s1.artist){
        return(0);
    }
    if (s.artist < s1.artist){
        return(-1);
    }
}
int Song::compareTitle(const Song &s, const Song &s1){
    if (s.title > s1.title){
        return(1);
    }
    if (s.title == s1.title){
        return(0);
    }
    if (s.title < s1.title){
        return(-1);
    }
}

int Song::compareSize(const Song &s, const Song &s1){
    if (s.size > s1.size){
        return(1);
    }
    if (s.size == s1.size){
        return(0);
    }
    if (s.size < s1.size){
        return(-1);
    }
}

Song::~Song(){}



