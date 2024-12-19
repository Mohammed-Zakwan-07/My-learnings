import java.util.Scanner;

public class palindrome {
  public static void main (String[] args) {
    Scanner input = new Scanner(System.in);

    System.out.println("enter a number");
    int num = input.nextInt();

    int ognum = num;
    int reversed_no = 0;

    while (ognum > 0) {
      int digit = ognum % 10 ;
      reversed_no = reversed_no * 10 + digit ;
      ognum /= 10;
    }
    if (num == reversed_no) {
      System.out.println(num + " is palindorme");
    }else{
      System.out.println(num + " is not palindorme");
    }

    input.close();
  } 
}
