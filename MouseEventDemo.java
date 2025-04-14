import java.awt.event.*;
import javax.swing.*;

public class MouseEventDemo extends JFrame implements MouseListener {
  JLabel label;

  MouseEventDemo() {
    label = new JLabel("No mouse event yet");
    label.setBounds(100, 100, 200, 30);

    add(label);
    addMouseListener(this);

    setSize(400, 300);
    setLayout(null);
    setVisible(true);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }

  public void mouseClicked(MouseEvent e) {
    label.setText("Mouse Clicked at " + e.getX() + "," + e.getY());
  }

  public static void main(String[] args) {
    new MouseEventDemo();
  }
}
