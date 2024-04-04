import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		ArrayList<Integer>[] list = new ArrayList[25];
		for(int i=0; i<n; i++) {
			list[i] = new ArrayList<>();
			list[i].add(i);
		}
		
		while(true) {
			String motion = input.next();
			if(motion.equals("quit")) break;
			int from = input.nextInt();
			String pos = input.next();
			int to = input.nextInt();
			
			if(from == to) continue;
			int fromBlock = -1;
			int fromIndex = -1;
			int toBlock = -1;
			int toIndex = -1;
			for(int i=0; i<n; i++) {
				for(int j=0; j<list[i].size(); j++) {
					if(list[i].get(j) == from) {
						fromBlock = i;
						fromIndex = j;
					}
					if(list[i].get(j) == to) {
						toBlock = i;
						toIndex = j;
					}
				}
			}
			if(fromBlock == toBlock) continue;
			if(motion.equals("move")) {
				if(pos.equals("onto") || pos.equals("over")) {
					for(int i=0; i<list[fromBlock].size()-fromIndex-1;) {
						int temp = list[fromBlock].get(fromIndex+1);
						list[fromBlock].remove(fromIndex+1);
						list[temp].add(temp);
					}
					if(pos.equals("onto")) {
						for(int i=0; i<list[toBlock].size()-toIndex-1;) {
							int temp = list[toBlock].get(toIndex+1);
							list[toBlock].remove(toIndex+1);
							list[temp].add(temp);
						}
					}
					list[fromBlock].remove(fromIndex);
					list[toBlock].add(from);
				}
			}
			else if(motion.equals("pile")) {
				if(pos.equals("onto")) {
					for(int i=0; i<list[toBlock].size()-toIndex-1;) {
						int temp = list[toBlock].get(toIndex+1);
						list[toBlock].remove(toIndex+1);
						list[temp].add(temp);
					}
					for(int i=0; i<list[fromBlock].size()-fromIndex;) {
						int temp = list[fromBlock].get(fromIndex);
						list[fromBlock].remove(fromIndex);
						list[toBlock].add(temp);
					}
				}
				else if(pos.equals("over")) {
					for(int i=0; i<list[fromBlock].size()-fromIndex;) {
						int temp = list[fromBlock].get(fromIndex);
						list[fromBlock].remove(fromIndex);
						list[toBlock].add(temp);
					}
				}
			}
		}
		for(int i=0; i<n; i++) {
			System.out.print(i + ":");
			for(int j=0; j<list[i].size(); j++) {
				System.out.print(" " + list[i].get(j));
			}
			System.out.println();
		}
		input.close();
	}

}
