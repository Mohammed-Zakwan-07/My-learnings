import java.awt.event.*;
import javax.swing.*;

public class KeyEventDemo extends JFrame implements KeyListener {
  JTextField textField;
  JLabel label;

  KeyEventDemo() {
    textField = new JTextField();
    label = new JLabel("Type something");

    textField.setBounds(100, 100, 200, 30);
    label.setBounds(100, 150, 200, 30);

    add(textField);
    add(label);
    textField.addKeyListener(this);

    setSize(400, 300);
    setLayout(null);
    setVisible(true);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }

  public void keyTyped(KeyEvent e) {
    label.setText("You typed: " + e.getKeyChar());
  }

  public static void main(String[] args) {
    new KeyEventDemo();
  }
}
