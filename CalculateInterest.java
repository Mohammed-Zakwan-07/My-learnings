import java.util.Scanner;

interface Interest {
  final float Rate = 3;

  void SimpleInterest(float Amt);

  void CompoundInterest(float Amt);
}

public class CalculateInterest implements Interest {
  @Override
  public void SimpleInterest(float Amt) {
    float SI = (Amt * Rate) / 100;
    System.out.println("Simple Interest is: " + SI);
  }

  @Override
  public void CompoundInterest(float Amt) {
    float CI = (Amt * Rate * (1 + Rate / 100)) / 100;
    System.out.println("Compound Interest is: " + CI);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the amount: ");
    float Amt = sc.nextFloat();
    CalculateInterest ci = new CalculateInterest();
    ci.SimpleInterest(Amt);
    ci.CompoundInterest(Amt);
  }
}
