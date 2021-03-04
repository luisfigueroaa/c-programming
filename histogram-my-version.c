/*
Histograma:

Horitzontal:	    Vertical
1:  ###		    ##
2:  #		    ##     ##
3:  ##		    ## ##  ##
^		    1   2   3 <--- numero de palabras
|
|
|
numero de palabras */

#include <stdio.h>

#define TRUE	1
#define FALSE	0

#define	BUFFER	100 // longitud maxima por palabra en el histograma

int main(){
    int i;
    char c;

    int histogram[BUFFER];
    int histogram_length = 0;

    int new_word = FALSE;
    int max_word_count = 0;

    int word_count_index = 0;

    // Initialize the histogram array with 0
    for(i = 0; i <= BUFFER; ++i){
	histogram[i] = 0;
    }

    // Count the words length and store in histogram array at the
    // specific index
    while((c = getchar()) != EOF){
	if(c == ' ' || c == '\t' || c == '\n'){
	    if(!new_word){
		new_word = TRUE;
		++histogram[word_count_index - 1];

		if(histogram[word_count_index - 1] > max_word_count){
		    max_word_count = histogram[word_count_index - 1];
		}

		if(histogram_length < word_count_index - 1){
		    histogram_length = word_count_index - 1;
		}
		word_count_index = 0;
	    }
	}
	else{
	    new_word = FALSE;
	    ++word_count_index;
	}
    }

    // Add in the histogram array an end of useful data char
    histogram[histogram_length + 1] = '$';

    putchar('\n');

    int column_index = 0;
    int line_index = 0;

    // Print horizontal histogram
    printf("Horizontal Histogram\n---------------------------\n");

    while(histogram[column_index] != '$'){
	printf("%3d: \t", column_index + 1);

	for(line_index = 0; line_index < histogram[column_index]; ++line_index){
	    putchar('#');
	}

	putchar('\n');

	++column_index;
    }

    putchar('\n');

    // Print a vertical histogram
    printf("Vertical histogram\n-------------------------\n");

    for (line_index = max_word_count; line_index >= 0; --line_index){
	column_index = 0;

	while(histogram[column_index] != '$'){
	    if(line_index == 0){
		printf("%2d ", column_index + 1);
	    }
	    else if (histogram[column_index] >= line_index){
		printf("## ");
	    }
	    else{
		printf("   ");
	    }

	    ++column_index;
	}

	putchar('\n');
    }
    return 0;
}