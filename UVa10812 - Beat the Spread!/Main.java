import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int test = input.nextInt();
		while(test-- > 0) {
			long sum = input.nextLong();
			long dif = input.nextLong();
			if(sum >= dif && (sum + dif) % 2 == 0) { 
				long x = (sum + dif) / 2;
				long y = (sum - dif) / 2;
				System.out.println(x + " " + y);
			}
			else 
				System.out.println("impossible");
		}
	}
}
