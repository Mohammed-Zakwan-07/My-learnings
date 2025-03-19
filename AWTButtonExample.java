import java.awt.*;
import java.awt.event.*;

public class AWTButtonExample {
  public static void main(String[] args) {
    Frame frame = new Frame("AWT Example");

    frame.setSize(300, 300);
    frame.setLayout(new FlowLayout());

    Label label = new Label("Click the button!");

    Button button = new Button("Click Me");

    button.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        label.setText("Button Clicked!");
      }
    });

    frame.add(label);
    frame.add(button);

    frame.addWindowListener(new WindowAdapter() {
      public void windowClosing(WindowEvent e) {
        frame.dispose();
      }
    });

    frame.setVisible(true);
  }
}
