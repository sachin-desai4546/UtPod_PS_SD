#include <iostream>
#include "Song.h"
#include <string>

using namespace std;

Song::Song(){
    artist = "";
    title = "";
    size = 0;
}
Song::Song(string _artist, string _title, int _size) {
    if ((_artist != "") && (_title != "") && (_size > 0)){
        artist = _artist;
        title = _title;
        size = _size;
//    setArtist(_artist);
//    setTitle(_title);
//    setSize(_size);
    } else {
        cout << "Invalid Inputs" << endl;
    }
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
    } else {
        cout << "Invalid Inputs" << endl;
    }
}
void Song::setArtist(string _artist){
    if (artist != ""){
        artist = _artist;
    } else {
        cout << "Invalid Inputs" << endl;
    }
}
void Song::setSize(int _size){
    if (_size > 0){
        size = _size;
    } else {
        cout << "Invalid Inputs" << endl;
    }
}

bool Song::operator >(const Song &s){
    if (title > Song::getTitle(s)){
        return true;
    } else if (title < Song::getTitle(s)){
        return false;
    } else {
        if (artist > Song::getArtist(s)){
            return true;
        } else if (artist < Song::getTitle(s)){
            return false;
        } else {
            if (size > Song::getSize(s)){
                return true;
            } else {
                return false;
            }
        }
    }
}

bool Song::operator <(const Song &s){
    if (title < Song::getTitle(s)){
        return true;
    } else if (title > Song::getTitle(s)){
        return false;
    } else {
        if (artist < Song::getArtist(s)){
            return true;
        } else if (artist > Song::getTitle(s)){
            return false;
        } else {
            if (size < Song::getSize(s)){
                return true;
            } else {
                return false;
            }
        }
    }
}

bool Song::operator ==(const Song &s){
    return (title == s.title &&
            artist == s.artist &&
            size == s.size);
}

void Song::songSwap(Song &s) {
    string tempTitle = title;
    string tempArtist = artist;
    int tempSize = size;
    title = getTitle(s);
    artist = getArtist(s);
    size = getSize(s);
    s.setTitle(tempTitle);
    s.setArtist(tempArtist);
    s.setSize(tempSize);
}

Song::~Song(){}

