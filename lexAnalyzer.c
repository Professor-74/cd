#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

const char*keywords[]={
	"int", "float", "char", "double", "if", "else", "while", "for", "return", "void"
};

int isKeyword(const char*word)
{
	int n = sizeof(keywords) / sizeof(keywords[0]);
	
	for (int i=0; i<n; i++)
	{
		if (strcmp, keywords[i]==0)
		{
			return 1;
		}
		
		return 0;
	}
}

int main()
{
	char input[1000];
	int i=0;
	
	printf("Enter the source code:\n");
	fgets(input, sizeof(input), stdin);
	
	printf("--Tokens--\n");
	
	while (input[i]!='\0')
	{
		if (
			input[i]==' '||
			input[i]=='\t'||
			input [i]== '\n'||
			input[i]=='\r'
		   )
		   
		   {
		   	i++;
		   	continue;
		   }
		   
		   
		if (isalpha(input[i])|| input[i]=='_')
		{
			char word[MAX];
			int j=0;
			while (isalnum(input[i])|| input[i]=='_')
			{
				word[j++]= input[i++];
			}
			
			word[j] = '\0';
			
			if (isKeyword(word))
			{
				printf("%s -> KEYWORD\n", word);
			}
			else
			{
				printf("%s -> IDENTIFIER\n", word);
			}
			
				
		}
		
		else if (isdigit(input[i]))
		{
			char number[MAX];
			int j=0;
			while (isdigit(input[i]) || input[i]=='.')
			{
				number[j++]= input[i++];
			}
			
			number[j]= '\0';
			printf("%s -> NUMBER\n",number);
		}
		
		else if (
				input[i]== '+' ||
				input[i]=='-' ||
				input[i]=='*' ||
				input[i]=='/'||
				input[i]=='%' 
			
		        )
		        
			{
				printf("%c -> Arithmetic Operator\n", input[i]);
				i++;
			}
			
		else if (
		        	input[i]== '=' ||
		        	input[i]=='<' ||
		        	input[i]== '>' ||
		        	input[i]=='!'
		        )
		        
		        {
		        	char op[3];
		        	op[0] = input[i];
		        	op[1] = '\0';
		        	
		        	if (
		        		input[i]== '=' && input[i+1]== '=' ||
		        		input[i]== '<' && input[i+1]== '=' ||
		        		input[i]== '>' && input[i+1]== '=' ||
		        		input[i]== '!' && input[i+1]== '='
		        	   )
		        	   {
		        	   	op[1] = input[i+1];
		        	   	op[2] = '\0';
		        	   	i+=2;
		        	   }
		        	   
		        	else{
		 
		 			i++;
		 		    }
		 		    
		 		printf("%s -> Relational / Assignment Operator\n", op);
		        		
		        }
		  
		  else if (
		  
		  		input[i]==';' ||
		  		input[i]== ','||
		  		input[i]== '(' ||
		  		input[i]==')' ||
		  		input[i]=='{' ||
		  		input[i] == '}' ||
		  		input[i]== '[' ||
		  		input[i]== ']'		  
		  )
		  {
		  printf("%c-> SPECIAL SYMBOL\n", input[i]);
		  i++;
		  }
		  
		  else {
		  	printf("%c -> UNKNOWN\n", input[i]);
		  	i++;
		  }
		  
		  
		        
		 
	}
	
	return 0;
	
}
