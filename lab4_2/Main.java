import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Project Cleaning Car");
        frame.setDefaultLookAndFeelDecorated(true);
        frame.setContentPane(new PacientFrame().mainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocation(200, 200);
        frame.pack();
        frame.setSize(1000, 600);
        frame.setResizable(true);
        frame.setVisible(true);
    }
}