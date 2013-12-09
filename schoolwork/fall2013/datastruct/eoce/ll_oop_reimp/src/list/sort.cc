#include "list.h"

//Needs finished
void List :: sort()
{
	Node *tmp, *tmp2, *tmp3, *tmp4;
	
	int i, count = this->qty;
	
	tmp = this->start;
	
	do
	{
		for( i = 0; i < (count - 1); i++ )
		{
			if( tmp->getValue() > tmp->getNext()->getValue() )
			{
				tmp2 = tmp->getNext();
				tmp3 = getNode(tmp);
				append(tmp2, tmp3);
			}
		}
		
		tmp = this->start;
		
		count--;
	} while( count > 1 );
}
