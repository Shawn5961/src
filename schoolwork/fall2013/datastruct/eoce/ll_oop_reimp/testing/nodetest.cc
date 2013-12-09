#include <stdio.h>
#include "node.h"

int main()
{
	int input;

	printf("Creating a node with the default constructor\n");
	Node *defaultNode = new Node;

	printf("Creating a node with the regular constructor\n");
	printf("\nEnter a value for the new node\n");
	scanf("%d", &input);
	Node *regularNode = new Node(input);

	printf("Copying regularNode to copiedNode\n");
	Node *copiedNode = regularNode->copy();

	printf("\nValue of defaultNode: %d\n", defaultNode->getValue());
	printf("Value of regularNode: %d\n", regularNode->getValue());
	printf("Value of copiedNode: %d\n", copiedNode->getValue());

	printf("\nChanging the value of copiedNode\n");
	printf("Enter a new value for copiedNode\n");
	scanf("%d", &input);
	copiedNode->setValue(input);


	printf("\nValue of defaultNode: %d\n", defaultNode->getValue());
	printf("Value of regularNode: %d\n", regularNode->getValue());
	printf("Value of copiedNode: %d\n", copiedNode->getValue());
	
	printf("\nSetting defaultNode->next to regularNode\n");
	defaultNode->setNext(regularNode);
	printf("Setting regularNode->prev to defaultNode\n");
	regularNode->setPrev(defaultNode);
	printf("Setting regularNode->next to copiedNode\n");
	regularNode->setNext(copiedNode);
	printf("Setting copiedNode->prev to regularNode\n");
	copiedNode->setPrev(regularNode);

	printf("\nValue of regularNode->prev: %d\n", regularNode->getPrev()->getValue());
	printf("Value of regularNode: %d\n", regularNode->getValue());
	printf("Value of regularNode->next: %d\n", regularNode->getNext()->getValue());

	return 0;
}
