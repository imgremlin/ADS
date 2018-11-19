#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

	int chc = 0;
	int eqc = 0;

void insertionSort(int a[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = a[i]; 
       j = i-1; 
  	   chc++;
  	   eqc++;
       while (j >= 0 && a[j] > key) 
       { 
           a[j+1] = a[j]; 
           j = j-1; 
           eqc+=2;
           chc++;
       } 
       a[j+1] = key;
	   chc++; 
   } 
}

void quickSort(int a[], int left, int right) {
	
    int i = left, j = right;
    int tmp;
    int pivot = a[(left + right) / 2];
 
    //partition
    while (i <= j) {
        while (a[i] < pivot)
        {
        	i++;
        	eqc++;
		}
        
        while (a[j] > pivot)
        {
        	j--;
        	eqc++;
		}
        
        if (i <= j) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
            chc++;
        }
        eqc++;
    };
 
    //recursion 
    if (left < j)
    	quickSort(a, left, j);
    eqc++;
    
    if (i < right)
    	quickSort(a, i, right);
    eqc++;
}


void countSort(int a[], int n, int exp)
{
	int output[n], i, count[10] = {0};
	
	for (i = 0; i < n; i++)
	{
		count[(a[i] / exp) % 10]++;
		chc++;
		eqc++;
	}
		
		
	for (i = 1; i < 10; i++)
	{
		chc++;
		eqc++;
		count[i] += count[i-1];
	}
		
		
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		chc++;
		eqc++;
		count[(a[i] / exp) % 10]--;
	}
	
	for (i = 0; i < n; i++)
	{
		a[i] = output[i];
		chc++;
		eqc++;
	}
		
}
 
void radixsort(int a[], int n)
{
	int exp, i;
	int max = a[0];
	for(i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			chc++;
		}
		
		eqc++;
	}
				
	for (exp = 1; max/exp > 0; exp *= 10)
		countSort(a, n, exp);
}


int main() {
  srand(time(NULL));
  int i, j, max, n, min, k,maxp, minp, maxi, mini, temp;
  int choice = 0;
  printf("Input size of matrix: ");
  scanf("%i", &n);
  int a[n]; 
  
  printf("How do enerate array: \n");
  printf("1 - generate random elements \n");
  printf("2 - worst case \n");
  printf("3 - best case \n");	
  
  //case	
  while(1)
  {
  	scanf("%i", &choice);
  	if (choice==1)
  	{
  			for (i = 0; i<n; i++)
  			{
      			a[i] = 0 + rand() %100;
 			}
  		break;
	}
	else if (choice==3)
	{
	    for (i = 0; i<n; i++)
  			{
      			a[i] = i;
 			}
			break;
		}
	else if (choice==2)
	{
	    for (i = 0; i<n; i++)
  			{
      			a[i] = n-i;
 			}
			break;
		}
  }
    
  printf("Choose the sort: \n");
  printf("1 - Insert sort \n");
  printf("2 - Quick sort \n");
  printf("3 - Radix sort \n");	
    
  
  //case	
  while(1)
  {
  	scanf("%i", &choice);
  	if (choice==1)
  	{
  		 insertionSort(a, n);
  		break;
	}
	else if (choice==2)
	{
	    quickSort(a, 0, n-1);
			break;
		}
	else if (choice==3)
	{
	    radixsort(a, n);
			break;
		}
  }
    
    
  printf("Number of changes = %d\n", chc);
  printf("Number of equals = %d", eqc);   
    
	return 0;
}
