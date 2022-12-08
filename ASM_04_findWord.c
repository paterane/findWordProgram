/*
    Assignment: 4 
    Date: 12/8/2022
    Program Name: WordFinder
    Programmer: Peter Oo
*/
#include <stdio.h>

void wordUpper(char *word);
void wordLower(char *word);

int main(){
    char filename[20] = "example.txt"; // submit your file name to be searched through
    char theWord[50] = {'\0'};   // Don't want to change the case of the word.
    char theWordUpper[50] = {'\0'}; // to store uppercase word
    char wordFile[50] = {'\0'}; // to store word read from the File
    int wordCount = 0;
    FILE *fp;

    printf("Type the file name you want to search through: ");
    scanf(" %s", filename);

    printf("Please, input the word you want to find:[not more than 20 words] ");
    scanf(" %s", theWord);

    int i = 0;
    while(theWord[i] != '\0'){
        theWordUpper[i] = theWord[i]; // copy content of theWord to the WordUpper, don't want to update original array.
        i++;
    }

    wordUpper(theWordUpper);

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("[-] File not found!\n"); // file not found case
        return -1;
    }

    while(fscanf(fp, "%s", wordFile) != EOF){ // scan formatted string or word through the file
        int i = 0;
        int match = 1;
        wordUpper(wordFile);
        while(wordFile[i] != '\0' || theWordUpper[i] != '\0'){ // to stop searching if see '\0' @ shorter word
            if(theWordUpper[i] != wordFile[i]) match = 0;
            printf("._");  // searching animated.
            i++;
        }
        if(match == 1) wordCount++;
    }
    printf("\n"); // go next line after searching.

    if(wordCount == 0){
        printf("No match\tThe word '%s' is not found!\n",theWord);
    }
    else{
        if(wordCount == 1) printf("Only %d match: the word '%s' is found!", wordCount, theWord);
        else printf("%d matches: the words '%s' are found!", wordCount, theWord);
    }

    if(fp != NULL) fclose(fp);

    return 0;
}

///******************FUNCTIONS**********************///

void wordUpper(char *word){
    int i = 0;
    while(word[i] != '\0'){
        if(word[i] >= 97 && word[i] <= 122) word[i] -= 32;
        i++;
    }
}

///**************In case, lowercase to be used************///
void wordLower(char *word){
    int i = 0;
    while(word[i] != '\0'){
        if(word[i] >= 65 && word[i] <= 90) word[i] += 32;
        i++;
    }
}
