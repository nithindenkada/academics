import java.util.Random;
import java.util.Scanner;

public class Random {
    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter how many numbers you want: ");
        int set = sc.nextInt();
        System.out.println("Enter starting number: ");
        int start = sc.nextInt();
        System.out.println("Enter ending number");
        int end = sc.nextInt();

        Random random = new Random();
        System.out.println("random number : ");
        for(int i = 1; i <= set; i++){
        System.out.println(+(int) (Math.random() * (end - start + 1) + start));
    }}
}