/*
This is a block style comment. Any text written inbetween the slash (/) and star (*) 
is ignored by the compiler. Comments are super useful for explaining what your program 
does to anyone who reads it.

^ You may delete the instructions above this line ^

Program Name: [Michael's Jukebox]

Author: [Michael Anyaegbunam]

Program Description:
[This code is a jukebox that takes user input and returns the chosen song with lyrics included!]

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_SONGS 5
// Every C program must contain a main() function
struct Songs{                   //Here the struct is used to intialize the contents of each variable. I chose a larger 1000 bit limit.
	char artist[1000];
	char title[1000];
	char album[1000];
	char file[1000];
};

void JukeboxMenu(struct Songs songs[]) {  //Initialize the Menu- Here I wanted to get as close as possible to Hawamdeh's menu. The "%-15" is used to create a 15 space width around each column of the table
	printf("\nWelcome to Michael Anyaegbunam's Lyric Jukebox\n!");
	printf("Please select a track from the list below:\n ");
	printf("| %-15s | %-15s | %-15s |\n", "Artist", "Song", "Album");
	printf("------------------------------------------------------\n");

	for (int i = 0; i < NUM_SONGS; i++) {   // If i is less than the number of songs, add the song, artist, title and album name
		printf("| %-20s | %-20s | %-20s |\n", songs[i].artist, songs[i].title, songs[i].album);
	}


}

void Lyrics(char* filename) {  // basic syntax 
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("We dont have a song here with that name. Try Again.");
		return;
	}
    
	char length[1000];
	while (fgets(length, sizeof(length), file)) {
		printf("%s", length);
		sleep(1);

	}
    fclose(file);
}



int main(void) {
	struct Songs songs[NUM_SONGS] = {
		{"The Smiths", "I Know It's Over", "The Queen is Dead", "I"},
		{"Vansire", "Metamodernity", "Metamodernity", "Metamodernity"},
		{"Mac Demarco", "No Other Heart", "Another One", "No"},
		{"Nas", "The World is Yours", "Illmatic", "The"},
		{"Bjork", "Unison", "Vespertine", "U"}



	};

	int userchoice;
	while (1) {  //While true, where 1 = true. I almost messed up here by typing "while True"
		JukeboxMenu(songs);
		printf("Enter a song to play or click 0 to quit: ");
		scanf("%d", &userchoice);

		if (userchoice == 0) {
			printf("Exited Michael's Jukebox!\n");
			break;
		
			
		} else if (userchoice > 0 && userchoice <= NUM_SONGS) { // Prints the song details
			printf("\nPlaying %s - %s\n\n", songs[userchoice - 1].artist, songs[userchoice - 1].title);
			Lyrics(songs[userchoice - 1].file);

		} else {
			printf("Choose a valid song. Try Again.\n");
		}

	}


	

    return 0;
}