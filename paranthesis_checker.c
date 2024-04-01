#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 100
char stack[max];
int top = -1;
void push(char stack[], char);
char pop(char stack[]);
void infixtopostfix(char source[], char target[]); // source is given expression and target is the postfix
int getpriority(char);                             // to check the presedence of operators
int main()
{
    char infix[100], postfix[100];
    printf("Enter the infix expression\n");
    scanf("%s", &infix);
    strcpy(postfix, "");            // to make postfix string empty all 100 positions
    infixtopostfix(infix, postfix); // calling the function
    printf("\nthe postfix expression is\n");
    printf("%s", postfix);
}
void infixtopostfix(char source[], char target[])
{
    int i = 0, j = 0; // i to iterate through each character of given string or source and j is to iterate through every character of target string
    char temp;
    strcpy(target, "");       // to make target string empty
    while (source[i] != '\0') // runs till the iteration found the empty index position
    {
        if (source[i] == '(')
        {
            push(stack, source[i]); // acccording to algorithm when we find open brace push it into stack
            i++;
        }

        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i]; // according to algorithm if we fing digit or alpha add it to the postfix target is the postfix here
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%') // to check the operators
        {
            while ((top != -1) && (stack[top] != '(') && (getpriority(stack[top]) > getpriority(source[i]))) // to check the presedence of operators
            {         //if any of the condition is false it push that character to stack else it will pop                                                                                       // if stack operator has greater presednec than reading pop it from stack and add to the postfix expression
                target[j] = pop(stack);
                j++;
            }
            push(stack, source[i]);//to push the operators 
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (stack[top] == '(')) // runs until top become -1 or until it get the open brace as per the algorithm
            {
                target[j] = pop(stack); // the element which delete stores in target string
                j++;
            }
            if (top == -1)
            {
                printf("Invalid expression\n"); // if the entered string is empty
               
            }
            temp = pop(stack); // to remove the open brace like if expression is -(a+b)
            i++;
        }
         else
        {
            printf("\nInvalid expression");
            
        }
       
        while ((top != -1) && (stack[top] != '('))//if their are any other elements inn stack not followed by the uper conditions then it follows that
        {
            target[j] =pop(stack);
            j++;
        }
        target[j] = '\0';
    }
}
int getpriority(char o)//to check the presedence of operators
{
    if ((o=='/')||(o=='*')||(o=='%'))
    {
        return 1;
    }
    else if((o=='+')||(o=='-'))
    {
        return 0;
    }
}
void push(char stack[],char val)//to push the elements
{
    if(top==max-1)
    {
        printf("It is overflow");
    }
    else{
        top++;
        stack[top]=val;
    }
}
char pop(char stack[])//to delete the elemets
{
    char val=' ';//assigning character value as empty so it can hold stack characters
    if(top==-1)
    {
        printf("UNder flow");
    }
    else{
        val=stack[top];
        top--;
    }
}