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
       while (j >= 0 && a[j] > key) 
       { 
           a[j+1] = a[j]; 
           j = j-1; 
           chc++;
       } 
       a[j+1] = key;
	   chc++; 
   } 
}

int partition (int a[], int low, int high) 
{ 
    int pivot = a[high]; 
    int i = (low - 1);  
  	int j;
    for (j = low; j <= high- 1; j++) 
    { 
		eqc++;
        if (a[j] <= pivot) 
        { 
            i++;   
            swap(&a[i], &a[j]); 
            chc+=3;
        } 
      
    } 
    swap(&a[i + 1], &a[high]); 
    chc++;
    return (i + 1); 
} 

void quickSort(int a[], int low, int high) 
{ 
    if (low < high) 
    { 
        
        int pi = partition(a, low, high); 
  
        
        quickSort(a, low, pi - 1); 
        quickSort(a, pi + 1, high); 
    } 
} 

void countSort(int a[], int n, int exp)
{
	int output[n], i, count[10] = {0};
	
	for (i = 0; i < n; i++)
	{
		count[(a[i] / exp) % 10]++;
		chc++;
	}
		
		
	for (i = 1; i < 10; i++)
	{
		chc++;
		count[i] += count[i-1];
	}
		
		
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		chc++;
		count[(a[i] / exp) % 10]--;
	}
	
	for (i = 0; i < n; i++)
	{
		a[i] = output[i];
		chc++;
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
      			a[i] = rand() %100000;
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
