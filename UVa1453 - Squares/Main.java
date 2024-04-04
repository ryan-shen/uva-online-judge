import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		while(test-- > 0) {
			int n = input.nextInt();
			Point[] point = new Point[n*4];
			for(int i=0; i<n*4; i+=4) {
				int x = input.nextInt();
				int y = input.nextInt();
				int length = input.nextInt();
				point[i] = new Point(x, y);
				point[i+1] = new Point(x + length, y);
				point[i+2] = new Point(x, y + length);
				point[i+3] = new Point(x + length, y + length);
			}
			Arrays.sort(point);
			ArrayList<Point> convex = new ArrayList<>();
			convex.add(point[0]);
			int convexIndex = 1;
			for(int i=1; i<n*4; i++) {
				convex.add(point[i]);
				if(convex.get(convexIndex).x == convex.get(convexIndex-1).x
						&& convex.get(convexIndex).y >= convex.get(convexIndex-1).y) {
					convex.remove(convexIndex);
					continue;
				}
				convexIndex++;
				int area = 0;
				while(area <= 0 && convexIndex >= 3) {
					Point vector1 = new Point(convex.get(convexIndex-2).x - convex.get(convexIndex-3).x
							, convex.get(convexIndex-2).y - convex.get(convexIndex-3).y);
					Point vector2 = new Point(convex.get(convexIndex-1).x - convex.get(convexIndex-2).x
							, convex.get(convexIndex-1).y - convex.get(convexIndex-2).y);
					area = Vector(vector1, vector2);
					if(area <= 0) {
						convex.remove(convexIndex-2);
						convexIndex--;
					}
				}
			}
			for(int i=n*4-1; i>0; i--) {
				convex.add(point[i]);
				if(convex.get(convexIndex).x == convex.get(convexIndex-1).x
						&& convex.get(convexIndex).y <= convex.get(convexIndex-1).y) {
					convex.remove(convexIndex);
					continue;
				}
				convexIndex++;
				int area = 0;
				while(area <= 0 && convexIndex >= 3) {
					Point vector1 = new Point(convex.get(convexIndex-2).x - convex.get(convexIndex-3).x
							, convex.get(convexIndex-2).y - convex.get(convexIndex-3).y);
					Point vector2 = new Point(convex.get(convexIndex-1).x - convex.get(convexIndex-2).x
							, convex.get(convexIndex-1).y - convex.get(convexIndex-2).y);
					area = Vector(vector1, vector2);
					if(area <= 0) {
						convex.remove(convexIndex-2);
						convexIndex--;
					}
				}	
			}
			int maxValue = 0;
			for(int i=0; i<convex.size()-1; i++) {
				for(int j=i+1; j<convex.size(); j++) {
					double difX = Math.pow(convex.get(j).x - convex.get(i).x, 2);
					double difY = Math.pow(convex.get(j).y - convex.get(i).y, 2);
					maxValue = Math.max(maxValue, (int)(difX + difY));
				}
			}
			System.out.println(maxValue);
		}
	}
	
	public static int Vector(Point p1, Point p2) {
		return p1.x * p2.y - p2.x * p1.y;
	}
}

class Point implements Comparable<Point>{
	int x;
	int y;
	Point(int x, int y){
		this.x = x;
		this.y = y;
	}
	public int compareTo(Point o) {
		if(this.x > o.x)
			return 1;
		else if(this.x == o.x && this.y > o.y)
			return 1;
		else
			return -1;
	}
}
