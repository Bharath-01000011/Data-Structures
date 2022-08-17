

public class Main
{
    static int recursion(int num)
    {
        if(num < 0)
        {
            return -1;
        }
        if(num < 10)
        {
            return num;
        }
        else
        {
            
            return recursion(num/10) + recursion(num%10);
        }
    }
	public static void main(String[] args) {
	
	int num = 5555;
	System.out.println("Sum of digit : "+recursion(num));
		
	}
}
