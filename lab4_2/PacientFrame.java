import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

public class PacientFrame extends JFrame {
    public JPanel mainPanel;
    private JList<Object> list;
    private DefaultListModel<Object> defaultListModel;
    private laba42 listP;
    public PacientFrame() {
        listP = new laba42();
        addFrameElements();
    }
    private void addFrameElements() {
        mainPanel           = new JPanel();
        JPanel leftBlock    = new JPanel();
        JPanel rightBlock   = new JPanel();

        JTextField nameField        = new JTextField();
        JTextField surnameField     = new JTextField();
        JTextField yearOfBirthField = new JTextField();

        JButton buttonAdd = new JButton("Добавить");
        JButton buttonDel = new JButton("Удалить");
        JButton buttonRemake = new JButton("Изменить");

        GridLayout iMoreLikeFlexbox = new GridLayout(0, 1);

        leftBlock.setLayout(iMoreLikeFlexbox);
        rightBlock.setLayout(iMoreLikeFlexbox);
        mainPanel.setLayout(new GridLayout(1, 2));

        JLabel name     = new JLabel("Имя:", SwingConstants.CENTER);
        JLabel surname  = new JLabel("Фамилия:", SwingConstants.CENTER);
        JLabel yearOfB  = new JLabel("Год рождения:", SwingConstants.CENTER);
        mainPanel.add(leftBlock);
        mainPanel.add(rightBlock);
        leftBlock.add(name);
        leftBlock.add(nameField);
        leftBlock.add(surname);
        leftBlock.add(surnameField);
        leftBlock.add(yearOfB);
        leftBlock.add(yearOfBirthField);
        leftBlock.add(buttonAdd);
        leftBlock.add(buttonDel);
        leftBlock.add(buttonRemake);

        defaultListModel = new DefaultListModel<>();
        list = new JList<>(defaultListModel);
        JScrollPane pane = new JScrollPane();
        pane.setViewportView(list);
        rightBlock.add(pane);

        JButton buttonFilter        = new JButton("Фильтр");
        JButton buttonClearFilter   = new JButton("Очистить фильтр");
        rightBlock.add(buttonFilter);
        rightBlock.add(buttonClearFilter);
        Object[] a = listP.to_String();
        for (int i = 0; i < a.length; i++) {
            defaultListModel.addElement(a[i]);
        }
        buttonAdd.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    listP.patientData.add(new Pacient(Integer.parseInt(yearOfBirthField.getText()), nameField.getText(), surnameField.getText()));
                    defaultListModel.clear();
                    Object[] a = listP.to_String();
                    for (int i = 0; i < a.length; i++) {
                        defaultListModel.addElement(a[i]);
                    }
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null, "Неправильные данные ");
                }
            }
        });
        buttonDel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (list.getSelectedValue() == null) {
                    JOptionPane.showMessageDialog(null, "Данные не выбраны ");
                } else {
                    listP.patientData.remove(list.getSelectedValue());
                    defaultListModel.clear();
                    Object[] a = listP.to_String();
                    for (int i = 0; i < a.length; i++) {
                        defaultListModel.addElement(a[i]);
                    }
                }
            }
        });

        buttonFilter.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                defaultListModel.clear();
                List<Pacient> tmp = listP.streamFilter();
                for (Pacient i : tmp) {
                    defaultListModel.addElement(i);
                }
            }
        });
        buttonClearFilter.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                defaultListModel.clear();
                Object[] a = listP.to_String();
                for (int i = 0; i < a.length; i++) {
                    defaultListModel.addElement(a[i]);
                }
            }
        });

        buttonRemake.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                if (list.getSelectedValue() != null) {
                    JFrame frame = new JFrame("Изменение параметров");
                    frame.setDefaultLookAndFeelDecorated(true);
                    frame.setVisible(true);
                    JPanel panel = new JPanel();
                    frame.pack();
                    frame.setContentPane(panel);
                    frame.setSize(500, 300);
                    frame.setLocation(200, 200);

                    JTextField nameField        = new JTextField();
                    JTextField surnameField     = new JTextField();
                    JTextField yearOfBirthField = new JTextField();
                    JTextField wasLike          = new JTextField(list.getSelectedValue().toString());

                    JLabel about     = new JLabel("Изменить параметры", SwingConstants.CENTER);
                    JLabel was       = new JLabel("Вот так было:", SwingConstants.CENTER);
                    JLabel name      = new JLabel("Имя:", SwingConstants.CENTER);
                    JLabel surname   = new JLabel("Фамилия:", SwingConstants.CENTER);
                    JLabel yearOfB   = new JLabel("Год рождения:", SwingConstants.CENTER);
                    panel.setLayout(new GridLayout(0, 1));
                    panel.add(about);
                    panel.add(was);
                    panel.add(wasLike);
                    panel.add(name);
                    panel.add(nameField);
                    panel.add(surname);
                    panel.add(surnameField);
                    panel.add(yearOfB);
                    panel.add(yearOfBirthField);
                    JButton button = new JButton("Готово");
                    button.addActionListener(new ActionListener() {
                        @Override
                        public void actionPerformed(ActionEvent actionEvent) {
                            try {

                                listP.patientData.add(listP.patientData.indexOf(list.getSelectedValue()), new Pacient(Integer.parseInt(yearOfBirthField.getText()), nameField.getText(), surnameField.getText()));
                                listP.patientData.remove(list.getSelectedValue());
                                defaultListModel.clear();
                                Object[] a = listP.to_String();
                                for (int i = 0; i < a.length; i++) {
                                    defaultListModel.addElement(a[i]);
                                }
                            } catch (Exception ex) {
                                JOptionPane.showMessageDialog(null, "Неправильные данные ");
                            } finally {
                                frame.dispose();
                            }

                        }
                    });
                    panel.add(button);
                } else {
                    JOptionPane.showMessageDialog(null, "Не выбрано");
                }

            }
        });
    }
}