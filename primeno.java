import java.util.Scanner;

class primeno {

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    System.out.println("enter a number :");
    int num = input.nextInt();

    int found = 1;

    if (num <= 1) {
      found =-1;
    }

    for (int i = 2; i <= Math.sqrt(num); i++) {
      if (num % i == 0 ) {
        found = -1 ;
      }
    }
    
    if ( found == -1 ) {
      System.out.println(num + " is not a prime number");
    }else{
      System.out.println(num + " is a prime number");
    }

    input.close();
  }
}
