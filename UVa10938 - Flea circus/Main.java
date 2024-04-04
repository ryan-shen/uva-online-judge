import java.util.*;
public class Main {

	static boolean[][] adj;
	static int[] trace;
	static int[] level;
	static int index;
	static int n;
	static int[] firstAppear;
	static int[] parent;
	static int root;
	static int[][] rmq;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(true) {
			n = input.nextInt();
			if(n == 0) break;
			adj = new boolean[n+1][n+1];
			root = 1;
			for(int i=1; i<n; i++) {
				int v1 = input.nextInt();
				int v2 = input.nextInt();
				adj[v1][v2] = true;
				adj[v2][v1] = true;
				if(root == 1) root = v1;
			}
			trace = new int[n*5];
			level = new int[n*5];
			firstAppear = new int[n+5];
			parent = new int[n+5];
			Arrays.fill(firstAppear, 0);
			Arrays.fill(parent, 0);
			index = 1;
		
			DFS(root, 0);
			initRMQ();
			int query = input.nextInt();
			for(int i=1; i<=query; i++) {
				int v1 = input.nextInt();
				int v2 = input.nextInt();
				LCA(v1, v2);
			}
			
		}
	}
	
	public static void DFS(int ptr, int layer) {
		trace[index] = ptr;
		level[index] = layer;
		if(firstAppear[ptr] == 0) firstAppear[ptr] = index;
		index++;
		for(int i=1; i<=n; i++) {
			if(i == trace[index-2]) continue;
			if(adj[ptr][i]) {
				adj[ptr][i] = false;
				adj[i][ptr] = false;
				if(parent[i] == 0) parent[i] = ptr;
				DFS(i, layer+1);
				trace[index] = ptr;
				level[index] = layer;
				if(firstAppear[ptr] == 0) firstAppear[ptr] = index;
				index++;
			}
		}
	}
	
	public static void LCA(int v1, int v2) {
		int start = Math.min(firstAppear[v1],firstAppear[v2]);
		int end = Math.max(firstAppear[v1],firstAppear[v2]);
		int minLevel = queryRMQ(start, end);
		
		int move = (level[start] - minLevel + level[end] - minLevel) / 2;
		int meetPoint;
		if(level[start] >= level[end]) meetPoint = trace[start];
		else meetPoint = trace[end];
		for(int i=0; i<move; i++) meetPoint = parent[meetPoint];
		if(Math.abs(level[start] - level[end]) % 2 == 0) {
			System.out.println("The fleas meet at " + meetPoint + ".");
		}
		else {
			System.out.println("The fleas jump forever between " + Math.min(meetPoint, parent[meetPoint])
					+ " and " + Math.max(meetPoint, parent[meetPoint]) + ".");
		}
	}
	
	public static void initRMQ() {
		int maxExp = 0;
		while(Math.pow(2, maxExp+1) < index) maxExp++;
		rmq = new int[maxExp+1][index+1];
		for(int i=1; i<index; i++) rmq[0][i] = level[i];
		for(int i=1; i<=maxExp; i++) {
			for(int j=1; j+Math.pow(2, i)-1<index; j++) {
				rmq[i][j] = Math.min(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);
			}
		}
	}
	
	public static int queryRMQ(int start, int end) {
		int maxExp = 0;
		while(Math.pow(2, maxExp+1) < (end - start + 1)) maxExp++;
		return Math.min(rmq[maxExp][start], rmq[maxExp][end-(1<<maxExp)+1]);
	}

}
