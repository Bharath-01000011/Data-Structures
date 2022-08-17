public class Main
{
    static int recursion(int num,int power)
    {
        if(power < 0)
        {
            return -1;
        }
        if(num < 0)
        {
            return 0;
        }
        
        if(power == 1)
        {
            return num;
        }
        
        else
        {
            
            return num * recursion(num,power-1);
        }
    }
	public static void main(String[] args) {
	
	int num = 2;
	int power = 5;
	System.out.println("Sum of digit : "+recursion(num,power));
		
	}
}
