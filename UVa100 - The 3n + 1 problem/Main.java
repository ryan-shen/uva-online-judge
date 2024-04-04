import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()) {
			int a = input.nextInt();
			int b = input.nextInt();
			int minValue = Math.min(a, b);
			int maxValue = Math.max(a, b);
			int maxCount = 0;
			for(int i=minValue; i<=maxValue; i++) {
				int count = 1;
				int n = i;
				while(n != 1) {
					if(n % 2 == 0) n /= 2;
					else n = n * 3 + 1;
					count++;
				}
				maxCount = Math.max(maxCount, count);
			}
			System.out.println(a + " " + b + " " + maxCount);
		}
		input.close();
	}

}
