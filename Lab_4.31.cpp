#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define N 50


typedef struct pass_list{
  	char *series;
  	int *number;
  	struct pass_list * next;
}book_list; 


void settings(void){
	printf("What can you do: \n");
	printf("1.Add to the list \n");
	printf("2.Remove item from the list \n");
	printf("3.Reverse the list \n");
	printf("4.Print the list \n");
	printf("5.Delete the list \n");
	printf("0.Exit \n");
}

pass_list *init(char *series, int *number){ 
	book_list *temp = (book_list *) malloc(sizeof(book_list)); 
	temp->series = series; 
	temp->number = number; 
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


void add_pass (pass_list *head, char *series, int *number){ 
 	pass_list *temp = (pass_list*)malloc(sizeof(pass_list));
	while(head->next) head=head->next;
	head->next=temp; 
	temp->series=series; 
	temp->number=number; 
	temp->next = NULL; 
}



void print_list (pass_list *head){ 
 	
 	 
	 if (head==NULL) {
		printf ("list is empty\n");
		return;
	}
	 else
	 {
	 pass_list *temp=head;
	 	do
		{
  			printf ("%s - %d\n", temp->series ,*(temp->number));  
  			if (temp->next == NULL) break;
  			temp = temp->next;
 		} while (temp);
 		return;
 	}
 	
}

void delete_head (pass_list **head){
 	if (head==NULL) printf("dont know what to delete\n");
 	else
	{ 
  		pass_list *ptr = *head;
  		*head=(*head)->next;
  		free(ptr->series);
  		free(ptr->number);
  		free(ptr);
 	}
}

void clear_list(pass_list **head){
	pass_list *temp, *t=(*head)->next;
	if (*head != NULL)
		while (*head != NULL)
		{
			temp=(*head)->next;
			free((*head)->series);
			free((*head)->number);
			free(*head);
			*head=temp;
		}		
	else printf ("list deleted\n");
	*head=NULL;
	return;
}


  pass_list* reverse_list(pass_list *first){
  pass_list * reverse_done = NULL;
  pass_list * node;
  pass_list * nnode;
  
  for (node = first; node != NULL; node = nnode){
    nnode = node -> next;
    node -> next = reverse_done;
    reverse_done = node;
}
  return reverse_done;
}

int main() { 

  	char in, n, i;
  	char *series;
  	printf("Insert amount of passports: \n"); 
	scanf("%d", &n);
	int *number = (int*)malloc(sizeof(int)); 
	series = input_string("series"); 
	printf("Insert number:\t");
	scanf("%d", number);
	pass_list *head = init(series, number);
	for (i=1; i<n; i++)
	{
		series = input_string("series");
		printf("Insert number:\t"); 
		number = (int*)malloc(sizeof(int)); 
		scanf("%d", number); 
		add_pass(head, series, number); 
	}
	
	settings();
  	printf ("Choose what to do: \n");
  	scanf ("%d",&in);
  	
  	while (in >= 0){
		switch (in)
		{	
   		case 1: 
		   		series = input_string("series"); 
		   		printf("Insert number:\t"); 
				number = (int*)malloc(sizeof(int));
				scanf("%d", number); 
				add_pass(head, series, number);
	   			printf ("well done\n");
  		break;
   
   		case 2: delete_head (&head);
    			printf ("well done\n");
    	break;
    
   		case 3: head=reverse_list(head);
   				printf ("well done\n");
   		break;
   
   		case 4: print_list (head);
   				printf ("well done\n");
  		break;
   
   		case 5: clear_list (&head);
    			printf ("well done\n");
    	break;
    
   		case 0: exit (0);
   				printf ("well done\n");
   		break;
   
   		default:
				printf ("Choose what to do: \n");
				settings();
		break;
  		}
  	printf ("Choose what to do: \n");
	scanf ("%d", &in);
 	}
return 0;
}
