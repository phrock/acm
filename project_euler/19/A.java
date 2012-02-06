import java.util.Calendar;
import java.util.GregorianCalendar;

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

public class A {
  public static void main(String[] args) {
    GregorianCalendar g = new GregorianCalendar(1901, 0, 1);
    int res = 0;
    while (g.get(Calendar.YEAR) != 2001) {
      if (g.get(Calendar.DAY_OF_WEEK) == Calendar.SUNDAY &&
          g.get(Calendar.DAY_OF_MONTH) == 1) {
        ++res;
      }
      g.add(Calendar.DAY_OF_WEEK, 1);
    }
    System.out.println(res);
  }
}