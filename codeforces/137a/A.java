import java.util.Scanner;

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
    Scanner in = new Scanner(System.in);
    String s = in.next();
    int res = 0, aux = 1;
    char last = s.charAt(0);
    for (int i = 1; i < s.length(); ++i) {
      char c = s.charAt(i);
      if (c != last || aux == 5) {
        ++res;
        aux = 1;
      } else {
        ++aux;
      }
      last = c;
    }
    if (aux > 0) {
      ++res;
    }
    System.out.println(res);
    
  }
}
