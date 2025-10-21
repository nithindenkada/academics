import java.lang.Exception;
import java.util.Scanner;

class VoteException extends Exception {
    public VoteException(String mes) {
        super(mes);
    }
}

public class userDefinedException {

    public static void checkEligibility(int age) throws VoteException {
        if(age < 18)
            throw new VoteException("You are minor! ");
        System.out.println("Congrats..! You are Major!");
    }


    public static void main (String args[]) throws  VoteException {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your to check eligibility to vote : ");
        int age = sc.nextInt();

        checkEligibility(age);
    }
}