import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()) {
			int n = input.nextInt();
			int m = input.nextInt();
			double[] x = new double[n];
			double[] y = new double[n];
			double sum = 0;
			for(int i=0; i<n; i++) {
				x[i] = (double) i / n * (n + m);
				y[i] = Math.round(x[i]);
				sum += Math.abs(x[i] - y[i]);
			}
			sum = sum * 10000 / (n + m);
			System.out.printf("%.4f\n", sum);
		}
	}

}
