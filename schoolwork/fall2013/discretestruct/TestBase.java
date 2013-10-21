//Author: Alicia McNett
////Purpose to convert a number from decimal to a given base

import static java.lang.Math.*;

public class TestBase
{
	public static void main(String[] args)
	{
		System.out.println("Binary Base Expansion of Value 13: " +
				baseExpand(13, 2)); 
		System.out.println("Octal Base Expansion of Value 4745: " +
				baseExpand(4745, 8));
	}

	public static int baseExpand(int n, int b)
	{
		int k = 0, digit, expansion = 0;
		while (n != 0)
		{
			digit = n % b;
			n = n / b;
			expansion = expansion + digit * (int)pow(10,k);
			k++;
		}
		return expansion;
	}
}
