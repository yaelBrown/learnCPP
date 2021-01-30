//Use "stdafx.h" only, if using visual studio.

// #include "stdafx.h"

// Header file section

#include<stdio.h>

// Define the number of vertices in the graph

#define size 5

// Definition of the function to print the solution matrix

void printGraph(int outputGraph[][size]);

// Prints transitive closure of graph using Warshall's algorithm

void transitiveClosure(int inputGraph[][size])

{

//Declare the required variables

int outputGraph[size][size], i, j, k;

printf("The given graph is: \n");

//Initialise and print the given graph to find the

//transitive closure

for (i = 0; i < size; i++)

{

for (j = 0; j < size; j++)

{

outputGraph[i][j] = inputGraph[i][j];

printf("%d ", inputGraph[i][j]);

}

printf("\n");

}

//Use for loop to find the adjacency matrix

for (k = 0; k < size; k++)

{

//Print the reflexive closure matrix index

printf("\nReflexive closure matrix(%d)\n", k + 1);

// Pick all vertices one by one

for (i = 0; i < size; i++)

{

// Pick vertices and store in the

// above picked source

for (j = 0; j < size; j++)

{

// If vertex k is found in the path from i to j,

//then change the value of reach[i][j] is 1

outputGraph[i][j] = outputGraph[i][j] ||

(outputGraph[i][k] && outputGraph[k][j]);

printf("%d ", outputGraph[i][j]);

}

printf("\n");

}

}

// Print the transitive closure matrix

printGraph(outputGraph);

}

//Create a functoion printGraph() to print the matrix

void printGraph(int outputGraph[][size])

{

printf("\nThe transitive closure of the given graph is as ");

printf("follows:\n\n");

for (int i = 0; i < size; i++)

{

for (int j = 0; j < size; j++)

//Display the value of the outputGraph at index i, j

printf("%d ", outputGraph[i][j]);

printf("\n");

}

}

//main function to test the above functions

int main()

{

//Initialize the given graph

int inputGraph[size][size] = { { 0, 0, 0, 0, 1 },

{ 1, 0, 0, 0, 0 },

{ 0, 0, 1, 1, 0 },

{ 0, 0, 1, 0, 0 },

{ 1, 0, 1, 0, 1 }

};

// Print the transitive closure of the given graph

transitiveClosure(inputGraph);

//main method returns 0

return 0;

}