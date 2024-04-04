import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while (input.hasNext()) {
			int city = input.nextInt();
			int road = input.nextInt();
			int[] price = new int[city];
			ArrayList<Node>[] arr = new ArrayList[city];

			for (int i = 0; i < city; i++) {
				price[i] = input.nextInt();
				arr[i] = new ArrayList<>();
			}
			for (int i = 0; i < road; i++) {
				int v1 = input.nextInt();
				int v2 = input.nextInt();
				int weight = input.nextInt();
				arr[v1].add(new Node(v2, weight));
				arr[v2].add(new Node(v1, weight));
			}
			int query = input.nextInt();
			for (int k = 0; k < query; k++) {
				PriorityQueue<Node> pq = new PriorityQueue<Node>(new Node());
				int capacity = input.nextInt();
				int v1 = input.nextInt();
				int v2 = input.nextInt();
				int[][] minCost = new int[city][capacity];
				for (int i = 0; i < city; i++)
					Arrays.fill(minCost[i], Integer.MAX_VALUE);
				boolean pass = false;
				Node now;
				pq.add(new Node(v1, 0, 0));
				minCost[v1][0] = 0;
				while (true) {
					now = pq.poll();
					if (now == null)
						break;
					else if (now.curNode == v2) {
						pass = true;
						break;
					}
					for(int i = 0; i < arr[now.curNode].size(); i++){
						if (arr[now.curNode].get(i).weight <= capacity) {
							if(now.curOil >= arr[now.curNode].get(i).weight && minCost[arr[now.curNode].get(i).curNode][now.curOil - arr[now.curNode].get(i).weight] > now.cost 
									&& price[arr[now.curNode].get(i).curNode] < price[now.curNode]) {
								pq.add(new Node(arr[now.curNode].get(i).curNode, now.curOil - arr[now.curNode].get(i).weight, now.cost));
								minCost[arr[now.curNode].get(i).curNode][now.curOil - arr[now.curNode].get(i).weight] = now.cost;
								continue;
							}
							for (int j = 0; j <= capacity - arr[now.curNode].get(i).weight; j++) {
								if (now.curOil >= j + arr[now.curNode].get(i).weight && minCost[arr[now.curNode].get(i).curNode][j] > now.cost) {
									pq.add(new Node(arr[now.curNode].get(i).curNode, j, now.cost));
									minCost[arr[now.curNode].get(i).curNode][j] = now.cost;
								} 
								else if (now.curOil < j + arr[now.curNode].get(i).weight && minCost[arr[now.curNode].get(i).curNode][j] >= now.cost
										+ price[now.curNode] * (j + arr[now.curNode].get(i).weight - now.curOil)) {
									pq.add(new Node(arr[now.curNode].get(i).curNode, j,
											now.cost + price[now.curNode] * (j + arr[now.curNode].get(i).weight - now.curOil)));
									minCost[arr[now.curNode].get(i).curNode][j] = now.cost
											+ price[now.curNode] * (j + arr[now.curNode].get(i).weight - now.curOil);
								}
							}
						}
					}
				}
				if (pass)
					System.out.println(now.cost);
				else
					System.out.println("impossible");
			}
		}
	}

}

class Node implements Comparator<Node> {
	int curNode;
	int curOil;
	int cost;
	int weight;
	Node() {
	}
	Node(int curNode, int weight){
		this.curNode = curNode;
		this.weight = weight;
	}
	Node(int curNode, int curOil, int cost) {
		this.curNode = curNode;
		this.curOil = curOil;
		this.cost = cost;
	}

	@Override
	public int compare(Node o1, Node o2) {
		return o1.cost - o2.cost;
	}
}
