import javax.swing.table.AbstractTableModel;
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
//pierwsze okienko
public class ClassInterface extends JFrame {
    private Class classInstance;
    private JPanel contentPane;
    private JTable classTable;

    public ClassInterface(Class classInstance) {
        this.classInstance = classInstance;

        setTitle("Menu");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        contentPane = new JPanel(new BorderLayout());
        setContentPane(contentPane);

        ClassTableModel classTableModel = new ClassTableModel(classInstance);
        classTable = new JTable(classTableModel);

        JScrollPane scrollPane = new JScrollPane(classTable);
        contentPane.add(scrollPane, BorderLayout.CENTER);

        // Add MouseListener to the JTable
        classTable.getSelectionModel().addListSelectionListener(e -> {
            if (e.getValueIsAdjusting()) {
                return;
            }
            int selectedRow = classTable.getSelectedRow();
            if (selectedRow != -1) {
                StudentInterface studentInterface = new StudentInterface(classInstance.getStudentList());
                studentInterface.setVisible(true);
            }
        });

        classTable.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount() == 2) {
                    int selectedRow = classTable.getSelectedRow();
                    if (selectedRow != -1) {
                        StudentInterface studentInterface = new StudentInterface(classInstance.getStudentList());
                        studentInterface.setVisible(true);
                    }
                }
            }
        });


        // Set the size of the JFrame and make it visible
        setSize(800, 800);
        setVisible(true);
    }
}

class ClassTableModel extends AbstractTableModel {
    private static final String[] COLUMN_NAMES = {"Group Name", "Student List", "Max Students"};
    private static final int GROUP_NAME_COL = 0;
    private static final int STUDENT_LIST_COL = 1;
    private static final int MAX_STUDENTS_COL = 2;


    private Class classInstance;

    public ClassTableModel(Class classInstance) {
        this.classInstance = classInstance;
    }

    @Override
    public int getRowCount() {
        return 1;
    }

    @Override
    public int getColumnCount() {
        return COLUMN_NAMES.length;
    }

    @Override
    public String getColumnName(int columnIndex) {
        return COLUMN_NAMES[columnIndex];
    }

    @Override
    public java.lang.Class<?> getColumnClass(int columnIndex) {
        if (columnIndex == 0) {
            return String.class;
        } else if (columnIndex == 1) {
            return String.class;
        } else {
            return Integer.class;
        }
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        if (columnIndex == GROUP_NAME_COL) {
            return classInstance.getGroupName();
        } else if (columnIndex == STUDENT_LIST_COL) {
            return classInstance.getStudentList().size();
        } else if (columnIndex == MAX_STUDENTS_COL) {
            return classInstance.getMaxStudents();
        } else {
            return null;
        }
    }

}