import java.util.Scanner;

class Person {
    String Name;
    String Address;
    String PhoneNo;
    String Email;

    Person(String Name, String Address, String PhoneNo, String Email) {
        this.Name = Name;
        this.Address = Address;
        this.PhoneNo = PhoneNo;
        this.Email = Email;
    }

    void Input() {
        @SuppressWarnings("resource")
        Scanner input = new Scanner(System.in);
        System.out.print("Enter name: ");
        this.Name = input.nextLine();
        System.out.print("Enter address: ");
        this.Address = input.nextLine();
        System.out.print("Enter phone number: ");
        this.PhoneNo = input.nextLine();
        System.out.print("Enter email: ");
        this.Email = input.nextLine();
    }

    void Display() {
        System.out.println("Name: " + Name);
        System.out.println("Address: " + Address);
        System.out.println("Phone-No: " + PhoneNo);
        System.out.println("Email: " + Email);
    }

    public static void main(String[] args) {

        Person person = new Person("", "", "", "");

        person.Input();
        System.out.println("\n--- Person Details ---");
        person.Display();
    }
}
