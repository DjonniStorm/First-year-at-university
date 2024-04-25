import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class laba42 {
    public ArrayList<Pacient> patientData = new ArrayList();
    public Object[] to_String() {
        return patientData.toArray();
    }
    public List<Pacient> streamFilter() {
        return patientData.stream().filter(i -> i.getYearOfBirth() < 1980).collect(Collectors.toList());
    }
}
