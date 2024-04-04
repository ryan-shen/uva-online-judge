import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		for(int k=1; k<=test; k++) {
			int length = input.nextInt();
			int time = input.nextInt();
			int n = input.nextInt();
			Ant[] ant = new Ant[n];
			int[] order = new int[n];
			for(int i=0; i<n; i++) {
				int pos = input.nextInt();
				String dir = input.next();
				ant[i] = new Ant(pos, dir);
				order[i] = pos;
			}
			
			Arrays.sort(order);
			for(int i=0; i<n; i++) {
				ant[i].posOrder = Arrays.binarySearch(order, ant[i].position);
			}
			
			Ant[] newAnt = new Ant[n];
			for(int i=0; i<n; i++) {
				newAnt[i] = new Ant();
				if(ant[i].direction.equals("R")) {
					newAnt[i].position = ant[i].position + time;
					newAnt[i].direction = "R";
				}
				else{
					newAnt[i].position = ant[i].position - time;
					newAnt[i].direction = "L";
				}
			}
			
			Arrays.sort(newAnt);
			
			for(int i=0; i<n-1; i++) {
				if(newAnt[i].position == newAnt[i+1].position) {
					newAnt[i].direction = "Turning";
					newAnt[i+1].direction = "Turning";
				}
			}
			
			System.out.println("Case #" + k + ":");
			for(int i=0; i<n; i++) {
				int index = ant[i].posOrder;
				if(newAnt[index].position < 0 || newAnt[index].position > length) System.out.println("Fell off"); 
				else System.out.println(newAnt[index].position + " " + newAnt[index].direction);
			}
			System.out.println();
		}
	}

}

class Ant implements Comparable<Ant>
{
	int posOrder;
	int position;
	String direction;
	
	Ant(){};
	Ant(int position, String direction){
		this.position = position;
		this.direction = direction;
	}
	
	@Override
	public int compareTo(Ant o) {
		if (this.position > o.position) {
			return 1;
		} else if (this.position < o.position) {
			return -1;
		}
		return 0;
	}
}
