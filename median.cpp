// Copyright (C) 2014 University of Kaiserslautern
// Microelectronic System Design Research Group
//
// This file is part of the FPGAHS Course
// de.uni-kl.eit.course.fpgahs
//
// Matthias Jung <jungma@eit.uni-kl.de>
// Christian De Schryver <schryver@eit.uni-kl.de>

#include"image.h"
#include<iostream>


using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(unsigned char arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) 
    { 
        key = arr[i]; 
        j = i - 1; 
  
        /* Move elements of arr[0..i-1], that are 
        greater than key, to one position ahead 
        of their current position */
        while (j >= 0 && arr[j] > key) 
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 


void medianFilter(const unsigned char input[][HEIGHT], unsigned char output[][HEIGHT], unsigned int width, unsigned int height)
{


unsigned char window[9];
unsigned char array[width][height];
int row = 0, col = 0;

    // Now print the array to see the result 
    for(row = 1; row < width-1; ++row) 
    { 
        for(col = 1; col < height-1; ++col) 
        { 
            //neighbor pixel values are stored in window including this pixel 
            window[0] = input[row-1][col-1]; 
            window[1] = input[row-1][col]; 
            window[2] = input[row-1][col+1]; 
            window[3] = input[row][col-1]; 
            window[4] = input[row][col]; 
            window[5] = input[row][col+1]; 
            window[6] = input[row+1][col-1]; 
            window[7] = input[row+1][col]; 
            window[8] = input[row+1][col+1]; 
  
            //sort window array 
            insertionSort(window,9);  
            //put the median to the new array 
            output[col][row]=window[4];     
           
        } 
       
    } 
// //    Move window through all elements of the image
//    for (int m = 1; m < height-1; ++m){
//       for (int n = 1; n < width-1; ++n)
//       {
//          //   Pick up window elements
//          int k = 0;
//          unsigned char window[9];
//          for (int j = m - 1; j < m + 2; ++j){
//                 //   std::cout << "j:"<< j << std::endl;
//             for (int i = n - 1; i < n + 2; ++i){
//             //  std::cout << "i:"<< i << std::endl;
//                  window[k++] = input[m][n];
//             }
//          }


//          //   Order elements (only half of them)
//          for (int j = 0; j < 5; ++j)
//          {
//             //   Find position of minimum element
//             int min = j;
//             for (int l = j + 1; l < 9; ++l)
//             if (window[l] < window[min])
//                min = l;
//             //   Put found minimum element in its place
//             const unsigned char temp = window[j];
//             window[j] = window[min];
//             window[min] = temp;
//          }
//          //   Get result - the middle element
//          output[m][n] = window[4];
//       }}
for(int i=0; i<=width-1; i++){  
        output[i][0] = 0;
        output[i][99] = 0;
        output[0][i] = 0;
        output[99][i] = 0;
    }
}

