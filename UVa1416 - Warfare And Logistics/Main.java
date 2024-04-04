import java.util.*;
public class Main {

	static int[][] adj;
	static int[][] shortAdj;
	static int[][] floydAdj;
	static int[][] dijkstraAdj;
	static int[][] secondRoad;
	static int enemy;
	static int cost;
	static int INF = 100000001;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()) {
			enemy = input.nextInt();
			int road = input.nextInt();
			cost = input.nextInt();
			adj = new int[enemy+1][enemy+1];
			shortAdj = new int[enemy+1][enemy+1];
			floydAdj = new int[enemy+1][enemy+1];
			dijkstraAdj = new int[enemy+1][enemy+1];
			secondRoad = new int[enemy+1][enemy+1];
			for(int i=1; i<=enemy; i++) {
				Arrays.fill(adj[i], INF);
				adj[i][i] = 0;
			}
			for(int i=1; i<=road; i++) {
				int v1 = input.nextInt();
				int v2 = input.nextInt();
				int length = input.nextInt();
				if(adj[v1][v2] == INF) {
					adj[v1][v2] = length;
					adj[v2][v1] = length;
				}
				else if(adj[v1][v2] != INF && secondRoad[v1][v2] == 0){
					int minLength = Math.min(adj[v1][v2], length);
					int maxLength = Math.max(adj[v1][v2], length);
					adj[v1][v2] = minLength;
					adj[v2][v1] = minLength;
					secondRoad[v1][v2] = maxLength;
					secondRoad[v2][v1] = maxLength;
				}
				else {
					int minLength;
					int midLength;
					if(length < adj[v1][v2]) {
						minLength = length;
						midLength = adj[v1][v2];
					}
					else if(length < secondRoad[v1][v2]) {
						minLength = adj[v1][v2];
						midLength = length;
					}
					else {
						minLength = adj[v1][v2];
						midLength = secondRoad[v1][v2];
					}
					adj[v1][v2] = minLength;
					adj[v2][v1] = minLength;
					secondRoad[v1][v2] = midLength;
					secondRoad[v2][v1] = midLength;
				}
			}
			
			for(int i=1; i<=enemy; i++)
				System.arraycopy(adj[i], 1, floydAdj[i], 1, enemy);
			System.out.print(Floyd() + " ");
		
			for(int k=1; k<=enemy; k++)
				System.arraycopy(floydAdj[k], 1, shortAdj[k], 1, enemy);
			
			long maxValue = 0;
			for(int i=1; i<enemy; i++) {
				for(int j=i+1; j<=enemy; j++) {
					for(int k=1; k<=enemy; k++)
						System.arraycopy(adj[k], 1, dijkstraAdj[k], 1, enemy);
					if(secondRoad[i][j] == 0) {
						dijkstraAdj[i][j] = INF;
						dijkstraAdj[j][i] = INF;
					}
					else {
						dijkstraAdj[i][j] = secondRoad[i][j];
						dijkstraAdj[j][i] = secondRoad[i][j];
					}
					if(Dijkstra(i, j) == shortAdj[i][j])
						continue;
					
					for(int k=1; k<=enemy; k++)
						System.arraycopy(dijkstraAdj[k], 1, floydAdj[k], 1, enemy);
					maxValue = Math.max(maxValue, Floyd());
				}
			}
			System.out.println(maxValue);
		}
		

	}
	
	public static long Floyd() {
		for(int k=1; k<=enemy; k++) {
			for(int i=1; i<=enemy; i++) {
				for(int j=1; j<=enemy; j++) {
					floydAdj[i][j] = Math.min(floydAdj[i][j], floydAdj[i][k] + floydAdj[k][j]);
				}
			}
		}
		int total = 0;
		for(int i=1; i<=enemy; i++) {
			for(int j=1; j<=enemy; j++) {
				if(floydAdj[i][j] != INF) 
					total += floydAdj[i][j];
				else
					total += cost;
			}
		}
		return total;
	}
	
	public static int Dijkstra(int start, int end) {
		boolean[] visited = new boolean[enemy+1];
		for(int i=1; i<enemy; i++) {
			int minPoint = 0;
			int minDist = Integer.MAX_VALUE;
			for(int j=1; j<=enemy; j++) {
				if(dijkstraAdj[start][j] < minDist && !visited[j] && start != j) {
					minPoint = j;
					minDist = dijkstraAdj[start][j];
				}
			}
			visited[minPoint] = true;
			for(int j=1; j<=enemy; j++)
				dijkstraAdj[start][j] = Math.min(dijkstraAdj[start][j], dijkstraAdj[start][minPoint] + dijkstraAdj[minPoint][j]);
		}
		return dijkstraAdj[start][end];
	}
}
