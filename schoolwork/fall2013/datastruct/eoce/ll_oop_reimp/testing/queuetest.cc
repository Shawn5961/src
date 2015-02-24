#include <stdio.h>
#include "queue.h"

int main()
{
	Node *tmp = new Node;
	Queue *myQueue = new Queue();
	Queue *tempQueue = new Queue();

	int option, input, i = 0;
	bool queueExists = false;
	
	do
	{
		printf("Please choose an option\n");
		printf("1: Build queue\n");
		printf("2: Display queue\n");
		printf("3: Enqueue\n");
		printf("4: Dequeue\n");
		printf("5: Get buffer size\n");
		printf("6: Set buffer size\n");
		printf("9: Destroy queue\n");
		printf("0: Exit\n");
		scanf("%d", &option);

		switch( option )
		{
			case 1:
				if( queueExists == false)
				{
					printf("Enter queue size\n");
					scanf("%d", &input);
					myQueue->setBufferSize(input);
					tempQueue->setBufferSize(input);
					do
					{
						printf("Enter a value (-1 to quit)\n");
						scanf("%d", &input);
						tmp = new Node(input);
						myQueue->enqueue(tmp);
						i++;
					} while( input != -1 && i < myQueue->getBufferSize());
					i = 0;
					queueExists = true;
				}
				else
					printf("Queue already exists. Please destroy before rebuilding\n");
				break;

			case 2:
				printf("Displaying queue: ");
				tmp = myQueue->dequeue();
				while( tmp != NULL )
				{
					printf("%d ", tmp->getValue());
					tempQueue->enqueue(tmp);
					tmp = myQueue->dequeue();
				}
				printf("\n");

				tmp = tempQueue->dequeue();
				while( tmp != NULL )
				{
					myQueue->enqueue(tmp);
					tmp = tempQueue->dequeue();
				}
				break;

			case 3:
				printf("Enter a value to enqueue.\n");
				scanf("%d", &input);
				tmp->setValue(input);
				myQueue->enqueue(tmp);
				break;

			case 4:
				printf("Dequeueing\n");
				tmp = myQueue->dequeue();
				printf("Dequeued node value: %d\n", tmp->getValue());
				break;

			case 5:
				printf("Buffer size: %d\n", myQueue->getBufferSize());
				break;

			case 6:
				printf("Enter a value to set buffer size\n");
				scanf("%d", &input);
				myQueue->setBufferSize(input);
				break;

			case 9:
				printf("Destroying queue\n");
				myQueue->~Queue();
				queueExists = false;
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
