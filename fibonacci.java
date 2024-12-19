import java.util.Scanner;

public class fibonacci {
  public static void main (String [] args) {
    Scanner input = new Scanner(System.in);

    System.out.println("How many numbers?");
    int n = input.nextInt();

    int a = 0, b = 1;
    int next;

    System.out.print("0  1 ");
    for (int i = 3; i <= n; i++) {
      
      next = a + b;
      a = b;
      b = next;
      System.out.print(" " + next + 
      " ");
      

    }

    input.close();
  }
  
}
