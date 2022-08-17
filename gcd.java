public class gcd {
    static int recursion(int num1, int num2)
    {
        if(num2 != 0)
        {
            return recursion(num2, num1 % num2);
        }
        else
        {
            return num1;
        }
    }
    public static void main(String[] args) {
        int num1 = 66;
        int num2 = 20;
        System.out.print("GCD of "+num1+" and "+num2+" is : "+recursion(num1, num2));
    }
    
}
