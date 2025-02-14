import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Employee {
    String name;
    String dateOfAppointment;

    Employee(String name, String dateOfAppointment) {
        this.name = name;
        this.dateOfAppointment = dateOfAppointment;
    }

    String getDateOfAppointment() {
        return dateOfAppointment;
    }

    public String toString() {
        return name + " - " + dateOfAppointment;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of employees: ");
        int n = scanner.nextInt();

        Employee[] employees = new Employee[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for Employee " + (i + 1) + ":");
            System.out.print("Name: ");
            String name = scanner.nextLine();
            System.out.print("Date of Appointment (DD-MM-YYYY): ");
            String date = scanner.nextLine();
            employees[i] = new Employee(name, date);
        }

        Arrays.sort(employees, Comparator.comparing(Employee::getDateOfAppointment));

        System.out.println("\nEmployees sorted by date of appointment:");
        for (Employee emp : employees) {
            System.out.println(emp);
        }

        scanner.close();
    }
}
