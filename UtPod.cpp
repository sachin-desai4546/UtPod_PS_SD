#include <iostream>
#include <string>
#include <cstdlib>

//DOCUMENT HERE

#include "UtPod.h"
#include "Song.h"

using namespace std;

UtPod::UtPod() {
    songs = NULL;
    memSize = MAX_MEMORY;
    randSeed = 1;
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
 o returns a SUCCESS if successful
 o returns NO_MEMORY if not enough memory to add the song

 precondition: s is a valid Song

 input parms -

 output parms -
*/
int UtPod::addSong(Song const &s){
    if ((songs == NULL && Song::getSize(s) < memSize) || Song::getSize(s) < getRemainingMemory()){
        SongNode *temp = new SongNode;
        temp -> s = s;
        temp -> next = songs;
        songs = temp;
        return SUCCESS;
    } else {
        return NO_MEMORY;
    }
}


/* FUNCTION - int removeSong
 * * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
 o returns SUCCESS if successful
 o returns NOT_FOUND if nothing is removed


 input parms -

 output parms -
*/
int UtPod::removeSong(Song const &s){
    int count = 0;
    SongNode *currentLoc = songs;
    SongNode *nextLoc = songs -> next;
    SongNode *previousLoc = songs;

    while (currentLoc -> next != NULL){
        if (currentLoc -> s == s){
            if(currentLoc == songs){
                songs = nextLoc;
                delete currentLoc;
                return SUCCESS;
            }else{
                previousLoc -> next = currentLoc -> next;
                delete currentLoc;
                return SUCCESS;
            }
        }
        nextLoc = nextLoc -> next;
        currentLoc = currentLoc -> next;
        if(count > 0){
            previousLoc = previousLoc -> next;
        }
        count++;
    }
    if(currentLoc -> s == s){
        if(songs -> next == NULL){
            songs = NULL;
        }
        previousLoc -> next = NULL;
        delete currentLoc;
        return SUCCESS;
    }
    return NOT_FOUND;
}


/* FUNCTION - void shuffle
 *  shuffles the songs into random order
 o will do nothing if there are less than two songs in the current list

 input parms -

 output parms -
*/
void UtPod::shuffle(){
    if (songs == NULL){
        return;
    }
    int count = 0;
    for (SongNode *temp = songs; temp -> next != NULL; temp = temp -> next){
        count++;
    }
    count++;
    for (int swapCount = 0; swapCount < 50; swapCount++){
        int randNum1 = (rand() % count);
        SongNode *Num1 = songs;
        for (int num1Traverse = 0; num1Traverse < randNum1; num1Traverse++){
            Num1 = Num1 -> next;
        }
        int randNum2 = (rand() % count);
        SongNode *Num2 = songs;
        for (int num2Traverse = 0; num2Traverse < randNum2; num2Traverse++){
            Num2 = Num2 -> next;
        }
        Num1 -> s.songSwap(Num2 -> s);
    }

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
    if(songs == NULL){
        cout << "no songs" << endl;
        return;
    }
    while (temp->next != NULL) {
        title = Song::getTitle(temp->s);
        artist = Song::getArtist(temp->s);
        cout << title << " by " << artist << endl;
        temp = temp->next;
    }
    title = Song::getTitle(temp->s);
    artist = Song::getArtist(temp->s);
    if(title == "" || artist == ""){
        cout << "no songs" << endl;
    } else{
        cout << title << " by " << artist << endl;
    }

}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
 o will do nothing if there are less than two songs in the current list

 input parms -

 output parms -
*/
void UtPod::sortSongList() {
    if (songs == NULL) {
        cout << "no songs to sort" << endl;
        return;
    }
    for (SongNode *p1 = songs; p1 != NULL; p1 = p1 -> next){
        for (SongNode *p2 = songs; p2 != NULL; p2 = p2 -> next){
            if (p1 -> s < p2 -> s){
                p1 -> s.songSwap(p2 -> s);
            }
        }
    }
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
    int total = 0;
    SongNode *temp = songs;
    while (temp -> next != NULL){
        total += Song::getSize(temp -> s);
        temp = temp -> next;
    }
    total += Song::getSize(temp -> s);
    return (memSize - total);
}


UtPod::~UtPod(){
    clearMemory();
}