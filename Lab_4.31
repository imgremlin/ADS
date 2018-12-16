#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define N 70


typedef struct book_list{
  	char *title;
  	int *year;
  	struct book_list * next;
}book_list; 


void settings(void){
	printf ("\nList of available actions: \n1-adding an element to the tail of the list \
	\n2-removing an element from the head of the list \
	\n3-reverse \
	\n4-output the entire list in the format Title - year \
	\n5-delete the entire list \
	\n0-finish work\n");
}

book_list *init(char *title, int *year){ 
	book_list *temp = (book_list *) malloc(sizeof(book_list)); 
	temp->title = title; 
	temp->year = year; 
	temp->next = NULL; 
	return temp; 
}

char* input_string (char *message){ 
	char *buff = (char*)malloc(N*sizeof(char)); 
	printf("Input %s:\t", message); 
	scanf("%s", buff); 
	char *result = (char*)malloc((strlen(buff)+1)*sizeof(char)); 
	strcpy(result, buff); 
	free (buff); 
	return result; 
}


void add_book (book_list *head, char *title, int *year){ 
 	book_list *temp = (book_list*)malloc(sizeof(book_list));
	while(head->next) head=head->next;
	head->next=temp; 
	temp->title=title; 
	temp->year=year; 
	temp->next = NULL; 
}



void print_list (book_list *head){ 
 	
 	 
	 if (head==NULL) {
		printf ("--The list is empty--\n");
		return;
	}
	 else
	 {
	 book_list *temp=head;
	 	do
		{
  			printf ("%s - %d\n", temp->title ,*(temp->year));  
  			if (temp->next == NULL) break;
  			temp = temp->next;
 		} while (temp);
 		return;
 	}
 	
}

void delete_head (book_list **head){
 	if (head==NULL) printf("--Nothing to delete--\n");
 	else
	{ 
  		book_list *ptr = *head;
  		*head=(*head)->next;
  		free(ptr->title);
  		free(ptr->year);
  		free(ptr);
 	}
}

void clear_list(book_list **head){
	book_list *temp, *t=(*head)->next;
	if (*head != NULL)
		while (*head != NULL)
		{
			temp=(*head)->next;
			free((*head)->title);
			free((*head)->year);
			free(*head);
			*head=temp;
		}		
	else printf ("--List deleted--\n");
	*head=NULL;
	return;
}


book_list* reverse_list(book_list *first){
  book_list * reverse_done = NULL;
  book_list * node;
  book_list * nnode;
  
  for (node = first; node != NULL; node = nnode){
    nnode = node -> next;
    node -> next = reverse_done;
    reverse_done = node;
}
  return reverse_done;
}

int main() { 

  	char in, n, i;
  	char *title;
  	printf("\nPlease input started number of books: "); 
	scanf("%d", &n);
	int *year = (int*)malloc(sizeof(int)); 
	title = input_string("title"); 
	printf("Input year:\t");
	scanf("%d", year);
	book_list *head = init(title, year);
	for (i=1; i<n; i++)
	{
		title = input_string("title");
		printf("Input year:\t"); 
		year = (int*)malloc(sizeof(int)); 
		scanf("%d", year); 
		add_book(head, title, year); 
	}
	
	settings();
  	printf ("\nSelect an command from the list: ");
  	scanf ("%d",&in);
  	
  	while (in >= 0){
		switch (in)
		{	
   		case 1: 
		   		title = input_string("title"); 
		   		printf("Input Year:\t"); 
				year = (int*)malloc(sizeof(int));
				scanf("%d", year); 
				add_book(head, title, year);
	   			printf ("--OPERATION COMPLETED--\n");
  		break;
   
   		case 2: delete_head (&head);
    			printf ("--OPERATION COMPLETED--\n");
    	break;
    
   		case 3: head=reverse_list(head);
   				printf ("--OPERATION COMPLETED--\n");
   		break;
   
   		case 4: print_list (head);
   				printf ("--OPERATION COMPLETED--\n");
  		break;
   
   		case 5: clear_list (&head);
    			printf ("--OPERATION COMPLETED--\n");
    	break;
    
   		case 0: exit (0);
   				printf ("--OPERATION COMPLETED--\n");
   		break;
   
   		default:
				printf ("\nSelect an existing command from the list: ");
				settings();
		break;
  		}
  	printf ("\nSelect an command from the list: ");
	scanf ("%d", &in);
 	}
return 0;
}
