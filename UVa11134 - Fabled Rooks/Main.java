import java.util.*;
public class Main {

	static int[][] arr;
	static Rook[] rook;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true) {
			int n = input.nextInt();
			if(n == 0) break;
			arr = new int[n+1][n+1];
			rook = new Rook[n];
			for(int i=0; i<n; i++) {
				rook[i] = new Rook();
				rook[i].printOrder = i;
				rook[i].x1 = input.nextInt();
				rook[i].y1 = input.nextInt();
				rook[i].x2 = input.nextInt();
				rook[i].y2 = input.nextInt();
			}
			boolean[] hasRook = new boolean[n+1];
			boolean pass = true;
			
			Arrays.fill(hasRook, false);
			for(int i=0; i<n; i++) {
				rook[i].range = rook[i].x2;
			}
			Arrays.sort(rook);
			for(int i=0; i<n; i++) {
				for(int j=rook[i].x1; j<=rook[i].x2; j++) {
					if(!hasRook[j]) {
						rook[i].x = j;
						hasRook[j] = true;
						break;
					}
				}
			}
			for(int i=1; i<=n; i++)
				if(!hasRook[i])
					pass = false;

			Arrays.fill(hasRook, false);
			for(int i=0; i<n; i++) {
				rook[i].range = rook[i].y2;
			}
			Arrays.sort(rook);
			for(int i=0; i<n; i++) {
				for(int j=rook[i].y1; j<=rook[i].y2; j++) {
					if(!hasRook[j]) {
						rook[i].y = j;
						hasRook[j] = true;
						break;
					}
				}
			}
			for(int i=1; i<=n; i++)
				if(!hasRook[i])
					pass = false;
			
			for(int i=0; i<n; i++)
				rook[i].range = rook[i].printOrder;
			Arrays.sort(rook);
			if(pass) {
				for(int i=0; i<n; i++)
					System.out.println(rook[i].x + " " + rook[i].y);
			}
			else
				System.out.println("IMPOSSIBLE ");
		}

	}

}

class Rook implements Comparable<Rook>{
	int x1;
	int x2;
	int y1;
	int y2;
	int x = -1;
	int y = -1;
	int range;
	int printOrder;
	@Override
	public int compareTo(Rook o) {
		return this.range - o.range;
	}
}
