package leetcode;

public class Sum_of_Two_Integers {
    public static void main(String[] args) {
        System.out.println(getSum(2, 3));
    }
    // https://leetcode.com/problems/sum-of-two-integers/discuss/132479/Simple-explanation-on-how-to-arrive-at-the-solution
    // 위 링크에서 설명을 참조하자

    public static int getSum(int a, int b) {
        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
}
