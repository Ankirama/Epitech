import com.simplecount.controller.Controller;
import com.simplecount.model.Model;
import com.simplecount.view.frame.View;

/**
 * Created by ankirama on 18/11/15.
 */
public class Main {
    public static void main(String[] args) {
        Controller calculator = new Controller(new Model(), new View());
    }
}
