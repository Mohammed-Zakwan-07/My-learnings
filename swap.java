import java.util.Scanner;
class swap {
  public static void main(String[] args){
    Scanner input = new Scanner(System.in);

    System.out.println("Enter 2 numbers :");
    int A = input.nextInt();
    int B = input.nextInt();

    System.out.println("Before swaping : "+ A + " " + B);

    A = A + B;
    B = A - B;
    A = A - B;

    System.out.println("After swaping : "+ A + " " + B);
    input.close();
  }
  
}
