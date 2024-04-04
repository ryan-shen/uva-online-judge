import java.util.*;

public class Main {

	static int n;
	static int goal;
	static int[][] minTime;
	static int[][] from;
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()) {
			n = input.nextInt();
			goal = input.nextInt();
			int[] time = new int[n+1];
			for(int i=1; i<=n; i++)
				time[i] = input.nextInt();
			input.nextLine();
			ArrayList<Integer>[] lift = new ArrayList[n+1];
			for(int i=1; i<=n; i++) {
				lift[i] = new ArrayList<>();
				String s = input.nextLine();
				String[] str = s.split(" ");
				for(int j=0; j<str.length; j++)
					lift[i].add(Integer.parseInt(str[j]));
			}
			
			minTime = new int[101][101];
			for(int i=0; i<=100; i++) {
				Arrays.fill(minTime[i], Integer.MAX_VALUE);
				minTime[i][i] = 0;
			}
			for(int i=1; i<=n; i++) {
				for(int j=0; j<lift[i].size()-1; j++) {
					for(int k=j+1; k<lift[i].size(); k++) {
						if(time[i] * (lift[i].get(k) - lift[i].get(j)) < minTime[lift[i].get(j)][lift[i].get(k)]) {
							minTime[lift[i].get(j)][lift[i].get(k)] = time[i] * (lift[i].get(k) - lift[i].get(j));
							minTime[lift[i].get(k)][lift[i].get(j)] = time[i] * (lift[i].get(k) - lift[i].get(j));
						}
					}
				}
				
			}
			Dijkstra();
			if(minTime[0][goal] != Integer.MAX_VALUE)
				System.out.println(minTime[0][goal]);
			else
				System.out.println("IMPOSSIBLE");
		}
		
	}
	public static void Dijkstra() {
		boolean[] visited = new boolean[101];
		while(true) {
			int minFloor = 0;
			int minValue = Integer.MAX_VALUE;
			for(int i=0; i<=100; i++) {
				if(!visited[i] && minTime[0][i] < minValue) {
					minFloor = i;
					minValue = minTime[0][i];
				}
			}
			visited[minFloor] = true;
			if(minValue == Integer.MAX_VALUE)
				return;
			for(int i=0; i<=100; i++) {
				if(minTime[minFloor][i] != Integer.MAX_VALUE) {
							minTime[0][i] = Math.min(minTime[0][i], minTime[0][minFloor] + minTime[minFloor][i] + 60);
				}
			}
		}
	}

}
