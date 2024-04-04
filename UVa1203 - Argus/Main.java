import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()) {
			PriorityQueue<Argus> pq = new PriorityQueue<Argus>(new Argus()); 
			while(true) {
				String s = input.next();
				if(s.equals("#"))
					break;
				else if (s.equals("Register")) {
					int id = input.nextInt();
					int period = input.nextInt();
					pq.add(new Argus(id, period));
				}
			}
			int query = input.nextInt();
			for(int i=0; i<query; i++) {
				Argus now = pq.poll();
				System.out.println(now.id);
				now.period += now.baseTime;
				pq.add(now);
			}
		}
	}

}

class Argus implements Comparator<Argus>{
	int id;
	int period;
	int baseTime;
	Argus(){}
	Argus(int id, int period){
		this.id = id;
		this.period = period;
		baseTime = period;
	}
	@Override
	public int compare(Argus o1, Argus o2) {
		if(o1.period > o2.period)
			return 1;
		else if(o1.period == o2.period && o1.id > o2.id)
			return 1;
		else
			return -1;
	}
	
}
