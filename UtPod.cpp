#include <iostream>

//DOCUMENT HERE

#include "UtPod.h"
#include "Song.h"

using namespace std;

UtPod::UtPod() {
    memSize = MAX_MEMORY;
};

//Constructor with size parameter
// The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
// set the size to MAX_MEMORY.
UtPod::UtPod(int size) {

};

/* FUNCTION - int addSong
 * * attempts to add a new song to the UtPod
 o returns a 0 if successful
 o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms -

 output parms -
*/
void UtPod::addSong(Song const &s){
    return;
};


/* FUNCTION - int removeSong
 * * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
 o returns 0 if successful
 o returns -1 if nothing is removed


 input parms -

 output parms -
*/
int UtPod::removeSong(Song const &s){

};


/* FUNCTION - void shuffle
 *  shuffles the songs into random order
 o will do nothing if there are less than two songs in the current list

 input parms -

 output parms -
*/
void UtPod::shuffle(){

};


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

 input parms -

 output parms -
*/
void UtPod::showSongList(){

};


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
 o will do nothing if there are less than two songs in the current list

 input parms -

 output parms -
*/
void UtPod::sortSongList(){

};

/* FUNCTION - void clearMemory
 * clears all the songs from memory

 input parms -

 output parms -
*/
void UtPod::clearMemory(){

};



/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs
 input parms -

 output parms -
*/
int UtPod::getRemainingMemory(){

};

UtPod::~UtPod();