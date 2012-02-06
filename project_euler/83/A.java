import java.util.PriorityQueue;
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
    int n = 80;
    int[][] a = new int[n + 5][n + 5], dist = new int[n + 5][n + 5];
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dist[i][j] = Integer.MAX_VALUE / 2;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        a[i][j] = in.nextInt();
      }
    }
    int[][] reach = new int[n + 5][n + 5];
    for (int i = 1; i <= n; ++i) {
      reach[0][i] = reach[n + 1][i] = reach[i][0] = reach[i][n + 1] = 1;
    }
    PriorityQueue<Node> q = new PriorityQueue<Node>();
    q.add(new Node(1, 1, a[1][1]));
    dist[1][1] = a[1][1];
    while (!q.isEmpty()) {
      Node node = q.poll();
      if (reach[node.x][node.y] == 1) {
        continue;
      }
      reach[node.x][node.y] = 1;
      for (int i = 0; i < dx.length; ++i) {
        int nextX = node.x + dx[i], nextY = node.y + dy[i];
        if (reach[nextX][nextY] == 0 &&
            dist[nextX][nextY] > dist[node.x][node.y] + a[nextX][nextY]) {
          dist[nextX][nextY] = dist[node.x][node.y] + a[nextX][nextY];
          q.add(new Node(nextX, nextY, dist[nextX][nextY]));
        }
      }
    }
    System.out.println(dist[n][n]);
  }

  public static int[] dx = {-1, 1, 0, 0};
  public static int[] dy = {0, 0, -1, 1};
}

class Node implements Comparable<Node> {
  public int x;
  public int y;
  public int cost;
  
  public Node (int x, int y, int cost) {
    this.x = x;
    this.y = y;
    this.cost = cost;
  }

  @Override
  public int compareTo(Node other) {
    return cost < other.cost ? -1 : cost == other.cost ? 0 : 1;
  }
}