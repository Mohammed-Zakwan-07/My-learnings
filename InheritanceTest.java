class Person {
    String Name, Address, PhoneNo, Email;
    
    Person(String Name, String Address, String PhoneNo, String Email) {
        this.Name = Name;
        this.Address = Address;
        this.PhoneNo = PhoneNo;
        this.Email = Email;        
    }

    void ToStrings() {
        System.out.println("Class: Person , Name: " + Name);
    }
}

class Student extends Person {
    String Status;
    
    Student(String Name, String Address, String PhoneNo, String Email, String Status) {
        super(Name, Address, PhoneNo, Email);
        this.Status = Status;
    }

    @Override
    void ToStrings() {
        System.out.println("Class: Student , Name: " + Name + ", Status: " + Status);
    }
}

class Employee extends Person {
    String Office;
    String Salary;
    String DateHired;
    
    Employee(String Name, String Address, String PhoneNo, String Email, String Office, String Salary, String DateHired) {
        super(Name, Address, PhoneNo, Email);
        this.Office = Office;
        this.Salary = Salary;
        this.DateHired = DateHired;
    }

    @Override
    void ToStrings() {
        System.out.println("Class: Employee , Name: " + Name + ", Office: " + Office + ", Salary: " + Salary + ", Date Hired: " + DateHired);
    }
}

class Faculty extends Employee {
    String OfficeHours;
    String Rank;

    Faculty(String Name, String Address, String PhoneNo, String Email, String Office, String Salary, String DateHired, String OfficeHours, String Rank) {
        super(Name, Address, PhoneNo, Email, Office, Salary, DateHired);
        this.OfficeHours = OfficeHours;
        this.Rank = Rank;
    }

    @Override
    void ToStrings() {
        System.out.println("Class: Faculty , Name: " + Name + ", Rank: " + Rank + ", Office Hours: " + OfficeHours);
    }
}

class Staff extends Employee {
    String Title;

    Staff(String Name, String Address, String PhoneNo, String Email, String Office, String Salary, String DateHired, String Title) {
        super(Name, Address, PhoneNo, Email, Office, Salary, DateHired);
        this.Title = Title;
    }

    @Override
    void ToStrings() {
        System.out.println("Class: Staff , Name: " + Name + ", Title: " + Title);
    }
}

public class InheritanceTest {
    public static void main(String[] args) {
        Person p = new Person("Alice", "123 Street", "12367890", "alice@email.com");
        Student s = new Student("Bob", "456 Avenue", "98743210", "bob@email.com", "Senior");
        Employee e = new Employee("Charlie", "789 Road", "55667777", "charlie@email.com", "Room 101", "50000", "01-01-2020");
        Faculty f = new Faculty("David", "101 Highway", "44432222", "david@email.com", "Room 202", "60000", "01-01-2019", "9 AM - 5 PM", "Professor");
        Staff st = new Staff("Eve", "202 Boulevard", "11122233", "eve@email.com", "Room 303", "45000", "01-01-2021", "Administrator");

        // Calling ToStrings() to display details
        p.ToStrings();
        s.ToStrings();
        e.ToStrings();
        f.ToStrings();
        st.ToStrings();
    }
}
