/* Homework 4: bigrams.c
 * Author: Mia Hoffmann Kamrat
 * Finds all the bigrams and their respective frequencies in an input. */

#include <stdio.h>

int main(){
  // Stores the number of instances of each bigram in an array and
  // initializes all counts to 0. 
  int count[256][256] = {0};
  // Initializes the old character to -1 as a placeholder (not on the ASCII
  // table) to indicate that no previous character exists when the first
  // character is read.
  char old = -1;
  // Stores the new character. 
  char new;

  // Variables to track the bigram with the highest frequency.
  int max = 0; // Initializes the max count to 0.
  char max_first; // First character in the current max bigram.
  char max_second; // Second character in the current max bigram.

  // Prompts the user to input a message.
  printf("Enter your message and press enter when done: ");

  // Reads the next character in the user input until that
  // character is a newline. 
  while((new = getchar()) != '\n'){
    // If there is a previous character, the count is increased
    // for that bigram.
    if(old != -1){  
      count[old][new]++;
    }
    // Updates the value of old so the next iteration will
    // look at the next pair.
    old = new; 
  }

  // Iterates through the rows of the array.
  for(int i=0; i<256; i++){
    // Iterates through the columns of the array.
    for(int j=0; j<256; j++){
      // Prints the current bigram and its associated frequency
      // if the bigram exists in the user input. 
      if(count[i][j] > 0){
        printf("\"%c%c\": %d\n", (char)i, (char)j, count[i][j]);
        // Updates the max information if the current bigram has
        // a larger count than the current max. 
        if(count[i][j] > max){
          max = count[i][j];
          max_first = (char)i;
          max_second = (char)j;
        }
      }
    }
  }

  // Prints the most common bigram if there are bigrams in the input.
  if(max > 0){
    printf("Most common bigram: \"%c%c\"\n",
           max_first, max_second);
  }else{
    // Prints message if input doesn't have enough characters for a bigram. 
    printf("The input did not contain any bigrams.\n");
  }

  return 0;
}
