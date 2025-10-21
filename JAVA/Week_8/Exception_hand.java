import java.util.Scanner;

public class Exception_hand {

    static public boolean isAlNum(String str) {
        for(int i = 0; i < str.length(); i++) {
            if(!(Character.isDigit(str.charAt(i))))
                return false;
        }
        return true;
    }

    static void checkException(String num1, String num2) {

        if(!(isAlNum(num1) && isAlNum(num2))){
            throw new NumberFormatException("Number cannot be string!");
        }
        int n1 = Integer.parseInt(num1);
        int n2 = Integer.parseInt(num2);
        if(n2 == 0) {
            throw new ArithmeticException("The number cannot devide by 0!");
        }
        System.out.println("Both are integers and its sum: " + (n1 + n2));
        System.out.println("Divides through :" + (n1 / n2));
    }


    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter first number: ");
        String num1 = sc.nextLine();
        System.out.println("Enter second number: ");
        String num2 = sc.nextLine();        

        checkException(num1, num2);
    }
}