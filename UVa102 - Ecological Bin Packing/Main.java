import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()) {
			long[] brown = new long[3];
			long[] green = new long[3];
			long[] clear = new long[3];
			long[] move = new long[6];
			String s = "";
			
			for(int i=0; i<3; i++) {
				brown[i] = input.nextInt();
				green[i] = input.nextInt();
				clear[i] = input.nextInt();
			}
			
			move[0] = brown[0] + brown[1] + green[0] + green[2] + clear[1] + clear[2];
			move[1] = brown[0] + brown[1] + green[1] + green[2] + clear[0] + clear[2];
			move[2] = brown[0] + brown[2] + green[0] + green[1] + clear[1] + clear[2];
			move[3] = brown[0] + brown[2] + green[1] + green[2] + clear[0] + clear[1];
			move[4] = brown[1] + brown[2] + green[0] + green[1] + clear[0] + clear[2];
			move[5] = brown[1] + brown[2] + green[0] + green[2] + clear[0] + clear[1];
			long minValue = Integer.MAX_VALUE;
			for(int i=0; i<6; i++) {
				minValue = Math.min(minValue, move[i]);
			}
			if(minValue == move[4]) s = "BCG";
			else if(minValue == move[5]) s = "BGC";
			else if(minValue == move[2]) s = "CBG";
			else if(minValue == move[0]) s = "CGB";
			else if(minValue == move[3]) s = "GBC";
			else if(minValue == move[1]) s = "GCB";
			System.out.println(s + " " + minValue);
		}
		input.close();
	}

}

