public class Change
{
	public static void main(String[] args)
	{
		final int QUARTERS = 25;
		final int DIMES = 10;
		final int NICKELS = 5;
		final int PENNIES = 1;

		int change = 164;

		int quarters = change/QUARTERS;
		change = change % QUARTERS;

		int dimes = change/DIMES;
		change = change % DIMES;

		int nickels = change/NICKELS;
		change = change % NICKELS;

		int pennies = change;

		System.out.println("Quarters: " + quarters);
		System.out.println("Dimes: " + dimes);
		System.out.println("Nickels: " + nickels);
		System.out.println("Pennies: " + pennies);

	}
}
