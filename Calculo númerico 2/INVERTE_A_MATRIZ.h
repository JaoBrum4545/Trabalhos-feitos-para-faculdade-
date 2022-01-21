#ifndef INVERTE_A_MATRIZ_H_INCLUDED
#define INVERTE_A_MATRIZ_H_INCLUDED

//O código que realiza a transição de A para A^-1 não é de minha autoria, segue abaixo a referencia:
	//GEEKSFORGEEKS. // C++ program to find adjoint and inverse of a matrix. Versão  [S. l.]: Geeksforgeeks.org. Disponível em: https://www.geeksforgeeks.org/adjoint-inverse-matrix/. Acesso em: 13 Julho 2021.	
#include "VETORES&MATRIZES.h"

// C++ program to find adjoint and inverse of a matrix
#include<bits/stdc++.h>
using namespace std;
 
// Function to get cofactor of A[p][q] in temp[][]. n is current
// dimension of A[][]
void getCofactor(float** A, float** temp, int p, int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
/* Recursive function for finding determinant of matrix.
   n is current dimension of A[][]. */
float determinant(float** A, int n)
{
    int D = 0; // Initialize result
 
    //  Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];
 
    float** temp = cria_matriz(n); // To store cofactors
 
    int sign = 1;  // To store sign multiplier
 
     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}
 
// Function to get adjoint of A[n][n] in adj[n][n].
void adjoint(float** A,float** adj,int n)
{
    if (n == 1)
    {
        adj[0][0] = 1.00;
        return;
    }
 
    // temp is used to store cofactors of A[][]
    int sign = 1;
    float** temp = cria_matriz(n);
 
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, n);
 
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;
 
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp, n-1));
        }
    }
}
 
// Function to calculate and store inverse, returns false if
// matrix is singular
bool inverse(float** A, float** inverse,int n)
{
    // Find determinant of A[][]
    int det = determinant(A, n);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }
 
    // Find adjoint
    float** adj = cria_matriz(n);
    adjoint(A, adj, n);
 
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            inverse[i][j] = adj[i][j]/float(det);
 
    return true;
}
 
// Generic function to display the matrix.  We use it to display
// both adjoin and inverse. adjoin is integer matrix and inverse
// is a float.
 
// Driver program
float** InverteMatriz(float** A,int n)
{
 
    float** adj = cria_matriz(n);  // To store adjoint of A[][]
 
    float** inv = cria_matriz(n); // To store inverse of A[][]
 
    adjoint(A, adj, n);
 
    if (inverse(A, inv,n))
    	
    return inv;
}


#endif
