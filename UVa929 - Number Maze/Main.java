import java.util.*;

public class Main {

	static Point[][] point;
	static Point now;
	static PriorityQueue<Point> pq;
	static int row;
	static int col;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		while(test-- > 0) {
			row = input.nextInt();
			col = input.nextInt();
			pq = new PriorityQueue<>(new Point());
			point = new Point[row][col];
			for(int i=0; i<row; i++) {
				for(int j=0; j<col; j++) {
					point[i][j] = new Point();
					point[i][j].weight = input.nextInt();
					point[i][j].x = i;
					point[i][j].y = j;
				}
			}
			point[0][0].minWeight = point[0][0].weight;
			pq.add(point[0][0]);
			while(true) {
				if(!pq.isEmpty()) {
					now = pq.poll();
					if(now.x == row-1 && now.y == col-1)
						break;
				}
				else
					break;
				if(now.y+1 < col && point[now.x][now.y+1].minWeight > point[now.x][now.y+1].weight + now.minWeight) {
					point[now.x][now.y+1].minWeight = point[now.x][now.y+1].weight + now.minWeight;
					pq.add(point[now.x][now.y+1]);
				}
				if(now.x+1 < row  && point[now.x+1][now.y].minWeight > point[now.x+1][now.y].weight + now.minWeight) {
					point[now.x+1][now.y].minWeight = point[now.x+1][now.y].weight + now.minWeight;
					pq.add(point[now.x+1][now.y]);
				}
				if(now.y-1 >= 0 && point[now.x][now.y-1].minWeight > point[now.x][now.y-1].weight + now.minWeight) {
					point[now.x][now.y-1].minWeight = point[now.x][now.y-1].weight + now.minWeight;
					pq.add(point[now.x][now.y-1]);
				}
				if(now.x-1 >= 0 && point[now.x-1][now.y].minWeight > point[now.x-1][now.y].weight + now.minWeight) {
					point[now.x-1][now.y].minWeight = point[now.x-1][now.y].weight + now.minWeight;
					pq.add(point[now.x-1][now.y]);
				}
			}
			System.out.println(point[row-1][col-1].minWeight);
		}

	}

}

class Point implements Comparator<Point>{
	int x;
	int y;
	int weight;
	int minWeight = Integer.MAX_VALUE;
	@Override
	public int compare(Point p1, Point p2) {
		return p1.minWeight - p2.minWeight;
	}
	
}
