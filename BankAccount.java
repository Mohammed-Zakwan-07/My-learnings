import java.util.Scanner;

public class BankAccount {
  private String acNo;
  private String acName;
  private int acBal;

  public BankAccount(String acNo) {
    this.acNo = acNo;
  }

  public BankAccount(String acNo, String acName) {
    this.acNo = acNo;
    this.acName = acName;
  }

  public BankAccount(String acNo, String acName, int acBal) {
    this.acNo = acNo;
    this.acName = acName;
    this.acBal = acBal;
  }

  public void deposit(int amount) {
    if (amount > 0) {
      acBal += amount;
      System.out.println(amount + " deposited successfully.");
    } else {
      System.out.println("Invalid deposit amount.");
    }
  }

  public void withdraw(int amount) {
    if (amount > 0 && amount <= acBal) {
      acBal -= amount;
      System.out.println(amount + " withdrawn successfully.");
    } else {
      System.out.println("Insufficient balance or invalid amount.");
    }
  }

  public void display() {
    System.out.println("-------------------------");
    System.out.println("Account No: " + acNo);
    System.out.println("Account Name: " + acName);
    System.out.println("Account Balance: $" + acBal);
    System.out.println("-------------------------");
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println("Enter the account number ");
    String acno = scanner.nextLine();

    System.out.println("Enter the account name ");
    String acname = scanner.nextLine();

    System.out.println("Enter the account balance  ");
    int acbal = scanner.nextInt();

    BankAccount obj1 = new BankAccount(acno);
    BankAccount obj2 = new BankAccount(acno, acname);
    BankAccount obj3 = new BankAccount(acno, acname, acbal);

    obj3.display();

    System.out.println("Enter the amount to deposit ");
    int Deposit = scanner.nextInt();
    System.out.println("Enter the amount to withdraw ");
    int with = scanner.nextInt();

    obj3.deposit(Deposit);
    obj3.withdraw(with);
    obj3.display();
  }
}
