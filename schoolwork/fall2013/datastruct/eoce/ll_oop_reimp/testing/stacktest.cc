#include <stdio.h>
#include "stack.h"

int main()
{
	Node *tmp = new Node;
	Stack *myStack = new Stack();
	Stack *tempStack = new Stack();

	int option, input, i = 0;
	bool stackExists = false;
	
	do
	{
		printf("Please choose an option\n");
		printf("1: Build stack\n");
		printf("2: Display stack\n");
		printf("3: Push to stack\n");
		printf("4: Pop from stack\n");
		printf("5: Peek\n");
		printf("6: Get stack size\n");
		printf("7: Get list size\n");
		printf("8: Change stack size\n");
		printf("9: Destroy stack\n");
		printf("0: Exit\n");
		scanf("%d", &option);

		switch( option )
		{
			case 1:
				if( stackExists == false)
				{
					printf("Enter stack size\n");
					scanf("%d", &input);
					myStack->setSize(input);
					tempStack->setSize(input);
					do
					{
						printf("Enter a value (-1 to quit)\n");
						scanf("%d", &input);
						tmp = new Node(input);
						myStack->push(tmp);
						i++;
					} while( input != -1 && i < myStack->getSize());
					i = 0;
					stackExists = true;
				}
				else
					printf("Stack already exists. Please destroy before rebuilding\n");
				break;

			case 2:
				printf("Displaying stack: ");
				tmp = myStack->pop();
				while( tmp != NULL )
				{
					printf("%d ", tmp->getValue());
					tempStack->push(tmp);
					tmp = myStack->pop();
				}
				printf("\n");

				tmp = tempStack->pop();
				while( tmp != NULL )
				{
					myStack->push(tmp);
					tmp = tempStack->pop();
				}
				break;

			case 3:
				if( myStack->getListSize() == myStack->getSize() )
					printf("Stack is full. Please resize or pop from stack\n");
				else
				{
					printf("Enter a value to push.\n");
					scanf("%d", &input);
					tmp->setValue(input);
					myStack->push(tmp);
				}
				break;

			case 4:
				printf("Popping from stack.\n");
				tmp = myStack->pop();
				printf("Popped node value: %d\n", tmp->getValue());
				break;

			case 5:
				printf("Peeking stack\n");
				tmp = myStack->peek();
				printf("Peeked node value: %d\n", tmp->getValue());
				break;

			case 6:
				printf("Stack size: %d\n", myStack->getSize());
				break;

			case 7:
				printf("List size: %d\n", myStack->getListSize());
				break;

			case 8:
				printf("Enter a value to set stack size\n");
				scanf("%d", &input);
				myStack->setSize(input);
				break;

			case 9:
				printf("Destroying stack\n");
				myStack->~Stack();
				stackExists = false;
				break;

			case 0:
				break;

			default:
				printf("Invalid option.\n");
				break;


		}

	} while( option != 0 );


	return(0);
}
