import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()) {
			int n1 = input.nextInt();
			int n2 = input.nextInt();
			int n = Math.max(n1, n2);
			int m = Math.min(n1, n2);
			int stateCount = 1<<m;
			long[][] method = new long[2][stateCount];
			int cur = 0;
			int pre = 1;
			method[0][stateCount-1] = 1; 
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					cur ^= 1;
					pre ^= 1;
					Arrays.fill(method[cur], 0);
					for(int k=0; k<stateCount; k++) {
						int highBit = k>>(m-1);
						int lowBit = k & 1;
						if(highBit == 1) {//no
							method[cur][(k<<1)^(1<<m)] += method[pre][k];
						}
						if(highBit == 0 && i > 0) {//up
							method[cur][(k<<1)|1] += method[pre][k];
						}
						if(highBit == 1 && lowBit == 0 && j > 0) {//left
							method[cur][(k<<1)^(1<<m)|3] += method[pre][k];
						}
					}
				}
			}
			System.out.println(method[cur][stateCount-1]);
		}
	}
}
