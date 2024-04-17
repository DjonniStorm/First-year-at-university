import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Lab4 {
    private final char left  = '(';
    private final char right = ')';

    public Lab4(String filename) {
        if (filename == null) {
            return;
        }
        StringBuilder text = readFile(filename);
        doTask(text);
    }
    private StringBuilder readFile(String filename) {
        StringBuilder sb = new StringBuilder();
        try(BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                sb.append(line);
            }
        } catch (IOException e){
            e.printStackTrace();
        }
        if (sb.isEmpty()) return null;
        return sb;
    }
    private void doTask(StringBuilder sb) {
        int countLeft  = 0;
        int countRight = 0;
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        for (int i = 0;  i < sb.length(); i++) {
            if (sb.charAt(i) == left)  countLeft++;
            if (sb.charAt(i) == right) countRight++;
            if (countRight > countLeft) {
                if (!a.contains(countRight - countLeft)) {
                    a.add(countRight - countLeft);
                    b.add(i);
                }
            }
        }
        if (!a.isEmpty()) {
            for (int i = 0; i < a.size(); i++) {
                printAll(b.get(i));
            }
        }
        if (countLeft > countRight) {printAll(-1); return;}
        if (a.isEmpty() && countLeft == countRight) printAll(0);

    }
    private void printAll(int index) {
        System.out.print("\n" + index);
    }
}
