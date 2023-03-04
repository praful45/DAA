// Floyd-Warshall Algorithm in C++

#include <iostream>
using namespace std;

// defining the number of vertices
#define nV 3

#define INF 999

void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
    cout<< "\n\nD"<<k+1<<":" <<endl;
    printMatrix(matrix);
  }
}

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
          cout<< "\tINF";
      else
          cout <<"\t"<<matrix[i][j];
    }
    cout << endl;
  }
}

int main() {
    int graph[nV][nV] = {   {0, 4, 13},
                            {8, 0, 2},
                            {3, INF, 0},
                        };
    cout<< "\nD0:" <<endl;
    printMatrix(graph);
  floydWarshall(graph);
}

