import school.students.Student;
import school.teachers.Teacher;

public class SchoolMain {
  public static void main(String[] args) {
    Student student = new Student();
    student.display();

    Teacher teacher = new Teacher();
    teacher.display();
  }
}
