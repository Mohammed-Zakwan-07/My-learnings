import java.awt.*;
import java.awt.event.*;

public class AWTDivisionExample {
  public static void main(String[] args) {

    Frame frame = new Frame("Division Calculator");
    frame.setSize(350, 200);
    frame.setLayout(new FlowLayout());

    TextField num1Field = new TextField(10);
    TextField num2Field = new TextField(10);
    Label resultLabel = new Label("Result will be displayed here");
    Button divideButton = new Button("Divide");

    divideButton.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        try {
          double num1 = Double.parseDouble(num1Field.getText());
          double num2 = Double.parseDouble(num2Field.getText());

          if (num2 == 0) {
            throw new ArithmeticException("Cannot divide by zero");
          }

          double result = num1 / num2;
          resultLabel.setText("Result: " + result);
        } catch (ArithmeticException ex) {
          resultLabel.setText("Error: " + ex.getMessage());
        } catch (NumberFormatException ex) {
          resultLabel.setText("Please enter valid numbers");
        }
      }
    });

    frame.add(new Label("Number 1: "));
    frame.add(num1Field);
    frame.add(new Label("Number 2: "));
    frame.add(num2Field);
    frame.add(divideButton);
    frame.add(resultLabel);

    frame.addWindowListener(new WindowAdapter() {
      public void windowClosing(WindowEvent e) {
        frame.dispose();
      }
    });

    frame.setVisible(true);
  }
}
