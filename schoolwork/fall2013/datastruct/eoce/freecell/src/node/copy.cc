#include "node.h"

Node * Node :: copy()
{
	Node *copyNode = new Node(this->value, this->suit);

	return copyNode;
}
