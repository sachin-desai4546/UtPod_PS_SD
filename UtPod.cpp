#include <iostream>

//DOCUMENT HERE

#include "UtPod.h"
#include "Song.h"
#include <string>

using namespace std;

UtPod::UtPod() {
    songs -> next = NULL;
    memSize = MAX_MEMORY;
};

//Constructor with size parameter
// The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
// set the size to MAX_MEMORY.
UtPod::UtPod(int size) {
    if ((size > MAX_MEMORY) || (size <= 0)){
        memSize = MAX_MEMORY;
    } else {
        memSize = size;
    }
};

/* FUNCTION - int addSong
 * * attempts to add a new song to the UtPod
 o returns a 0 if successful
 o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms -

 output parms -
*/
int UtPod::addSong(Song const &s){
    if (Song::getSize(s) < getRemainingMemory()){
        SongNode *temp = new SongNode;
        temp -> s = s;
        temp -> next = songs;
        songs = temp;
        return 0;
    } else {
        return -1;
    }
}


/* FUNCTION - int removeSong
 * * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
 o returns 0 if successful
 o returns -1 if nothing is removed


 input parms -

 output parms -
*/
int UtPod::removeSong(Song const &s){
    int count = 0;
    SongNode *temp = songs;
    SongNode *temp1;
    temp1 -> next = temp;
    while (temp1 -> next != NULL){
        if ((Song::compareSize(temp -> s, s) == 0) && (Song::compareTitle(temp -> s, s) == 0) && (Song::compareArtist(temp -> s, s) == 0) && (count == 0)){
            temp1 -> next = temp -> next;
            delete temp;
            count++;
        }
        temp1 = temp1 -> next;
        temp = temp -> next;
    }

}


/* FUNCTION - void shuffle
 *  shuffles the songs into random order
 o will do nothing if there are less than two songs in the current list

 input parms -

 output parms -
*/
void UtPod::shuffle(){

}


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

 input parms -

 output parms -
*/
void UtPod::showSongList(){
    string title;
    string artist;
    SongNode *temp = songs;
    while (temp -> next != NULL){
        title = Song::getTitle(temp -> s);
        artist = Song::getArtist(temp -> s);
        cout << title << " by " << artist << endl;
        temp = temp -> next;
    }
    title = Song::getTitle(temp -> s);
    artist = Song::getArtist(temp -> s);
    cout << title << " by " << artist << endl;
}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
 o will do nothing if there are less than two songs in the current list

 input parms -

 output parms -
*/
void UtPod::sortSongList() {
}

/* FUNCTION - void clearMemory
 * clears all the songs from memory

 input parms -

 output parms -
*/
void UtPod::clearMemory(){
    SongNode *temp = songs;
    SongNode *temp1 = songs;
    while (temp -> next != NULL){
        temp1 = temp -> next;
        delete temp;
        temp = temp1;
    }
    temp1 = temp -> next;
    delete temp;
}



/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs
 input parms -

 output parms -
*/
int UtPod::getRemainingMemory(){
    int total;
    SongNode *temp = songs;
    while (temp -> next != NULL){
        total += Song::getSize(temp -> s);
        temp = temp -> next;
    }
    total += Song::getSize(temp -> s);
    return (memSize - total);
}

UtPod::~UtPod(){}