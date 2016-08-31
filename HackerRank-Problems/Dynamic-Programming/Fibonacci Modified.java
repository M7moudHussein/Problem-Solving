import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t1, t2, n;
		t1 = sc.nextInt();
		t2 = sc.nextInt();
		n = sc.nextInt();
		BigInteger f1 = new BigInteger(Integer.valueOf(t1).toString());
		BigInteger f2 = new BigInteger(Integer.valueOf(t2).toString());
		BigInteger f3 = new BigInteger("0");
		for (int i = 3; i <= n; i++) {
			f3 = f1.add(f2.multiply(f2));
			f1 = f2;
			f2 = f3;
		}
		System.out.println(f3);
		sc.close();
	}
};
