import javax.swing.*;
import java.awt.GridLayout;
import java.awt.ScrollPane;
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

        GridLayout iMoreLikeFlexbox = new GridLayout(0, 1);

        leftBlock.setLayout(iMoreLikeFlexbox);
        rightBlock.setLayout(iMoreLikeFlexbox);
        mainPanel.setLayout(new GridLayout(1, 2));

        mainPanel.add(leftBlock);
        mainPanel.add(rightBlock);
        leftBlock.add(nameField);
        leftBlock.add(surnameField);
        leftBlock.add(yearOfBirthField);
        leftBlock.add(buttonAdd);
        leftBlock.add(buttonDel);


        defaultListModel = new DefaultListModel<>();
        list = new JList<>(defaultListModel);
        rightBlock.add(list);
        rightBlock.add(new ScrollPane(1));

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
                listP.patientData.add(new Pacient(Integer.parseInt(yearOfBirthField.getText()), nameField.getText(), surnameField.getText()));
                defaultListModel.clear();
                Object[] a = listP.to_String();
                for (int i = 0; i < a.length; i++) {
                    defaultListModel.addElement(a[i]);
                }
            }
        });
        buttonDel.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                listP.patientData.remove(list.getSelectedValue());
                defaultListModel.clear();
                Object[] a = listP.to_String();
                for (int i = 0; i < a.length; i++) {
                    defaultListModel.addElement(a[i]);
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
    }
}